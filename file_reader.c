//
// Created by bigel on 18.12.2020.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <bits/types/FILE.h>
#include <stdint.h>
#include "file_reader.h"
#include <errno.h>
#include "tested_declarations.h"
#include "rdebug.h"
//#include <assert.h>
//#include "tested_declarations.h"
//#include "rdebug.h"


struct disk_t *gdisk;
struct volume_t *gvolume;
int ind = 0;



struct disk_t* disk_open_from_file(const char* volume_file_name){
    if(!volume_file_name){
        errno = EFAULT;
        return NULL;
    }
    struct disk_t *disc = (struct disk_t*)calloc(1,sizeof(struct disk_t));
    if(!disc) {
        errno = ENOMEM;
        return NULL;
    }
    disc->file = fopen(volume_file_name, "rb+");
    if(!disc->file) {
        free(disc);
        errno = ENOENT;
        return NULL;
    }

    return disc;
}

int disk_read(struct disk_t* pdisk, int32_t first_sector, void* buffer, int32_t sectors_to_read)
{
    if(!pdisk || !buffer || !sectors_to_read){
        errno = EFAULT;
        return -1;
    }

    if(fseek(pdisk->file, first_sector * BYTES_PER_SECTOR , SEEK_SET) != 0) {
        errno = ERANGE;
        return -1;
    }

    size_t num_of_blocks = fread(buffer, BYTES_PER_SECTOR , sectors_to_read, pdisk->file);
    return num_of_blocks;
}

int disk_close(struct disk_t* pdisk)
{
    if(!pdisk){
        errno = EFAULT;
        return -1;
    }
    fclose(pdisk->file);
    free(pdisk);
    return 0;
}

struct volume_t* fat_open(struct disk_t* pdisk, uint32_t first_sector){
    if(!pdisk || !pdisk->file){
        errno = EFAULT;
        return NULL;
    }

    struct volume_t *volume = (struct volume_t*)calloc(1,sizeof(struct volume_t));
    if(!volume) {
        errno = ENOMEM;
        return NULL;
    }

    //odczyt bootsectora
    //int num_of_blocks = fread(volume, BYTES_PER_SECTOR, 1, pdisk->file);
    int num_of_blocks = disk_read(pdisk, first_sector, volume, 1);
    if(num_of_blocks!=1){
        free(volume);
        errno = ENOMEM;
        return NULL;
    }

    //volume->disk = *pdisk;
    gdisk = pdisk;


    if(volume->bytes_per_sector != BYTES_PER_SECTOR
    || volume->reserved_sectors < 1
    || volume->fat_count < 1
    || volume->sectors_per_fat < 1
    || (volume->logical_sectors16 == 0 && volume->logical_sectors32 == 0)
    //|| (volume->root_dir_capacity * SIZE_OF_DIR_ENTRY) % volume->bytes_per_sector == 0
    //|| volume->root_dir_capacity
    || volume->sectors_per_fat < 16 || volume->sectors_per_fat > 256){
        free(volume);
        errno = EINVAL;
        return NULL;
    }

    int sector_size = BYTES_PER_SECTOR * volume->sectors_per_fat;

    //FAT 1
    uint16_t  *volume_FAT1 = malloc(sector_size);
    if(!volume_FAT1) {
        free(volume);
        errno = ENOMEM;
        return NULL;
    }

    num_of_blocks = disk_read(pdisk, first_sector + volume->reserved_sectors, volume_FAT1, volume->sectors_per_fat);
    if(num_of_blocks!=volume->sectors_per_fat){
        free(volume_FAT1);
        free(volume);
        errno = ENOMEM;
        return NULL;
    }

    //FAT = volume_FAT1;

    //FAT 2
    uint16_t  *volume_FAT2 = malloc(sector_size);
    if(!volume_FAT2) {
        free(volume_FAT1);
        free(volume);
        errno = ENOMEM;
        return NULL;
    }

    num_of_blocks = disk_read(pdisk, first_sector + volume->reserved_sectors + volume->sectors_per_fat, volume_FAT2, volume->sectors_per_fat);
    if(num_of_blocks!=volume->sectors_per_fat){
        free(volume_FAT1);
        free(volume_FAT2);
        free(volume);
        errno = EINVAL;
        return NULL;
    }


    int c = memcmp(volume_FAT1,volume_FAT2, sector_size);
    if(c != 0){
        free(volume_FAT1);
        free(volume_FAT2);
        free(volume);
        errno = EINVAL;
        return NULL;
    }

    free(volume_FAT1);
    free(volume_FAT2);

    gvolume = volume;
    return volume;
}


int fat_close(struct volume_t* pvolume){
    if(!pvolume){
        errno = EFAULT;
        return -1;
    }
    free(pvolume);
    return 0;
}

int file_name_extract(struct dir_t *dir, struct dir_entry_t *entry, int indeks){
    if(indeks >= gvolume->root_dir_capacity || dir[indeks].full_name[0] == 0) return 1;

    if (dir[indeks].full_name[0] == FAT_DELETED_MAGIC || (dir[indeks].attributes & FAT_VOLUME_LABEL) != 0 || dir[indeks].full_name[0] == 0) return 1;
    for(int i =0; i < 12; i++) entry[0].name[i] = '\0';
    for(int i =0, j=0; i < 11; i++){
        char c = dir[indeks].full_name[i];
        if(i==8 && dir[indeks].full_name[i]!=' ' && dir[indeks].full_name[i]!=0){
            entry[0].name[j] = '.';
            j++;
        }
        if(c!=20 && c!=' '){
            entry[0].name[j] = c;
            j++;
        }
    }
    return 0;
}


struct file_t* file_open(struct volume_t* pvolume, const char* file_name){
    if(!pvolume || !file_name){
        errno = EFAULT;
        return NULL;
    }

    struct dir_t *file_entry = (struct dir_t*)malloc(sizeof(struct dir_t));
    if(!file_entry) {
        errno = ENOMEM;
        return NULL;
    }

    struct dir_t *dir = dir_open(pvolume,"\\");

    int is_in_dir = 0;
    struct dir_entry_t entry;
    for (int i = 0; i < pvolume->root_dir_capacity; i++){
        if(file_name_extract(dir, &entry,i)) continue;
        if(strcmp(entry.name, file_name) == 0){
            if((dir[i].attributes & FAT_DIRECTORY) != 0){
                free(dir);
                free(file_entry);
                return NULL;
            }
            *file_entry = dir[i];
            is_in_dir = 1;
            break;
        }
    }
    if(is_in_dir==0){
        free(dir);
        free(file_entry);
        return NULL;
    }

    struct file_t *file = (struct file_t*)malloc(sizeof(struct file_t));
    if(!file) {
        free(dir);
        free(file_entry);
        errno = ENOMEM;
        return NULL;
    }

    memcpy(file->full_name,file_entry->full_name,11);
    file->attributes = file_entry->attributes;
    file->high_cluster_index = file_entry->high_cluster_index;
    file->low_cluster_index = file_entry->low_cluster_index;
    file->size = file_entry->size;
    file->pvolume = pvolume;
    file->whence = SEEK_SET;

    uint32_t start_cluster = pvolume->reserved_sectors + pvolume->fat_count*pvolume->sectors_per_fat + (pvolume->root_dir_capacity*32)/pvolume->bytes_per_sector;
    file->start_cluster = start_cluster;

    free(file_entry);
    free(dir);
    return file;
}



int file_close(struct file_t* stream){
    if(!stream){
        errno = EFAULT;
        return -1;
    }
    free(stream);
    return 0;
}

size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream){
    if(!ptr  || !stream){
        errno = EFAULT;
        return -1;
    }

    size_t count =0;

    //if(stream->size>=nmemb*size) count = nmemb;
    //else count = stream->size;

    count = size * nmemb;
    if (count > stream->size - stream->whence) count = stream->size - stream->whence;

    uint32_t volume_start = 0;
    uint32_t fat1_position = volume_start + stream->pvolume->reserved_sectors;

    uint16_t *buffer = (uint16_t *)calloc(stream->pvolume->bytes_per_sector, stream->pvolume->sectors_per_fat);
    int num_of_blocks = disk_read(gdisk, fat1_position, buffer, stream->pvolume->sectors_per_fat);
    if(num_of_blocks!= stream->pvolume->sectors_per_fat){
        free(buffer);
        errno = ENOMEM;
        return 0;
    }


    int current_cluster = stream->low_cluster_index;
    uint32_t start_cluster = stream->start_cluster;

    int num_of_clusters = stream->size / stream->pvolume->bytes_per_sector / stream->pvolume->sectors_per_cluster;
    if(stream->size % stream->pvolume->bytes_per_sector != 0) num_of_clusters++;

    int size_of_clusters = num_of_clusters * stream->pvolume->sectors_per_cluster * stream->pvolume->bytes_per_sector;
    int content_offset = 0;

    char *file_content = (char *)calloc(size_of_clusters+10, 1);

    for( int i =0;;i++) {
        if(i>=num_of_clusters) break;

        uint32_t cluster_position = start_cluster + (current_cluster-2) * stream->pvolume->sectors_per_cluster;

        int blocks_read = disk_read(gdisk, cluster_position, file_content+content_offset, stream->pvolume->sectors_per_cluster);
        if(blocks_read <= 0){
            free(file_content);
            free(buffer);
            return -1;
        }

        current_cluster=buffer[current_cluster];
        content_offset += stream->pvolume->sectors_per_cluster * stream->pvolume->bytes_per_sector;
    }



    //if(stream->size>=nmemb)
    //else memcpy(ptr, file_content + stream->whence, stream->size);

    memcpy(ptr, file_content + stream->whence, count);

    file_seek(stream,count,SEEK_CUR);

    //printf("%d",stream->size);

    //printf("%llu\n",strlen(ptr));

    free(file_content);
    free(buffer);
    if(size!=1 && count<size * nmemb) return 0;
    return size == 1 ? count : 1;
}

int32_t file_seek(struct file_t* stream, int32_t offset, int whence){
    if(!stream){
        errno = EFAULT;
        return -1;
    }

    if(whence == SEEK_SET) stream->whence = offset;
    if(whence == SEEK_CUR) stream->whence += offset;
    if(whence == SEEK_END) stream->whence = stream->size + offset;

    return offset;
}

struct dir_t* dir_open(struct volume_t* pvolume, const char* dir_path){
    if(!pvolume || !dir_path || (dir_path[0]!='\\')){
        errno = EFAULT;
        return NULL;
    }

    int32_t root_directory_position = 0 + pvolume->reserved_sectors + pvolume->fat_count * pvolume->sectors_per_fat;
    int32_t root_directory_size = (pvolume->root_dir_capacity * sizeof(struct dir_entry_t)) / pvolume->bytes_per_sector;
    size_t bytes_per_root_directory_ = root_directory_size * pvolume->bytes_per_sector;

    struct dir_t *dir = (struct dir_t *)malloc(bytes_per_root_directory_);
    if(dir == NULL){
        errno = ENOMEM;
        return NULL;
    }
    int num_of_blocks = disk_read(gdisk, root_directory_position, dir, root_directory_size);
    if(num_of_blocks != root_directory_size){
        free(dir);
        errno = ENOMEM;
        return NULL;
    }


    return dir;
}



int dir_read(struct dir_t* pdir, struct dir_entry_t* pentry){
    if(!pdir || !pentry){
        errno = EFAULT;
        return -1;
    }

    if(ind >= gvolume->root_dir_capacity || pdir[ind].full_name[0] == 0) return 1;

    while ((pdir[ind].full_name[0] == FAT_DELETED_MAGIC || (pdir[ind].attributes & FAT_VOLUME_LABEL) != 0 || pdir[ind].full_name[0] == 0)) {
        ind++;
    }

    //zerowanieS
    for(int i =0; i < 12; i++) pentry[0].name[i] = '\0';

    //kopiowanie nazwy pliku
    for(int i =0, j=0; i < 11; i++){
        char c = pdir[ind].full_name[i];
        if(i==8 && pdir[ind].full_name[i]!=' ' && pdir[ind].full_name[i]!=0){
            pentry[0].name[j] = '.';
            j++;
        }
        if(c!=20 && c!=' '){
            pentry[0].name[j] = c;
            j++;
        }
    }

    /*
     if(indeks >= gvolume->root_dir_capacity || dir[indeks].full_name[0] == 0) return 1;

    if (dir[indeks].full_name[0] == FAT_DELETED_MAGIC || (dir[indeks].attributes & FAT_VOLUME_LABEL) != 0 || dir[indeks].full_name[0] == 0) return 1;
    for(int i =0; i < 12; i++) entry[0].name[i] = '\0';
    for(int i =0, j=0; i < 11; i++){
        char c = dir[indeks].full_name[i];
        if(i==8 && dir[indeks].full_name[i]!=' ' && dir[indeks].full_name[i]!=0){
            entry[0].name[j] = '.';
            j++;
        }
        if(c!=20 && c!=' '){
            entry[0].name[j] = c;
            j++;
        }
    }
    return 0;
     */

    ind++;

    return 0;
}

int dir_close(struct dir_t* pdir){
    if(!pdir){
        errno = EFAULT;
        return -1;
    }
    free(pdir);
    return 0;
}

