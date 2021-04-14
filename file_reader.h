
#ifndef UNTITLED10_FILE_READER_H
#define UNTITLED10_FILE_READER_H

#ifndef UNTITLED1_FILE_READER_H
#define UNTITLED1_FILE_READER_H

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <bits/types/FILE.h>
#include <stdbool.h>


#define BYTES_PER_SECTOR            512
#define SIZE_OF_DIR_ENTRY		    32
#define FAT_DELETED_MAGIC ((char)0xE5)

typedef uint16_t fat_date_t;
typedef uint16_t fat_time_t;

struct disk_t{
    FILE *file;
}__attribute__((packed));

struct disk_t* disk_open_from_file(const char* volume_file_name);

int disk_read(struct disk_t* pdisk, int32_t first_sector, void* buffer, int32_t sectors_to_read);
int disk_close(struct disk_t* pdisk);

struct volume_t{
    uint8_t  jump_code[3];
    char     oem_name[8];
    uint16_t bytes_per_sector;          // 0x00B  Liczba bajtów w sektorze
    uint8_t  sectors_per_cluster;       // 0x00D  Liczba sektorów w klastrze
    uint16_t reserved_sectors;          // 0x00E  Liczba zarezerwowanych sektorów
    uint8_t  fat_count;                 // 0x010  Liczba tabel alokacji plików (FAT)
    uint16_t root_dir_capacity;         // 0x011  Liczba wpisów w katalogu głównym woluminu (root directory)
    uint16_t logical_sectors16;         // 0x013  Całkowita liczba sektorów w woluminie
    uint8_t  media_type;                // 0x015  Typ nośnika
    uint16_t sectors_per_fat;           // 0x016  Liczba sektorów na jedną tablicę alokacji
    uint16_t chs_sectors_per_track;     // 0x018  liczba sektorów na ścieżce
    uint16_t chs_tracks_per_cylinder;   // 0x01A  Liczba ścieżek w cylindrze
    uint32_t hidden_sectors;            // 0x01C  Liczba ukrytych sektorów –określa przesunięcie woluminu FAT
    uint32_t logical_sectors32;         // 0x020  Całkowita liczba sektorów w woluminie
    uint8_t  media_id;
    uint8_t  chs_head;
    uint8_t  ext_bpb_signature;
    uint32_t serial_number;
    char     volume_label[11];
    char     fsid[8];
    uint8_t  boot_code[448];
    uint16_t magic;
    //struct disk_t disk;
}__attribute__((packed));

struct volume_t* fat_open(struct disk_t* pdisk, uint32_t first_sector);

int fat_close(struct volume_t* pvolume);

enum fat_attribute_t {
    FAT_DIRECTORY = 0x10,
    FAT_VOLUME_LABEL = 0x08,
} __attribute__(( packed ));


struct file_t{
    char full_name[8 + 3];
    enum fat_attribute_t attributes;
    fat_date_t high_cluster_index;
    uint16_t low_cluster_index; //klaster w ktorym jest index ktorym sie rozpoczyna plik
    uint32_t size;
    uint32_t whence;
    uint32_t start_cluster;
    struct volume_t *pvolume;
}__attribute__((packed));

struct file_t* file_open(struct volume_t* pvolume, const char* file_name);
int file_close(struct file_t* stream);
size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream);
int32_t file_seek(struct file_t* stream, int32_t offset, int whence);



struct dir_t{
    char full_name[8 + 3];
    enum fat_attribute_t attributes;
    uint8_t reserved0;
    uint8_t cration_time_ms;
    fat_time_t creation_time;
    fat_date_t creation_date;
    fat_time_t last_access_time;
    fat_date_t high_cluster_index;
    fat_time_t last_modification_time;
    fat_date_t last_modification_date;
    uint16_t low_cluster_index; //klaster w ktorym jest index ktorym sie rozpoczyna plik
    uint32_t size;
    //struct volume_t *pvolume;
}__attribute__((packed));



struct dir_entry_t{
    char name[8 + 3 + 1]; //8 nazwa pliku 3 rozszerzenie 1 kropka
    int is_archived;
    int is_readonly;
    int is_system;
    int is_hidden;
    int is_directory;
    uint32_t size;
}__attribute__((packed));

struct dir_t* dir_open(struct volume_t* pvolume, const char* dir_path);
int dir_read(struct dir_t* pdir, struct dir_entry_t* pentry);
int dir_close(struct dir_t* pdir);



#endif //UNTITLED1_FILE_READER_H

#endif //UNTITLED10_FILE_READER_H
