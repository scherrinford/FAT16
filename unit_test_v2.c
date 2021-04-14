/*
 * Unit Test Bootstrap
 * Autor: Tomasz Jaworski, 2018-2020
 *
 * Test dla zadania Projekt: czytnik dysku, woluminu, katalogu głównego i plików (3,0)
 * Autor testowanej odpowiedzi: Karolina Woźnicka
 * Test wygenerowano automatycznie o 2020-12-25 16:37:53.214702
 *
 * Debug: 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <signal.h>
#include <setjmp.h>
#include <assert.h>

#if !defined(__clang__) && !defined(__GNUC__)
// Zakomentuj poniższy błąd, jeżeli chcesz przetestować testy na swoim kompilatorze C.
#error System testow jednostkowych jest przeznaczony dla kompilatorów GCC/Clang.
#endif

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
// Zakomentuj poniższy błąd, jeżeli chcesz przetestować testy na platformie Windows.
#error System testow jednostkowych NIE jest przeznaczony dla testów uruchamianych na platformach Windows.
#endif

#define _RLDEBUG_API_
#include "unit_helper_v2.h"
#include "rdebug.h"

#include "tested_declarations.h"
#include "rdebug.h"

//
// Elementy globalne dla całego testu
//




//
//  Test 1: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST1(void)
{
    // informacje o teście
    test_start(1, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file("IRON.TX");
            test_error(disk == NULL, "Funkcja disk_open_from_file() powinna zwrócić NULL przy próbie otwarcia nieistniejącego pliku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 2: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST2(void)
{
    // informacje o teście
    test_start(2, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file(NULL);
            test_error(disk == NULL, "Funkcja disk_open_from_file() powinna zwrócić NULL przy próbie otwarcia nieistniejącego pliku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 3: Sprawdzanie poprawności działania funkcji disk_close
//
void UTEST3(void)
{
    // informacje o teście
    test_start(3, "Sprawdzanie poprawności działania funkcji disk_close", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            disk_close(NULL);
      
            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 4: Sprawdzanie poprawności działania funkcji fat_open
//
void UTEST4(void)
{
    // informacje o teście
    test_start(4, "Sprawdzanie poprawności działania funkcji fat_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file("oxygen.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume == NULL, "Funkcja fat_open() powinna zwrócić NULL w przypadku przekazania błędnego obrazu dysku");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 5: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST5(void)
{
    // informacje o teście
    test_start(5, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct volume_t* volume = fat_open(NULL, 0);
            test_error(volume == NULL, "Funkcja fat_open() powinna zwrócić NULL w przypadku przekazania błędnego obrazu dysku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 6: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST6(void)
{
    // informacje o teście
    test_start(6, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(5180, 1);
                char expected_filecontent[5181] = "";
        
                strcat(expected_filecontent, "or of the fires,\nThat figure me, those, glittering in mine eye,\nAre chief of all the greatest.  This, that shines\nMidmost for pupil, was the same, who sang\nThe Holy Spirit\'s song, and bare about\nThe ark from town to town; now doth he know\nThe merit of his soul-impassion\'d strains\nBy their well-fitted guerdon.  Of the five,\nThat make the circle of the vision, he\nWho to the beak is nearest, comforted\nThe widow for her son: now doth he know\nHow dear he costeth not to follow Christ,\nBoth from experience of this pleasant life,\nAnd of its opposite.  He next, who follows\nIn the circumference, for the over arch,\nBy true repenting slack\'d the pace of death:\nNow knoweth he, that the degrees of heav\'n\nAlter not, when through pious prayer below\nToday\'s is made tomorrow\'s destiny.\nThe other following, with the laws and me,\nTo yield the shepherd room, pass\'d o\'er to Greece,\nFrom good intent producing evil fruit:\nNow knoweth he, how all the ill, deriv\'d\nFrom his well doing, doth not helm him aught,\nThough it have brought destruction on the world.\nThat, which thou seest in the under bow,\nWas William, whom that land bewails, which weeps\nFor Charles and Frederick living: now he knows\nHow well is lov\'d in heav\'n the righteous king,\nWhich he betokens by his radiant seeming.\nWho in the erring world beneath would deem,\nThat Trojan Ripheus in this round was set\nFifth of the saintly splendours?  now he knows\nEnough of that, which the world cannot see,\nThe grace divine, albeit e\'en his sight\nReach not its utmost depth.\"  Like to the lark,\nThat warbling in the air expatiates long,\nThen, trilling out his last sweet melody,\nDrops satiate with the sweetness; such appear\'d\nThat image stampt by the\' everlasting pleasure,\nWhich fashions like itself all lovely things.\n     I, though my doubting were as manifest,\nAs is through glass the hue that mantles it,\nIn silence waited not: for to my lips\n\"What things are these?\"  involuntary rush\'d,\nAnd forc\'d a passage out: whereat I mark\'d\nA sudden lightening and new revelry.\nThe eye was kindled: and the blessed sign\nNo more to keep me wond\'ring and suspense,\nReplied:  \"I see that thou believ\'st these things,\nBecause I tell them, but discern\'st not how;\nSo that thy knowledge waits not on thy faith:\nAs one who knows the name of thing by rote,\nBut is a stranger to its properties,\nTill other\'s tongue reveal them.  Fervent love\nAnd lively hope with violence assail\nThe kingdom of the heavens, and overcome\nThe will of the Most high; not in such sort\nAs man prevails o\'er man; but conquers it,\nBecause \'t is willing to be conquer\'d, still,\nThough conquer\'d, by its mercy conquering.\n     \"Those, in the eye who live the first and fifth,\nCause thee to marvel, in that thou behold\'st\nThe region of the angels deck\'d with them.\nThey quitted not their bodies, as thou deem\'st,\nGentiles but Christians, in firm rooted faith,\nThis of the feet in future to be pierc\'d,\nThat of feet nail\'d already to the cross.\nOne from the barrier of the dark abyss,\nWhere never any with good will returns,\nCame back unto his bones.  Of lively hope\nSuch was the meed; of lively hope, that wing\'d\nThe prayers sent up to God for his release,\nAnd put power into them to bend his will.\nThe glorious Spirit, of whom I speak to thee,\nA little while returning to the flesh,\nBeliev\'d in him, who had the means to help,\nAnd, in believing, nourish\'d such a flame\nOf holy love, that at the second death\nHe was made sharer in our gamesome mirth.\nThe other, through the riches of that grace,\nWhich from so deep a fountain doth distil,\nAs never eye created saw its rising,\nPlac\'d all his love below on just and right:\nWherefore of grace God op\'d in him the eye\nTo the redemption of mankind to come;\nWherein believing, he endur\'d no more\nThe filth of paganism, and for their ways\nRebuk\'d the stubborn nations.  The three nymphs,\nWhom at the right wheel thou beheldst advancing,\nWere sponsors for him more than thousand years\nBefore baptizing.  O how far remov\'d,\nPredestination!  is thy root from such\nAs see not the First cause entire: and ye,\nO mortal men!  be wary how ye judge:\nFor w");
    strcat(expected_filecontent, "e, who see our Maker, know not yet\nThe number of the chosen: and esteem\nSuch scantiness of knowledge our delight:\nFor all our good is in that primal good\nConcentrate, and God\'s will and ours are one.\"\n     So, by that form divine, was giv\'n to me\nSweet medicine to clear and strengthen sight,\nAnd, as one handling skillfully the harp,\nAttendant on some skilful songster\'s voice\nBids the chords vibrate, and therein the song\nAcquires more pleasure; so, the whilst it spake,\nIt doth remember me, that I beheld\nThe pair of blessed luminaries move.\nLike the accordant twinkling of two eyes,\nTheir beamy circlets, dancing to the sounds.\n\n\n\nCANTO XXI\n\nAgain mine eyes were fix\'d on Beatrice,\nAnd with mine eyes my soul, that in her looks\nFound all contentment.  Yet no smile she wore\nAnd, \"Did I smile,\" quoth she, \"thou wouldst be straight\nLike Semele when into ashes turn\'d:\nFor, mounting these eternal palace-stairs,\nMy beauty, which the loftier it climbs,\nAs thou hast noted, still doth kindle more,\nSo shines, that, were no temp\'ring interpos\'d,\nThy mortal puissance would from its rays");
                
        
                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "LET.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 5180, file);
                test_error(size == 5180, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 5180 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 5180);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 5180);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 7: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST7(void)
{
    // informacje o teście
    test_start(7, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(3366, 1);
                char expected_filecontent[3367] = "";
        
                strcat(expected_filecontent, "mayst see, he was a king, who ask\'d\nFor wisdom, to the end he might be king\nSufficient: not the number to search out\nOf the celestial movers; or to know,\nIf necessary with contingent e\'er\nHave made necessity; or whether that\nBe granted, that first motion is; or if\nOf the mid circle can, by art, be made\nTriangle with each corner, blunt or sharp.\n     \"Whence, noting that, which I have said, and this,\nThou kingly prudence and that ken mayst learn,\nAt which the dart of my intention aims.\nAnd, marking clearly, that I told thee, \'Risen,\'\nThou shalt discern it only hath respect\nTo kings, of whom are many, and the good\nAre rare.  With this distinction take my words;\nAnd they may well consist with that which thou\nOf the first human father dost believe,\nAnd of our well-beloved.  And let this\nHenceforth be led unto thy feet, to make\nThee slow in motion, as a weary man,\nBoth to the \'yea\' and to the \'nay\' thou seest not.\nFor he among the fools is down full low,\nWhose affirmation, or denial, is\nWithout distinction, in each case alike\nSince it befalls, that in most instances\nCurrent opinion leads to false: and then\nAffection bends the judgment to her ply.\n     \"Much more than vainly doth he loose from shore,\nSince he returns not such as he set forth,\nWho fishes for the truth and wanteth skill.\nAnd open proofs of this unto the world\nHave been afforded in Parmenides,\nMelissus, Bryso, and the crowd beside,\nWho journey\'d on, and knew not whither: so did\nSabellius, Arius, and the other fools,\nWho, like to scymitars, reflected back\nThe scripture-image, by distortion marr\'d.\n     \"Let not the people be too swift to judge,\nAs one who reckons on the blades in field,\nOr ere the crop be ripe.  For I have seen\nThe thorn frown rudely all the winter long\nAnd after bear the rose upon its top;\nAnd bark, that all the way across the sea\nRan straight and speedy, perish at the last,\nE\'en in the haven\'s mouth seeing one steal,\nAnother brine, his offering to the priest,\nLet not Dame Birtha and Sir Martin thence\nInto heav\'n\'s counsels deem that they can pry:\nFor one of these may rise, the other fall.\"\n\n\n\nCANTO XIV\n\nFrom centre to the circle, and so back\nFrom circle to the centre, water moves\nIn the round chalice, even as the blow\nImpels it, inwardly, or from without.\nSuch was the image glanc\'d into my mind,\nAs the great spirit of Aquinum ceas\'d;\nAnd Beatrice after him her words\nResum\'d alternate:  \"Need there is (tho\' yet\nHe tells it to you not in words, nor e\'en\nIn thought) that he should fathom to its depth\nAnother mystery.  Tell him, if the light,\nWherewith your substance blooms, shall stay with you\nEternally, as now: and, if it doth,\nHow, when ye shall regain your visible forms,\nThe sight may without harm endure the change,\nThat also tell.\"  As those, who in a ring\nTread the light measure, in their fitful mirth\nRaise loud the voice, and spring with gladder bound;\nThus, at the hearing of that pious suit,\nThe saintly circles in their tourneying\nAnd wond\'rous note attested new delight.\n     Whoso laments, that we must doff this garb\nOf frail mortality, thenceforth to live\nImmortally above, he hath not seen\nThe sweet refreshing, of that heav\'nly shower.\n     Him, who lives ever, and for ever reigns\nIn mystic union of the Three in One,\nUnbounded, bounding all, each spirit thrice\nSang, with such melody, as but to hear\nFor highest merit were an");
                
        
                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "FLOWER.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 3366, file);
                test_error(size == 3366, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3366 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3366);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 3366);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 8: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST8(void)
{
    // informacje o teście
    test_start(8, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(4166, 1);
                char expected_filecontent[4167] = "";
        
                strcat(expected_filecontent, "monte was engaged to marry a lady of the\nAmidei family, but broke his promise and united himself to one of\nthe Donati.  This was so much resented by the former, that a\nmeeting of themselves and their kinsmen was held, to consider of\nthe best means of revenging the insult.  Mosca degli Uberti\npersuaded them to resolve on the assassination of Buondelmonte,\nexclaiming to them  \"the thing once done, there is an end.\"  The\ncounsel and its effects were the source of many terrible\ncalamities to the state of Florence.  \"This murder,\" says G.\nVillani, l. v. c. 38,  \"was the cause and beginning of the\naccursed Guelph and Ghibelline parties in Florence.\"  It happened\nin 1215.  See the Paradise, Canto XVI. 139.\n\nv. 111.  The boon companion.]\n        What stronger breastplate than a heart untainted?\nShakespeare, 2 Hen. VI. a. iii. s. 2.\n\nv. 160.  Bertrand.]  Bertrand de Born, Vicomte de Hautefort, near\nPerigueux in Guienne, who incited John to rebel against his\nfather, Henry II. of England.  Bertrand holds a distinguished\nplace among the Provencal poets.  He is quoted in Dante, \"De\nVulg. Eloq.\" l. ii. c. 2.  For the translation of some extracts\nfrom his poems, see Millot, Hist. Litteraire des Troubadors t. i.\np. 210; but the historical parts of that work are, I believe, not\nto be relied on.\n\nCANTO XXIX.\n\nv. 26.  Geri of Bello.]  A kinsman of the Poet\'s, who was\nmurdered by one of the Sacchetti family.  His being placed here,\nmay be considered as a proof that Dante was more impartial in the\nallotment of his punishments than has generally been supposed.\n\nv. 44.  As were the torment.]  It is very probable that these\nlines gave Milton the idea of his celebrated description:\n               Immediately a place\n        Before their eyes appear\'d, sad, noisome, dark,\n        A lasar-house it seem\'d, wherein were laid\n        Numbers of all diseas\'d, all maladies, &c.\n               P. L. b. xi. 477.\n\nv. 45.  Valdichiana.]  The valley through which passes the river\nChiana, bounded by Arezzo, Cortona, Montepulciano, and Chiusi. In\nthe heat of autumn it was formerly rendered unwholesome by the\nstagnation of the water, but has since been drained by the\nEmperor Leopold II.  The Chiana is mentioned as a remarkably\nsluggish stream, in the Paradise, Canto XIII. 21.\n\nv. 47.  Maremma\'s pestilent fen.]  See Note to Canto XXV. v. 18.\n\nv. 58.  In Aegina.] He alludes to the fable of the ants changed\ninto Myrmidons. Ovid, Met. 1. vii.\n\nv. 104.  Arezzo was my dwelling.]  Grifolino of Arezzo, who\npromised Albero, son of the Bishop of Sienna, that he would teach\nhim the art of flying; and because be did not keep his promise,\nAlbero prevailed on his father to have him burnt for a\nnecromancer.\n\nv. 117.\n               Was ever race\n        Light as Sienna\'s?]\nThe same imputation is again cast on the Siennese, Purg. Canto\nXIII. 141.\n\nv. 121.  Stricca.] This is said ironically.  Stricca, Niccolo\nSalimbeni, Caccia of Asciano, and Abbagliato, or Meo de\nFolcacchieri, belonged to a company of prodigal and luxurious\nyoung men in Sienna, called the \"brigata godereccia.\"  Niccolo\nwas the inventor of a new manner of using cloves in cookery, not\nvery well understood by the commentators, and which was termed\nthe  \"costuma ricca.\"\n\nv. 125.  In that garden.]  Sienna.\n\nv. 134.  Cappocchio\'s ghost.] Capocchio of Sienna, who is said to\nhave been a fellow-student of Dante\'s in natural philosophy.\n\nCANTO XXX.\n\nv. 4.  Athamas.]  From Ovid, Metam. 1. iv.\n        Protinos Aelides, &c.\n\nv. 16.  Hecuba. See Euripedes, Hecuba; and Ovid, Metnm. l. xiii.\n\nv. 33.  Schicchi.]  Gianni Schicci, who was of the family of\nCavalcanti, possessed such a faculty of moulding his features to\nthe resemblance of others, that he was employed by Simon Donati\nto personate Buoso Donati, then recently deceased, and to make a\nwill, leaving Simon his heir; for which service he was\nrenumerated with a mare of extraordinary value, here called \"the\nlady of the herd.\"\n\nv. 39.  Myrrha.] See Ovid, Metam. l. x.\n\nv. 60. Adamo\'s woe.]  Adamo of Breschia, at the instigation of\nCuido Alessandro, and their brother Aghinul");
    strcat(expected_filecontent, "fo, lords of Romena,\ncoonterfeited the coin of Florence; for which crim");
                
        
                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "BETTER.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 4166, file);
                test_error(size == 4166, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 4166 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 4166);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 4166);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 9: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST9(void)
{
    // informacje o teście
    test_start(9, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(876, 1);
                char expected_filecontent[877] = "";
        
                strcat(expected_filecontent, "must perforce decline to worse, unaw\'d\nBy fear of other.  If thou doubt me, mark\nThe blade: each herb is judg\'d of by its seed.\nThat land, through which Adice and the Po\nTheir waters roll, was once the residence\nOf courtesy and velour, ere the day,\nThat frown\'d on Frederick; now secure may pass\nThose limits, whosoe\'er hath left, for shame,\nTo talk with good men, or come near their haunts.\nThree aged ones are still found there, in whom\nThe old time chides the new: these deem it long\nEre God restore them to a better world:\nThe good Gherardo, of Palazzo he\nConrad, and Guido of Castello, nam\'d\nIn Gallic phrase more fitly the plain Lombard.\nOn this at last conclude.  The church of Rome,\nMixing two governments that ill assort,\nHath miss\'d her footing, fall\'n into the mire,\nAnd there herself and burden much defil\'d.\"\n     \"O Marco!\" I replied, shine arguments\nConvince me");
                
        
                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "VOICE.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 876, file);
                test_error(size == 876, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 876 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 876);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 876);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 10: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST10(void)
{
    // informacje o teście
    test_start(10, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(5120, 1);
                char expected_filecontent[5121] = "";
        
                strcat(expected_filecontent, "heaven.\n\nv. 67.  Hope.]  This is from the Sentences of Petrus Lombardus.\n\"Est autem spes virtus, qua spiritualia et aeterna bona speratam,\nid  est, beatitudinem aeternam.  Sine meritis enim aliquid\nsperare non spes, sed praesumptio, dici potest.\"  Pet. Lomb.\nSent.  1.  Iii.  Dist.  26.   Ed. Bas.  1486.  Fol.\n\nv. 74.  His anthem.]  Psalm ix.  10.\n\nv. 90.  Isaias ]  Chap. lxi. 10.\n\nv. 94.  Thy brother.]  St. John in the Revelation, c. vii.  9.\n\nv. 101.  Winter\'s month.]  \"If a luminary, like that which now\nappeared, were to shine throughout the month following the winter\nsolstice during which the constellation Cancer appears in the\neast at the setting of the sun, there would be no interruption to\nthe light, but the whole month would be as a single day.\"\n\nv. 112.  This.]  St. John, who reclined on the bosom of our\nSaviour, and to whose charge Jesus recommended his mother.\n\nv. 121.  So I.]  He looked so earnestly, to descry whether St.\nJohn were present there in body, or in spirit only, having had\nhis doubts raised  by that saying of our Saviour\'s:  \"If I will,\nthat he tarry till I come  what is that to thee.\"\n\nv. 127.  The two.]  Christ and Mary, whom he has described, in\nthe last Canto but one, as rising above his sight\n\nCANTO XXVI\n\nv. 2.  The beamy flame.]  St. John.\n\nv. 13.  Ananias\' hand.]  Who, by putting his hand on St. Paul,\nrestored his sight.  Acts, c. ix.  17.\n\nv. 36.  From him.]  Some suppose that Plato is here meant, who,\nin his Banquet, makes Phaedrus say:  \"Love is confessedly amongst\nthe eldest of beings, and, being the eldest, is the cause to us\nof the greatest goods \" Plat. Op. t. x. p. 177.  Bip.  ed. Others\nhave understood it of Aristotle, and others, of the writer who\ngoes by the name of Dionysius the Areopagite, referred to in the\ntwenty-eighth Canto.\n\nv. 40.  I will make.]  Exodus, c. xxxiii. 19.\n\nv. 42.  At the outset.]  John, c. i. 1.  &c.\n\nv. 51.  The eagle of our Lord.]  St. John\n\nv. 62.  The leaves.]  Created beings.\n\nv. 82.  The first living soul.]  Adam.\n\nv. 107.  Parhelion.]  Who enlightens and comprehends all things;\nbut is himself enlightened and comprehended by none.\n\nv. 117.  Whence.]  That is, from Limbo.  See Hell, Canto II.  53.\nAdam says that 5232 years elapsed from his creation to the time\nof his deliverance, which followed the death of Christ.\n\nv. 133.  EL]  Some read UN, \"One,\" instead of EL:  but the latter\nof these readings is confirmed by a passage from Dante\'s Treatise\nDe Vulg. Eloq. 1. i. cap. 4. \"Quod prius vox primi loquentis\nsonaverit, viro sanae mentis in promptu esse non dubito ipsum\nfuisse quod Deus est, videlicet El.\"  St. Isidore in the\nOrigines, 1.  vii. c. 1. had said, \"Primum apud Hebraeos Dei\nnomen El dicitur.\"\n\nv. 135.  Use.]  From Horace, Ars. Poet. 62.\n\nv. 138.  All my life.]  \"I remained in the terrestrial Paradise\nonly tothe seventh hour.\"  In the Historia Scolastica of Petrus\nComestor, it is said of our first parents:  Quidam tradunt eos\nfuisse in Paradiso septem horae.\"  I. 9. ed. Par. 1513. 4to.\n\nCANTO XXVII\n\nv.  1.  Four torches.]  St. Peter, St. James, St. John, and Adam.\n\nv. 11.  That.]  St. Peter\' who looked as the planet Jupiter\nwould, if it assumed the sanguine appearance of liars.\n\nv. 20.  He.]  Boniface VIII.\n\nv. 26.  such colour.]\nQui color infectis adversi solis ab ietu\nNubibus esse solet; aut purpureae Aurorae.\nOvid, Met.  1. iii. 184.\n\nv. 37.  Of Linus and of Cletus.]  Bishops of Rome in the first\ncentury.\n\nv. 40.  Did Sextus, Pius, and Callixtus bleed\nAnd Urban.]\nThe former two, bishops of the same see, in the second; and the\nothers, in the fourth century.\nv. 42.  No purpose was of ours.]  \"We did not intend that our\nsuccessors should take any part in the political divisions among\nChristians, or that my figure (the seal of St. Peter) should\nserve as a mark to authorize iniquitous grants and privileges.\"\n\nv. 51.  Wolves.]  Compare Milton, P. L. b. xii. 508, &c.\n\nv. 53.  Cahorsines and Gascons.]  He alludes to Jacques d\'Ossa, a\nnative of Cahors, who filled the papal chair in 1316, after it\nhad been two years vacant, and assumed the name of John X");
    strcat(expected_filecontent, "XII.,\nand to Clement V, a Gascon, of whom see Hell, Canto XIX. 86, and\nNote.\n\nv. 63.  The she-goat.]  When the sun is in Capricorn.\n\nv. 72.  From the hour.]  Since he had last looked (see Canto\nXXII.) he perceived that he had passed from the meridian circle\nto the eastern horizon, the half of our hemisphere, and a quarter\nof the heaven.\n\nv. 76.  From Gades.]  See Hell, Canto XXVI. 106\n\nv. 78.  The shore.]  Phoenicia, where Europa, the daughter of\nAgenor mounted on the back of Jupiter, in his shape of a bull.\n\nv. 80.  The sun.]  Dante was in the constellation Gemini, and the\nsun  in Aries.  There was, therefore, part of those two\nconstellations, and the whole of Taurus, between them.\n\nv. 93.  The fair nest of Leda.]  \"From the Gemini;\" thus called,\nbecause Leda was the mother of the twins, Castor and Pollux\n\nv. 112.  Time\'s roots.]  \"Here,\" says Beatrice, \"are the roots,\nfrom whence time springs: for the parts, into which it is\ndivided, the other heavens must be considered.\"  And she then\nbreaks out into an exc");
                
        
                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "TRADE");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 5120, file);
                test_error(size == 5120, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 5120 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 5120);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 5120);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 11: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST11(void)
{
    // informacje o teście
    test_start(11, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(3507, 1);
                char expected_filecontent[3508] = "";
        
                strcat(expected_filecontent, "wood.  But lo!  of those\nWho call \'Christ, Christ,\' there shall be many found,\n In judgment, further off from him by far,\nThan such, to whom his name was never known.\nChristians like these the Ethiop shall condemn:\nWhen that the two assemblages shall part;\nOne rich eternally, the other poor.\n     \"What may the Persians say unto your kings,\nWhen they shall see that volume, in the which\nAll their dispraise is written, spread to view?\nThere amidst Albert\'s works shall that be read,\nWhich will give speedy motion to the pen,\nWhen Prague shall mourn her desolated realm.\nThere shall be read the woe, that he doth work\nWith his adulterate money on the Seine,\nWho by the tusk will perish: there be read\nThe thirsting pride, that maketh fool alike\nThe English and Scot, impatient of their bound.\nThere shall be seen the Spaniard\'s luxury,\nThe delicate living there of the Bohemian,\nWho still to worth has been a willing stranger.\nThe halter of Jerusalem shall see\nA unit for his virtue, for his vices\nNo less a mark than million.  He, who guards\nThe isle of fire by old Anchises honour\'d\nShall find his avarice there and cowardice;\nAnd better to denote his littleness,\nThe writing must be letters maim\'d, that speak\nMuch in a narrow space.  All there shall know\nHis uncle and his brother\'s filthy doings,\nWho so renown\'d a nation and two crowns\nHave bastardized.  And they, of Portugal\nAnd Norway, there shall be expos\'d with him\nOf Ratza, who hath counterfeited ill\nThe coin of Venice.  O blest Hungary!\nIf thou no longer patiently abid\'st\nThy ill-entreating!  and, O blest Navarre!\nIf with thy mountainous girdle thou wouldst arm thee\nIn earnest of that day, e\'en now are heard\nWailings and groans in Famagosta\'s streets\nAnd Nicosia\'s, grudging at their beast,\nWho keepeth even footing with the rest.\"\n\n\n\nCANTO XX\n\nWhen, disappearing, from our hemisphere,\nThe world\'s enlightener vanishes, and day\nOn all sides wasteth, suddenly the sky,\nErewhile irradiate only with his beam,\nIs yet again unfolded, putting forth\nInnumerable lights wherein one shines.\nOf such vicissitude in heaven I thought,\nAs the great sign, that marshaleth the world\nAnd the world\'s leaders, in the blessed beak\nWas silent; for that all those living lights,\nWaxing in splendour, burst forth into songs,\nSuch as from memory glide and fall away.\n     Sweet love!  that dost apparel thee in smiles,\nHow lustrous was thy semblance in those sparkles,\nWhich merely are from holy thoughts inspir\'d!\n     After the precious and bright beaming stones,\nThat did ingem the sixth light, ceas\'d the chiming\nOf their angelic bells; methought I heard\nThe murmuring of a river, that doth fall\nFrom rock to rock transpicuous, making known\nThe richness of his spring-head: and as sound\nOf cistern, at the fret-board, or of pipe,\nIs, at the wind-hole, modulate and tun\'d;\nThus up the neck, as it were hollow, rose\nThat murmuring of the eagle, and forthwith\nVoice there assum\'d, and thence along the beak\nIssued in form of words, such as my heart\nDid look for, on whose tables I inscrib\'d them.\n     \"The part in me, that sees, and bears the sun,,\nIn mortal eagles,\" it began, \"must now\nBe noted steadfastly: for of the fires,\nThat figure me, those, glittering in mine eye,\nAre chief of all the greatest.  This, that shines\nMidmost for pupil, was the same, who sang\nThe Holy Spirit\'s song, and bare about\nThe ark from town to town; now doth he know\nThe merit of his soul-impassion\'d strains\nBy their well-fitted guerdon.  Of the five,\nThat make the circle ");
                
        
                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "REMEMBER");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 3507, file);
                test_error(size == 3507, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3507 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3507);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 3507);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 12: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST12(void)
{
    // informacje o teście
    test_start(12, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(3877, 1);
                char expected_filecontent[3878] = "";
        
                strcat(expected_filecontent, "\n\"What dost thou in this deep?  Go now and know,\nSince yet thou livest, that my neighbour here\nVitaliano on my left shall sit.\nA Paduan with these Florentines am I.\nOfttimes they thunder in mine ears, exclaiming\n\"O haste that noble knight! he who the pouch\nWith the three beaks will bring!\"  This said, he writh\'d\nThe mouth, and loll\'d the tongue out, like an ox\nThat licks his nostrils.  I, lest longer stay\nHe ill might brook, who bade me stay not long,\nBackward my steps from those sad spirits turn\'d.\n     My guide already seated on the haunch\nOf the fierce animal I found; and thus\nHe me encourag\'d.  \"Be thou stout; be bold.\nDown such a steep flight must we now descend!\nMount thou before:  for that no power the tail\nMay have to harm thee, I will be i\' th\' midst.\"\n     As one, who hath an ague fit so near,\nHis nails already are turn\'d blue, and he\nQuivers all o\'er, if he but eye the shade;\nSuch was my cheer at hearing of his words.\nBut shame soon interpos\'d her threat, who makes\nThe servant bold in presence of his lord.\n     I settled me upon those shoulders huge,\nAnd would have said, but that the words to aid\nMy purpose came not, \"Look thou clasp me firm!\"\n     But he whose succour then not first I prov\'d,\nSoon as I mounted, in his arms aloft,\nEmbracing, held me up, and thus he spake:\n\"Geryon! now move thee! be thy wheeling gyres\nOf ample circuit, easy thy descent.\nThink on th\' unusual burden thou sustain\'st.\"\n     As a small vessel, back\'ning out from land,\nHer station quits; so thence the monster loos\'d,\nAnd when he felt himself at large, turn\'d round\nThere where the breast had been, his forked tail.\nThus, like an eel, outstretch\'d at length he steer\'d,\nGath\'ring the air up with retractile claws.\n     Not greater was the dread when Phaeton\nThe reins let drop at random, whence high heaven,\nWhereof signs yet appear, was wrapt in flames;\nNor when ill-fated Icarus perceiv\'d,\nBy liquefaction of the scalded wax,\nThe trusted pennons loosen\'d from his loins,\nHis sire exclaiming loud, \"Ill way thou keep\'st!\"\nThan was my dread, when round me on each part\nThe air I view\'d, and other object none\nSave the fell beast.  He slowly sailing, wheels\nHis downward motion, unobserv\'d of me,\nBut that the wind, arising to my face,\nBreathes on me from below.  Now on our right\nI heard the cataract beneath us leap\nWith hideous crash; whence bending down to\' explore,\nNew terror I conceiv\'d at the steep plunge:\nFor flames I saw, and wailings smote mine ear:\nSo that all trembling close I crouch\'d my limbs,\nAnd then distinguish\'d, unperceiv\'d before,\nBy the dread torments that on every side\nDrew nearer, how our downward course we wound.\n     As falcon, that hath long been on the wing,\nBut lure nor bird hath seen, while in despair\nThe falconer cries, \"Ah me! thou stoop\'st to earth!\"\nWearied descends, and swiftly down the sky\nIn many an orbit wheels, then lighting sits\nAt distance from his lord in angry mood;\nSo Geryon lighting places us on foot\nLow down at base of the deep-furrow\'d rock,\nAnd, of his burden there discharg\'d, forthwith\nSprang forward, like an arrow from the string.\n\n\n\nCANTO XVIII\n\nTHERE is a place within the depths of hell\nCall\'d Malebolge, all of rock dark-stain\'d\nWith hue ferruginous, e\'en as the steep\nThat round it circling winds.  Right in the midst\nOf that abominable region, yawns\nA spacious gulf profound, whereof the frame\nDue time shall tell.  The circle, that remains,\nThroughout its round, between the gulf and base\nOf the high craggy banks, successive forms\nTen trenches, in its hollow bottom sunk.\n     As where to guard the walls, full many a foss\nBegirds some stately castle, sure defence\nAffording to the space within, so here\nWere model\'d these; and as like fortresses\nE\'en from their threshold to the brink without,\nAre flank\'d with bridges; from the rock\'s low base\nThus flinty paths advanc\'d, that \'cross the moles");
                
        
                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "INDICATE.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 3877, file);
                test_error(size == 3877, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3877 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3877);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 3877);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 13: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST13(void)
{
    // informacje o teście
    test_start(13, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(5180, 1);
                char expected_filecontent[5181] = "";

                strcat(expected_filecontent, "or of the fires,\nThat figure me, those, glittering in mine eye,\nAre chief of all the greatest.  This, that shines\nMidmost for pupil, was the same, who sang\nThe Holy Spirit\'s song, and bare about\nThe ark from town to town; now doth he know\nThe merit of his soul-impassion\'d strains\nBy their well-fitted guerdon.  Of the five,\nThat make the circle of the vision, he\nWho to the beak is nearest, comforted\nThe widow for her son: now doth he know\nHow dear he costeth not to follow Christ,\nBoth from experience of this pleasant life,\nAnd of its opposite.  He next, who follows\nIn the circumference, for the over arch,\nBy true repenting slack\'d the pace of death:\nNow knoweth he, that the degrees of heav\'n\nAlter not, when through pious prayer below\nToday\'s is made tomorrow\'s destiny.\nThe other following, with the laws and me,\nTo yield the shepherd room, pass\'d o\'er to Greece,\nFrom good intent producing evil fruit:\nNow knoweth he, how all the ill, deriv\'d\nFrom his well doing, doth not helm him aught,\nThough it have brought destruction on the world.\nThat, which thou seest in the under bow,\nWas William, whom that land bewails, which weeps\nFor Charles and Frederick living: now he knows\nHow well is lov\'d in heav\'n the righteous king,\nWhich he betokens by his radiant seeming.\nWho in the erring world beneath would deem,\nThat Trojan Ripheus in this round was set\nFifth of the saintly splendours?  now he knows\nEnough of that, which the world cannot see,\nThe grace divine, albeit e\'en his sight\nReach not its utmost depth.\"  Like to the lark,\nThat warbling in the air expatiates long,\nThen, trilling out his last sweet melody,\nDrops satiate with the sweetness; such appear\'d\nThat image stampt by the\' everlasting pleasure,\nWhich fashions like itself all lovely things.\n     I, though my doubting were as manifest,\nAs is through glass the hue that mantles it,\nIn silence waited not: for to my lips\n\"What things are these?\"  involuntary rush\'d,\nAnd forc\'d a passage out: whereat I mark\'d\nA sudden lightening and new revelry.\nThe eye was kindled: and the blessed sign\nNo more to keep me wond\'ring and suspense,\nReplied:  \"I see that thou believ\'st these things,\nBecause I tell them, but discern\'st not how;\nSo that thy knowledge waits not on thy faith:\nAs one who knows the name of thing by rote,\nBut is a stranger to its properties,\nTill other\'s tongue reveal them.  Fervent love\nAnd lively hope with violence assail\nThe kingdom of the heavens, and overcome\nThe will of the Most high; not in such sort\nAs man prevails o\'er man; but conquers it,\nBecause \'t is willing to be conquer\'d, still,\nThough conquer\'d, by its mercy conquering.\n     \"Those, in the eye who live the first and fifth,\nCause thee to marvel, in that thou behold\'st\nThe region of the angels deck\'d with them.\nThey quitted not their bodies, as thou deem\'st,\nGentiles but Christians, in firm rooted faith,\nThis of the feet in future to be pierc\'d,\nThat of feet nail\'d already to the cross.\nOne from the barrier of the dark abyss,\nWhere never any with good will returns,\nCame back unto his bones.  Of lively hope\nSuch was the meed; of lively hope, that wing\'d\nThe prayers sent up to God for his release,\nAnd put power into them to bend his will.\nThe glorious Spirit, of whom I speak to thee,\nA little while returning to the flesh,\nBeliev\'d in him, who had the means to help,\nAnd, in believing, nourish\'d such a flame\nOf holy love, that at the second death\nHe was made sharer in our gamesome mirth.\nThe other, through the riches of that grace,\nWhich from so deep a fountain doth distil,\nAs never eye created saw its rising,\nPlac\'d all his love below on just and right:\nWherefore of grace God op\'d in him the eye\nTo the redemption of mankind to come;\nWherein believing, he endur\'d no more\nThe filth of paganism, and for their ways\nRebuk\'d the stubborn nations.  The three nymphs,\nWhom at the right wheel thou beheldst advancing,\nWere sponsors for him more than thousand years\nBefore baptizing.  O how far remov\'d,\nPredestination!  is thy root from such\nAs see not the First cause entire: and ye,\nO mortal men!  be wary how ye judge:\nFor w");
    strcat(expected_filecontent, "e, who see our Maker, know not yet\nThe number of the chosen: and esteem\nSuch scantiness of knowledge our delight:\nFor all our good is in that primal good\nConcentrate, and God\'s will and ours are one.\"\n     So, by that form divine, was giv\'n to me\nSweet medicine to clear and strengthen sight,\nAnd, as one handling skillfully the harp,\nAttendant on some skilful songster\'s voice\nBids the chords vibrate, and therein the song\nAcquires more pleasure; so, the whilst it spake,\nIt doth remember me, that I beheld\nThe pair of blessed luminaries move.\nLike the accordant twinkling of two eyes,\nTheir beamy circlets, dancing to the sounds.\n\n\n\nCANTO XXI\n\nAgain mine eyes were fix\'d on Beatrice,\nAnd with mine eyes my soul, that in her looks\nFound all contentment.  Yet no smile she wore\nAnd, \"Did I smile,\" quoth she, \"thou wouldst be straight\nLike Semele when into ashes turn\'d:\nFor, mounting these eternal palace-stairs,\nMy beauty, which the loftier it climbs,\nAs thou hast noted, still doth kindle more,\nSo shines, that, were no temp\'ring interpos\'d,\nThy mortal puissance would from its rays");

                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "LET.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 5468, file);
                test_error(size == 5180, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 5180 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 5180);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 5180);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 14: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST14(void)
{
    // informacje o teście
    test_start(14, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(3366, 1);
                char expected_filecontent[3367] = "";

                strcat(expected_filecontent, "mayst see, he was a king, who ask\'d\nFor wisdom, to the end he might be king\nSufficient: not the number to search out\nOf the celestial movers; or to know,\nIf necessary with contingent e\'er\nHave made necessity; or whether that\nBe granted, that first motion is; or if\nOf the mid circle can, by art, be made\nTriangle with each corner, blunt or sharp.\n     \"Whence, noting that, which I have said, and this,\nThou kingly prudence and that ken mayst learn,\nAt which the dart of my intention aims.\nAnd, marking clearly, that I told thee, \'Risen,\'\nThou shalt discern it only hath respect\nTo kings, of whom are many, and the good\nAre rare.  With this distinction take my words;\nAnd they may well consist with that which thou\nOf the first human father dost believe,\nAnd of our well-beloved.  And let this\nHenceforth be led unto thy feet, to make\nThee slow in motion, as a weary man,\nBoth to the \'yea\' and to the \'nay\' thou seest not.\nFor he among the fools is down full low,\nWhose affirmation, or denial, is\nWithout distinction, in each case alike\nSince it befalls, that in most instances\nCurrent opinion leads to false: and then\nAffection bends the judgment to her ply.\n     \"Much more than vainly doth he loose from shore,\nSince he returns not such as he set forth,\nWho fishes for the truth and wanteth skill.\nAnd open proofs of this unto the world\nHave been afforded in Parmenides,\nMelissus, Bryso, and the crowd beside,\nWho journey\'d on, and knew not whither: so did\nSabellius, Arius, and the other fools,\nWho, like to scymitars, reflected back\nThe scripture-image, by distortion marr\'d.\n     \"Let not the people be too swift to judge,\nAs one who reckons on the blades in field,\nOr ere the crop be ripe.  For I have seen\nThe thorn frown rudely all the winter long\nAnd after bear the rose upon its top;\nAnd bark, that all the way across the sea\nRan straight and speedy, perish at the last,\nE\'en in the haven\'s mouth seeing one steal,\nAnother brine, his offering to the priest,\nLet not Dame Birtha and Sir Martin thence\nInto heav\'n\'s counsels deem that they can pry:\nFor one of these may rise, the other fall.\"\n\n\n\nCANTO XIV\n\nFrom centre to the circle, and so back\nFrom circle to the centre, water moves\nIn the round chalice, even as the blow\nImpels it, inwardly, or from without.\nSuch was the image glanc\'d into my mind,\nAs the great spirit of Aquinum ceas\'d;\nAnd Beatrice after him her words\nResum\'d alternate:  \"Need there is (tho\' yet\nHe tells it to you not in words, nor e\'en\nIn thought) that he should fathom to its depth\nAnother mystery.  Tell him, if the light,\nWherewith your substance blooms, shall stay with you\nEternally, as now: and, if it doth,\nHow, when ye shall regain your visible forms,\nThe sight may without harm endure the change,\nThat also tell.\"  As those, who in a ring\nTread the light measure, in their fitful mirth\nRaise loud the voice, and spring with gladder bound;\nThus, at the hearing of that pious suit,\nThe saintly circles in their tourneying\nAnd wond\'rous note attested new delight.\n     Whoso laments, that we must doff this garb\nOf frail mortality, thenceforth to live\nImmortally above, he hath not seen\nThe sweet refreshing, of that heav\'nly shower.\n     Him, who lives ever, and for ever reigns\nIn mystic union of the Three in One,\nUnbounded, bounding all, each spirit thrice\nSang, with such melody, as but to hear\nFor highest merit were an");

                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "FLOWER.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 3755, file);
                test_error(size == 3366, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3366 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3366);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 3366);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 15: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST15(void)
{
    // informacje o teście
    test_start(15, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(4166, 1);
                char expected_filecontent[4167] = "";

                strcat(expected_filecontent, "monte was engaged to marry a lady of the\nAmidei family, but broke his promise and united himself to one of\nthe Donati.  This was so much resented by the former, that a\nmeeting of themselves and their kinsmen was held, to consider of\nthe best means of revenging the insult.  Mosca degli Uberti\npersuaded them to resolve on the assassination of Buondelmonte,\nexclaiming to them  \"the thing once done, there is an end.\"  The\ncounsel and its effects were the source of many terrible\ncalamities to the state of Florence.  \"This murder,\" says G.\nVillani, l. v. c. 38,  \"was the cause and beginning of the\naccursed Guelph and Ghibelline parties in Florence.\"  It happened\nin 1215.  See the Paradise, Canto XVI. 139.\n\nv. 111.  The boon companion.]\n        What stronger breastplate than a heart untainted?\nShakespeare, 2 Hen. VI. a. iii. s. 2.\n\nv. 160.  Bertrand.]  Bertrand de Born, Vicomte de Hautefort, near\nPerigueux in Guienne, who incited John to rebel against his\nfather, Henry II. of England.  Bertrand holds a distinguished\nplace among the Provencal poets.  He is quoted in Dante, \"De\nVulg. Eloq.\" l. ii. c. 2.  For the translation of some extracts\nfrom his poems, see Millot, Hist. Litteraire des Troubadors t. i.\np. 210; but the historical parts of that work are, I believe, not\nto be relied on.\n\nCANTO XXIX.\n\nv. 26.  Geri of Bello.]  A kinsman of the Poet\'s, who was\nmurdered by one of the Sacchetti family.  His being placed here,\nmay be considered as a proof that Dante was more impartial in the\nallotment of his punishments than has generally been supposed.\n\nv. 44.  As were the torment.]  It is very probable that these\nlines gave Milton the idea of his celebrated description:\n               Immediately a place\n        Before their eyes appear\'d, sad, noisome, dark,\n        A lasar-house it seem\'d, wherein were laid\n        Numbers of all diseas\'d, all maladies, &c.\n               P. L. b. xi. 477.\n\nv. 45.  Valdichiana.]  The valley through which passes the river\nChiana, bounded by Arezzo, Cortona, Montepulciano, and Chiusi. In\nthe heat of autumn it was formerly rendered unwholesome by the\nstagnation of the water, but has since been drained by the\nEmperor Leopold II.  The Chiana is mentioned as a remarkably\nsluggish stream, in the Paradise, Canto XIII. 21.\n\nv. 47.  Maremma\'s pestilent fen.]  See Note to Canto XXV. v. 18.\n\nv. 58.  In Aegina.] He alludes to the fable of the ants changed\ninto Myrmidons. Ovid, Met. 1. vii.\n\nv. 104.  Arezzo was my dwelling.]  Grifolino of Arezzo, who\npromised Albero, son of the Bishop of Sienna, that he would teach\nhim the art of flying; and because be did not keep his promise,\nAlbero prevailed on his father to have him burnt for a\nnecromancer.\n\nv. 117.\n               Was ever race\n        Light as Sienna\'s?]\nThe same imputation is again cast on the Siennese, Purg. Canto\nXIII. 141.\n\nv. 121.  Stricca.] This is said ironically.  Stricca, Niccolo\nSalimbeni, Caccia of Asciano, and Abbagliato, or Meo de\nFolcacchieri, belonged to a company of prodigal and luxurious\nyoung men in Sienna, called the \"brigata godereccia.\"  Niccolo\nwas the inventor of a new manner of using cloves in cookery, not\nvery well understood by the commentators, and which was termed\nthe  \"costuma ricca.\"\n\nv. 125.  In that garden.]  Sienna.\n\nv. 134.  Cappocchio\'s ghost.] Capocchio of Sienna, who is said to\nhave been a fellow-student of Dante\'s in natural philosophy.\n\nCANTO XXX.\n\nv. 4.  Athamas.]  From Ovid, Metam. 1. iv.\n        Protinos Aelides, &c.\n\nv. 16.  Hecuba. See Euripedes, Hecuba; and Ovid, Metnm. l. xiii.\n\nv. 33.  Schicchi.]  Gianni Schicci, who was of the family of\nCavalcanti, possessed such a faculty of moulding his features to\nthe resemblance of others, that he was employed by Simon Donati\nto personate Buoso Donati, then recently deceased, and to make a\nwill, leaving Simon his heir; for which service he was\nrenumerated with a mare of extraordinary value, here called \"the\nlady of the herd.\"\n\nv. 39.  Myrrha.] See Ovid, Metam. l. x.\n\nv. 60. Adamo\'s woe.]  Adamo of Breschia, at the instigation of\nCuido Alessandro, and their brother Aghinul");
    strcat(expected_filecontent, "fo, lords of Romena,\ncoonterfeited the coin of Florence; for which crim");

                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "BETTER.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 4485, file);
                test_error(size == 4166, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 4166 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 4166);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 4166);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 16: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST16(void)
{
    // informacje o teście
    test_start(16, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(876, 1);
                char expected_filecontent[877] = "";

                strcat(expected_filecontent, "must perforce decline to worse, unaw\'d\nBy fear of other.  If thou doubt me, mark\nThe blade: each herb is judg\'d of by its seed.\nThat land, through which Adice and the Po\nTheir waters roll, was once the residence\nOf courtesy and velour, ere the day,\nThat frown\'d on Frederick; now secure may pass\nThose limits, whosoe\'er hath left, for shame,\nTo talk with good men, or come near their haunts.\nThree aged ones are still found there, in whom\nThe old time chides the new: these deem it long\nEre God restore them to a better world:\nThe good Gherardo, of Palazzo he\nConrad, and Guido of Castello, nam\'d\nIn Gallic phrase more fitly the plain Lombard.\nOn this at last conclude.  The church of Rome,\nMixing two governments that ill assort,\nHath miss\'d her footing, fall\'n into the mire,\nAnd there herself and burden much defil\'d.\"\n     \"O Marco!\" I replied, shine arguments\nConvince me");

                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "VOICE.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 1353, file);
                test_error(size == 876, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 876 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 876);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 876);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 17: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST17(void)
{
    // informacje o teście
    test_start(17, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(5120, 1);
                char expected_filecontent[5121] = "";

                strcat(expected_filecontent, "heaven.\n\nv. 67.  Hope.]  This is from the Sentences of Petrus Lombardus.\n\"Est autem spes virtus, qua spiritualia et aeterna bona speratam,\nid  est, beatitudinem aeternam.  Sine meritis enim aliquid\nsperare non spes, sed praesumptio, dici potest.\"  Pet. Lomb.\nSent.  1.  Iii.  Dist.  26.   Ed. Bas.  1486.  Fol.\n\nv. 74.  His anthem.]  Psalm ix.  10.\n\nv. 90.  Isaias ]  Chap. lxi. 10.\n\nv. 94.  Thy brother.]  St. John in the Revelation, c. vii.  9.\n\nv. 101.  Winter\'s month.]  \"If a luminary, like that which now\nappeared, were to shine throughout the month following the winter\nsolstice during which the constellation Cancer appears in the\neast at the setting of the sun, there would be no interruption to\nthe light, but the whole month would be as a single day.\"\n\nv. 112.  This.]  St. John, who reclined on the bosom of our\nSaviour, and to whose charge Jesus recommended his mother.\n\nv. 121.  So I.]  He looked so earnestly, to descry whether St.\nJohn were present there in body, or in spirit only, having had\nhis doubts raised  by that saying of our Saviour\'s:  \"If I will,\nthat he tarry till I come  what is that to thee.\"\n\nv. 127.  The two.]  Christ and Mary, whom he has described, in\nthe last Canto but one, as rising above his sight\n\nCANTO XXVI\n\nv. 2.  The beamy flame.]  St. John.\n\nv. 13.  Ananias\' hand.]  Who, by putting his hand on St. Paul,\nrestored his sight.  Acts, c. ix.  17.\n\nv. 36.  From him.]  Some suppose that Plato is here meant, who,\nin his Banquet, makes Phaedrus say:  \"Love is confessedly amongst\nthe eldest of beings, and, being the eldest, is the cause to us\nof the greatest goods \" Plat. Op. t. x. p. 177.  Bip.  ed. Others\nhave understood it of Aristotle, and others, of the writer who\ngoes by the name of Dionysius the Areopagite, referred to in the\ntwenty-eighth Canto.\n\nv. 40.  I will make.]  Exodus, c. xxxiii. 19.\n\nv. 42.  At the outset.]  John, c. i. 1.  &c.\n\nv. 51.  The eagle of our Lord.]  St. John\n\nv. 62.  The leaves.]  Created beings.\n\nv. 82.  The first living soul.]  Adam.\n\nv. 107.  Parhelion.]  Who enlightens and comprehends all things;\nbut is himself enlightened and comprehended by none.\n\nv. 117.  Whence.]  That is, from Limbo.  See Hell, Canto II.  53.\nAdam says that 5232 years elapsed from his creation to the time\nof his deliverance, which followed the death of Christ.\n\nv. 133.  EL]  Some read UN, \"One,\" instead of EL:  but the latter\nof these readings is confirmed by a passage from Dante\'s Treatise\nDe Vulg. Eloq. 1. i. cap. 4. \"Quod prius vox primi loquentis\nsonaverit, viro sanae mentis in promptu esse non dubito ipsum\nfuisse quod Deus est, videlicet El.\"  St. Isidore in the\nOrigines, 1.  vii. c. 1. had said, \"Primum apud Hebraeos Dei\nnomen El dicitur.\"\n\nv. 135.  Use.]  From Horace, Ars. Poet. 62.\n\nv. 138.  All my life.]  \"I remained in the terrestrial Paradise\nonly tothe seventh hour.\"  In the Historia Scolastica of Petrus\nComestor, it is said of our first parents:  Quidam tradunt eos\nfuisse in Paradiso septem horae.\"  I. 9. ed. Par. 1513. 4to.\n\nCANTO XXVII\n\nv.  1.  Four torches.]  St. Peter, St. James, St. John, and Adam.\n\nv. 11.  That.]  St. Peter\' who looked as the planet Jupiter\nwould, if it assumed the sanguine appearance of liars.\n\nv. 20.  He.]  Boniface VIII.\n\nv. 26.  such colour.]\nQui color infectis adversi solis ab ietu\nNubibus esse solet; aut purpureae Aurorae.\nOvid, Met.  1. iii. 184.\n\nv. 37.  Of Linus and of Cletus.]  Bishops of Rome in the first\ncentury.\n\nv. 40.  Did Sextus, Pius, and Callixtus bleed\nAnd Urban.]\nThe former two, bishops of the same see, in the second; and the\nothers, in the fourth century.\nv. 42.  No purpose was of ours.]  \"We did not intend that our\nsuccessors should take any part in the political divisions among\nChristians, or that my figure (the seal of St. Peter) should\nserve as a mark to authorize iniquitous grants and privileges.\"\n\nv. 51.  Wolves.]  Compare Milton, P. L. b. xii. 508, &c.\n\nv. 53.  Cahorsines and Gascons.]  He alludes to Jacques d\'Ossa, a\nnative of Cahors, who filled the papal chair in 1316, after it\nhad been two years vacant, and assumed the name of John X");
    strcat(expected_filecontent, "XII.,\nand to Clement V, a Gascon, of whom see Hell, Canto XIX. 86, and\nNote.\n\nv. 63.  The she-goat.]  When the sun is in Capricorn.\n\nv. 72.  From the hour.]  Since he had last looked (see Canto\nXXII.) he perceived that he had passed from the meridian circle\nto the eastern horizon, the half of our hemisphere, and a quarter\nof the heaven.\n\nv. 76.  From Gades.]  See Hell, Canto XXVI. 106\n\nv. 78.  The shore.]  Phoenicia, where Europa, the daughter of\nAgenor mounted on the back of Jupiter, in his shape of a bull.\n\nv. 80.  The sun.]  Dante was in the constellation Gemini, and the\nsun  in Aries.  There was, therefore, part of those two\nconstellations, and the whole of Taurus, between them.\n\nv. 93.  The fair nest of Leda.]  \"From the Gemini;\" thus called,\nbecause Leda was the mother of the twins, Castor and Pollux\n\nv. 112.  Time\'s roots.]  \"Here,\" says Beatrice, \"are the roots,\nfrom whence time springs: for the parts, into which it is\ndivided, the other heavens must be considered.\"  And she then\nbreaks out into an exc");

                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "TRADE");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 5220, file);
                test_error(size == 5120, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 5120 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 5120);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 5120);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 18: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST18(void)
{
    // informacje o teście
    test_start(18, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(3507, 1);
                char expected_filecontent[3508] = "";

                strcat(expected_filecontent, "wood.  But lo!  of those\nWho call \'Christ, Christ,\' there shall be many found,\n In judgment, further off from him by far,\nThan such, to whom his name was never known.\nChristians like these the Ethiop shall condemn:\nWhen that the two assemblages shall part;\nOne rich eternally, the other poor.\n     \"What may the Persians say unto your kings,\nWhen they shall see that volume, in the which\nAll their dispraise is written, spread to view?\nThere amidst Albert\'s works shall that be read,\nWhich will give speedy motion to the pen,\nWhen Prague shall mourn her desolated realm.\nThere shall be read the woe, that he doth work\nWith his adulterate money on the Seine,\nWho by the tusk will perish: there be read\nThe thirsting pride, that maketh fool alike\nThe English and Scot, impatient of their bound.\nThere shall be seen the Spaniard\'s luxury,\nThe delicate living there of the Bohemian,\nWho still to worth has been a willing stranger.\nThe halter of Jerusalem shall see\nA unit for his virtue, for his vices\nNo less a mark than million.  He, who guards\nThe isle of fire by old Anchises honour\'d\nShall find his avarice there and cowardice;\nAnd better to denote his littleness,\nThe writing must be letters maim\'d, that speak\nMuch in a narrow space.  All there shall know\nHis uncle and his brother\'s filthy doings,\nWho so renown\'d a nation and two crowns\nHave bastardized.  And they, of Portugal\nAnd Norway, there shall be expos\'d with him\nOf Ratza, who hath counterfeited ill\nThe coin of Venice.  O blest Hungary!\nIf thou no longer patiently abid\'st\nThy ill-entreating!  and, O blest Navarre!\nIf with thy mountainous girdle thou wouldst arm thee\nIn earnest of that day, e\'en now are heard\nWailings and groans in Famagosta\'s streets\nAnd Nicosia\'s, grudging at their beast,\nWho keepeth even footing with the rest.\"\n\n\n\nCANTO XX\n\nWhen, disappearing, from our hemisphere,\nThe world\'s enlightener vanishes, and day\nOn all sides wasteth, suddenly the sky,\nErewhile irradiate only with his beam,\nIs yet again unfolded, putting forth\nInnumerable lights wherein one shines.\nOf such vicissitude in heaven I thought,\nAs the great sign, that marshaleth the world\nAnd the world\'s leaders, in the blessed beak\nWas silent; for that all those living lights,\nWaxing in splendour, burst forth into songs,\nSuch as from memory glide and fall away.\n     Sweet love!  that dost apparel thee in smiles,\nHow lustrous was thy semblance in those sparkles,\nWhich merely are from holy thoughts inspir\'d!\n     After the precious and bright beaming stones,\nThat did ingem the sixth light, ceas\'d the chiming\nOf their angelic bells; methought I heard\nThe murmuring of a river, that doth fall\nFrom rock to rock transpicuous, making known\nThe richness of his spring-head: and as sound\nOf cistern, at the fret-board, or of pipe,\nIs, at the wind-hole, modulate and tun\'d;\nThus up the neck, as it were hollow, rose\nThat murmuring of the eagle, and forthwith\nVoice there assum\'d, and thence along the beak\nIssued in form of words, such as my heart\nDid look for, on whose tables I inscrib\'d them.\n     \"The part in me, that sees, and bears the sun,,\nIn mortal eagles,\" it began, \"must now\nBe noted steadfastly: for of the fires,\nThat figure me, those, glittering in mine eye,\nAre chief of all the greatest.  This, that shines\nMidmost for pupil, was the same, who sang\nThe Holy Spirit\'s song, and bare about\nThe ark from town to town; now doth he know\nThe merit of his soul-impassion\'d strains\nBy their well-fitted guerdon.  Of the five,\nThat make the circle ");

                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "REMEMBER");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 3848, file);
                test_error(size == 3507, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3507 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3507);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 3507);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 19: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST19(void)
{
    // informacje o teście
    test_start(19, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(3877, 1);
                char expected_filecontent[3878] = "";

                strcat(expected_filecontent, "\n\"What dost thou in this deep?  Go now and know,\nSince yet thou livest, that my neighbour here\nVitaliano on my left shall sit.\nA Paduan with these Florentines am I.\nOfttimes they thunder in mine ears, exclaiming\n\"O haste that noble knight! he who the pouch\nWith the three beaks will bring!\"  This said, he writh\'d\nThe mouth, and loll\'d the tongue out, like an ox\nThat licks his nostrils.  I, lest longer stay\nHe ill might brook, who bade me stay not long,\nBackward my steps from those sad spirits turn\'d.\n     My guide already seated on the haunch\nOf the fierce animal I found; and thus\nHe me encourag\'d.  \"Be thou stout; be bold.\nDown such a steep flight must we now descend!\nMount thou before:  for that no power the tail\nMay have to harm thee, I will be i\' th\' midst.\"\n     As one, who hath an ague fit so near,\nHis nails already are turn\'d blue, and he\nQuivers all o\'er, if he but eye the shade;\nSuch was my cheer at hearing of his words.\nBut shame soon interpos\'d her threat, who makes\nThe servant bold in presence of his lord.\n     I settled me upon those shoulders huge,\nAnd would have said, but that the words to aid\nMy purpose came not, \"Look thou clasp me firm!\"\n     But he whose succour then not first I prov\'d,\nSoon as I mounted, in his arms aloft,\nEmbracing, held me up, and thus he spake:\n\"Geryon! now move thee! be thy wheeling gyres\nOf ample circuit, easy thy descent.\nThink on th\' unusual burden thou sustain\'st.\"\n     As a small vessel, back\'ning out from land,\nHer station quits; so thence the monster loos\'d,\nAnd when he felt himself at large, turn\'d round\nThere where the breast had been, his forked tail.\nThus, like an eel, outstretch\'d at length he steer\'d,\nGath\'ring the air up with retractile claws.\n     Not greater was the dread when Phaeton\nThe reins let drop at random, whence high heaven,\nWhereof signs yet appear, was wrapt in flames;\nNor when ill-fated Icarus perceiv\'d,\nBy liquefaction of the scalded wax,\nThe trusted pennons loosen\'d from his loins,\nHis sire exclaiming loud, \"Ill way thou keep\'st!\"\nThan was my dread, when round me on each part\nThe air I view\'d, and other object none\nSave the fell beast.  He slowly sailing, wheels\nHis downward motion, unobserv\'d of me,\nBut that the wind, arising to my face,\nBreathes on me from below.  Now on our right\nI heard the cataract beneath us leap\nWith hideous crash; whence bending down to\' explore,\nNew terror I conceiv\'d at the steep plunge:\nFor flames I saw, and wailings smote mine ear:\nSo that all trembling close I crouch\'d my limbs,\nAnd then distinguish\'d, unperceiv\'d before,\nBy the dread torments that on every side\nDrew nearer, how our downward course we wound.\n     As falcon, that hath long been on the wing,\nBut lure nor bird hath seen, while in despair\nThe falconer cries, \"Ah me! thou stoop\'st to earth!\"\nWearied descends, and swiftly down the sky\nIn many an orbit wheels, then lighting sits\nAt distance from his lord in angry mood;\nSo Geryon lighting places us on foot\nLow down at base of the deep-furrow\'d rock,\nAnd, of his burden there discharg\'d, forthwith\nSprang forward, like an arrow from the string.\n\n\n\nCANTO XVIII\n\nTHERE is a place within the depths of hell\nCall\'d Malebolge, all of rock dark-stain\'d\nWith hue ferruginous, e\'en as the steep\nThat round it circling winds.  Right in the midst\nOf that abominable region, yawns\nA spacious gulf profound, whereof the frame\nDue time shall tell.  The circle, that remains,\nThroughout its round, between the gulf and base\nOf the high craggy banks, successive forms\nTen trenches, in its hollow bottom sunk.\n     As where to guard the walls, full many a foss\nBegirds some stately castle, sure defence\nAffording to the space within, so here\nWere model\'d these; and as like fortresses\nE\'en from their threshold to the brink without,\nAre flank\'d with bridges; from the rock\'s low base\nThus flinty paths advanc\'d, that \'cross the moles");

                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "INDICATE.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 4205, file);
                test_error(size == 3877, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3877 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3877);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 3877);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 20: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST20(void)
{
    // informacje o teście
    test_start(20, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[5181] = "";

                strcat(expected_filecontent, "or of the fires,\nThat figure me, those, glittering in mine eye,\nAre chief of all the greatest.  This, that shines\nMidmost for pupil, was the same, who sang\nThe Holy Spirit\'s song, and bare about\nThe ark from town to town; now doth he know\nThe merit of his soul-impassion\'d strains\nBy their well-fitted guerdon.  Of the five,\nThat make the circle of the vision, he\nWho to the beak is nearest, comforted\nThe widow for her son: now doth he know\nHow dear he costeth not to follow Christ,\nBoth from experience of this pleasant life,\nAnd of its opposite.  He next, who follows\nIn the circumference, for the over arch,\nBy true repenting slack\'d the pace of death:\nNow knoweth he, that the degrees of heav\'n\nAlter not, when through pious prayer below\nToday\'s is made tomorrow\'s destiny.\nThe other following, with the laws and me,\nTo yield the shepherd room, pass\'d o\'er to Greece,\nFrom good intent producing evil fruit:\nNow knoweth he, how all the ill, deriv\'d\nFrom his well doing, doth not helm him aught,\nThough it have brought destruction on the world.\nThat, which thou seest in the under bow,\nWas William, whom that land bewails, which weeps\nFor Charles and Frederick living: now he knows\nHow well is lov\'d in heav\'n the righteous king,\nWhich he betokens by his radiant seeming.\nWho in the erring world beneath would deem,\nThat Trojan Ripheus in this round was set\nFifth of the saintly splendours?  now he knows\nEnough of that, which the world cannot see,\nThe grace divine, albeit e\'en his sight\nReach not its utmost depth.\"  Like to the lark,\nThat warbling in the air expatiates long,\nThen, trilling out his last sweet melody,\nDrops satiate with the sweetness; such appear\'d\nThat image stampt by the\' everlasting pleasure,\nWhich fashions like itself all lovely things.\n     I, though my doubting were as manifest,\nAs is through glass the hue that mantles it,\nIn silence waited not: for to my lips\n\"What things are these?\"  involuntary rush\'d,\nAnd forc\'d a passage out: whereat I mark\'d\nA sudden lightening and new revelry.\nThe eye was kindled: and the blessed sign\nNo more to keep me wond\'ring and suspense,\nReplied:  \"I see that thou believ\'st these things,\nBecause I tell them, but discern\'st not how;\nSo that thy knowledge waits not on thy faith:\nAs one who knows the name of thing by rote,\nBut is a stranger to its properties,\nTill other\'s tongue reveal them.  Fervent love\nAnd lively hope with violence assail\nThe kingdom of the heavens, and overcome\nThe will of the Most high; not in such sort\nAs man prevails o\'er man; but conquers it,\nBecause \'t is willing to be conquer\'d, still,\nThough conquer\'d, by its mercy conquering.\n     \"Those, in the eye who live the first and fifth,\nCause thee to marvel, in that thou behold\'st\nThe region of the angels deck\'d with them.\nThey quitted not their bodies, as thou deem\'st,\nGentiles but Christians, in firm rooted faith,\nThis of the feet in future to be pierc\'d,\nThat of feet nail\'d already to the cross.\nOne from the barrier of the dark abyss,\nWhere never any with good will returns,\nCame back unto his bones.  Of lively hope\nSuch was the meed; of lively hope, that wing\'d\nThe prayers sent up to God for his release,\nAnd put power into them to bend his will.\nThe glorious Spirit, of whom I speak to thee,\nA little while returning to the flesh,\nBeliev\'d in him, who had the means to help,\nAnd, in believing, nourish\'d such a flame\nOf holy love, that at the second death\nHe was made sharer in our gamesome mirth.\nThe other, through the riches of that grace,\nWhich from so deep a fountain doth distil,\nAs never eye created saw its rising,\nPlac\'d all his love below on just and right:\nWherefore of grace God op\'d in him the eye\nTo the redemption of mankind to come;\nWherein believing, he endur\'d no more\nThe filth of paganism, and for their ways\nRebuk\'d the stubborn nations.  The three nymphs,\nWhom at the right wheel thou beheldst advancing,\nWere sponsors for him more than thousand years\nBefore baptizing.  O how far remov\'d,\nPredestination!  is thy root from such\nAs see not the First cause entire: and ye,\nO mortal men!  be wary how ye judge:\nFor w");
    strcat(expected_filecontent, "e, who see our Maker, know not yet\nThe number of the chosen: and esteem\nSuch scantiness of knowledge our delight:\nFor all our good is in that primal good\nConcentrate, and God\'s will and ours are one.\"\n     So, by that form divine, was giv\'n to me\nSweet medicine to clear and strengthen sight,\nAnd, as one handling skillfully the harp,\nAttendant on some skilful songster\'s voice\nBids the chords vibrate, and therein the song\nAcquires more pleasure; so, the whilst it spake,\nIt doth remember me, that I beheld\nThe pair of blessed luminaries move.\nLike the accordant twinkling of two eyes,\nTheir beamy circlets, dancing to the sounds.\n\n\n\nCANTO XXI\n\nAgain mine eyes were fix\'d on Beatrice,\nAnd with mine eyes my soul, that in her looks\nFound all contentment.  Yet no smile she wore\nAnd, \"Did I smile,\" quoth she, \"thou wouldst be straight\nLike Semele when into ashes turn\'d:\nFor, mounting these eternal palace-stairs,\nMy beauty, which the loftier it climbs,\nAs thou hast noted, still doth kindle more,\nSo shines, that, were no temp\'ring interpos\'d,\nThy mortal puissance would from its rays");

                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "LET.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 5180; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 21: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST21(void)
{
    // informacje o teście
    test_start(21, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3367] = "";

                strcat(expected_filecontent, "mayst see, he was a king, who ask\'d\nFor wisdom, to the end he might be king\nSufficient: not the number to search out\nOf the celestial movers; or to know,\nIf necessary with contingent e\'er\nHave made necessity; or whether that\nBe granted, that first motion is; or if\nOf the mid circle can, by art, be made\nTriangle with each corner, blunt or sharp.\n     \"Whence, noting that, which I have said, and this,\nThou kingly prudence and that ken mayst learn,\nAt which the dart of my intention aims.\nAnd, marking clearly, that I told thee, \'Risen,\'\nThou shalt discern it only hath respect\nTo kings, of whom are many, and the good\nAre rare.  With this distinction take my words;\nAnd they may well consist with that which thou\nOf the first human father dost believe,\nAnd of our well-beloved.  And let this\nHenceforth be led unto thy feet, to make\nThee slow in motion, as a weary man,\nBoth to the \'yea\' and to the \'nay\' thou seest not.\nFor he among the fools is down full low,\nWhose affirmation, or denial, is\nWithout distinction, in each case alike\nSince it befalls, that in most instances\nCurrent opinion leads to false: and then\nAffection bends the judgment to her ply.\n     \"Much more than vainly doth he loose from shore,\nSince he returns not such as he set forth,\nWho fishes for the truth and wanteth skill.\nAnd open proofs of this unto the world\nHave been afforded in Parmenides,\nMelissus, Bryso, and the crowd beside,\nWho journey\'d on, and knew not whither: so did\nSabellius, Arius, and the other fools,\nWho, like to scymitars, reflected back\nThe scripture-image, by distortion marr\'d.\n     \"Let not the people be too swift to judge,\nAs one who reckons on the blades in field,\nOr ere the crop be ripe.  For I have seen\nThe thorn frown rudely all the winter long\nAnd after bear the rose upon its top;\nAnd bark, that all the way across the sea\nRan straight and speedy, perish at the last,\nE\'en in the haven\'s mouth seeing one steal,\nAnother brine, his offering to the priest,\nLet not Dame Birtha and Sir Martin thence\nInto heav\'n\'s counsels deem that they can pry:\nFor one of these may rise, the other fall.\"\n\n\n\nCANTO XIV\n\nFrom centre to the circle, and so back\nFrom circle to the centre, water moves\nIn the round chalice, even as the blow\nImpels it, inwardly, or from without.\nSuch was the image glanc\'d into my mind,\nAs the great spirit of Aquinum ceas\'d;\nAnd Beatrice after him her words\nResum\'d alternate:  \"Need there is (tho\' yet\nHe tells it to you not in words, nor e\'en\nIn thought) that he should fathom to its depth\nAnother mystery.  Tell him, if the light,\nWherewith your substance blooms, shall stay with you\nEternally, as now: and, if it doth,\nHow, when ye shall regain your visible forms,\nThe sight may without harm endure the change,\nThat also tell.\"  As those, who in a ring\nTread the light measure, in their fitful mirth\nRaise loud the voice, and spring with gladder bound;\nThus, at the hearing of that pious suit,\nThe saintly circles in their tourneying\nAnd wond\'rous note attested new delight.\n     Whoso laments, that we must doff this garb\nOf frail mortality, thenceforth to live\nImmortally above, he hath not seen\nThe sweet refreshing, of that heav\'nly shower.\n     Him, who lives ever, and for ever reigns\nIn mystic union of the Three in One,\nUnbounded, bounding all, each spirit thrice\nSang, with such melody, as but to hear\nFor highest merit were an");

                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "FLOWER.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3366; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 22: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST22(void)
{
    // informacje o teście
    test_start(22, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[4167] = "";

                strcat(expected_filecontent, "monte was engaged to marry a lady of the\nAmidei family, but broke his promise and united himself to one of\nthe Donati.  This was so much resented by the former, that a\nmeeting of themselves and their kinsmen was held, to consider of\nthe best means of revenging the insult.  Mosca degli Uberti\npersuaded them to resolve on the assassination of Buondelmonte,\nexclaiming to them  \"the thing once done, there is an end.\"  The\ncounsel and its effects were the source of many terrible\ncalamities to the state of Florence.  \"This murder,\" says G.\nVillani, l. v. c. 38,  \"was the cause and beginning of the\naccursed Guelph and Ghibelline parties in Florence.\"  It happened\nin 1215.  See the Paradise, Canto XVI. 139.\n\nv. 111.  The boon companion.]\n        What stronger breastplate than a heart untainted?\nShakespeare, 2 Hen. VI. a. iii. s. 2.\n\nv. 160.  Bertrand.]  Bertrand de Born, Vicomte de Hautefort, near\nPerigueux in Guienne, who incited John to rebel against his\nfather, Henry II. of England.  Bertrand holds a distinguished\nplace among the Provencal poets.  He is quoted in Dante, \"De\nVulg. Eloq.\" l. ii. c. 2.  For the translation of some extracts\nfrom his poems, see Millot, Hist. Litteraire des Troubadors t. i.\np. 210; but the historical parts of that work are, I believe, not\nto be relied on.\n\nCANTO XXIX.\n\nv. 26.  Geri of Bello.]  A kinsman of the Poet\'s, who was\nmurdered by one of the Sacchetti family.  His being placed here,\nmay be considered as a proof that Dante was more impartial in the\nallotment of his punishments than has generally been supposed.\n\nv. 44.  As were the torment.]  It is very probable that these\nlines gave Milton the idea of his celebrated description:\n               Immediately a place\n        Before their eyes appear\'d, sad, noisome, dark,\n        A lasar-house it seem\'d, wherein were laid\n        Numbers of all diseas\'d, all maladies, &c.\n               P. L. b. xi. 477.\n\nv. 45.  Valdichiana.]  The valley through which passes the river\nChiana, bounded by Arezzo, Cortona, Montepulciano, and Chiusi. In\nthe heat of autumn it was formerly rendered unwholesome by the\nstagnation of the water, but has since been drained by the\nEmperor Leopold II.  The Chiana is mentioned as a remarkably\nsluggish stream, in the Paradise, Canto XIII. 21.\n\nv. 47.  Maremma\'s pestilent fen.]  See Note to Canto XXV. v. 18.\n\nv. 58.  In Aegina.] He alludes to the fable of the ants changed\ninto Myrmidons. Ovid, Met. 1. vii.\n\nv. 104.  Arezzo was my dwelling.]  Grifolino of Arezzo, who\npromised Albero, son of the Bishop of Sienna, that he would teach\nhim the art of flying; and because be did not keep his promise,\nAlbero prevailed on his father to have him burnt for a\nnecromancer.\n\nv. 117.\n               Was ever race\n        Light as Sienna\'s?]\nThe same imputation is again cast on the Siennese, Purg. Canto\nXIII. 141.\n\nv. 121.  Stricca.] This is said ironically.  Stricca, Niccolo\nSalimbeni, Caccia of Asciano, and Abbagliato, or Meo de\nFolcacchieri, belonged to a company of prodigal and luxurious\nyoung men in Sienna, called the \"brigata godereccia.\"  Niccolo\nwas the inventor of a new manner of using cloves in cookery, not\nvery well understood by the commentators, and which was termed\nthe  \"costuma ricca.\"\n\nv. 125.  In that garden.]  Sienna.\n\nv. 134.  Cappocchio\'s ghost.] Capocchio of Sienna, who is said to\nhave been a fellow-student of Dante\'s in natural philosophy.\n\nCANTO XXX.\n\nv. 4.  Athamas.]  From Ovid, Metam. 1. iv.\n        Protinos Aelides, &c.\n\nv. 16.  Hecuba. See Euripedes, Hecuba; and Ovid, Metnm. l. xiii.\n\nv. 33.  Schicchi.]  Gianni Schicci, who was of the family of\nCavalcanti, possessed such a faculty of moulding his features to\nthe resemblance of others, that he was employed by Simon Donati\nto personate Buoso Donati, then recently deceased, and to make a\nwill, leaving Simon his heir; for which service he was\nrenumerated with a mare of extraordinary value, here called \"the\nlady of the herd.\"\n\nv. 39.  Myrrha.] See Ovid, Metam. l. x.\n\nv. 60. Adamo\'s woe.]  Adamo of Breschia, at the instigation of\nCuido Alessandro, and their brother Aghinul");
    strcat(expected_filecontent, "fo, lords of Romena,\ncoonterfeited the coin of Florence; for which crim");

                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "BETTER.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 4166; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 23: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST23(void)
{
    // informacje o teście
    test_start(23, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[877] = "";

                strcat(expected_filecontent, "must perforce decline to worse, unaw\'d\nBy fear of other.  If thou doubt me, mark\nThe blade: each herb is judg\'d of by its seed.\nThat land, through which Adice and the Po\nTheir waters roll, was once the residence\nOf courtesy and velour, ere the day,\nThat frown\'d on Frederick; now secure may pass\nThose limits, whosoe\'er hath left, for shame,\nTo talk with good men, or come near their haunts.\nThree aged ones are still found there, in whom\nThe old time chides the new: these deem it long\nEre God restore them to a better world:\nThe good Gherardo, of Palazzo he\nConrad, and Guido of Castello, nam\'d\nIn Gallic phrase more fitly the plain Lombard.\nOn this at last conclude.  The church of Rome,\nMixing two governments that ill assort,\nHath miss\'d her footing, fall\'n into the mire,\nAnd there herself and burden much defil\'d.\"\n     \"O Marco!\" I replied, shine arguments\nConvince me");

                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "VOICE.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 876; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 24: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST24(void)
{
    // informacje o teście
    test_start(24, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[5121] = "";

                strcat(expected_filecontent, "heaven.\n\nv. 67.  Hope.]  This is from the Sentences of Petrus Lombardus.\n\"Est autem spes virtus, qua spiritualia et aeterna bona speratam,\nid  est, beatitudinem aeternam.  Sine meritis enim aliquid\nsperare non spes, sed praesumptio, dici potest.\"  Pet. Lomb.\nSent.  1.  Iii.  Dist.  26.   Ed. Bas.  1486.  Fol.\n\nv. 74.  His anthem.]  Psalm ix.  10.\n\nv. 90.  Isaias ]  Chap. lxi. 10.\n\nv. 94.  Thy brother.]  St. John in the Revelation, c. vii.  9.\n\nv. 101.  Winter\'s month.]  \"If a luminary, like that which now\nappeared, were to shine throughout the month following the winter\nsolstice during which the constellation Cancer appears in the\neast at the setting of the sun, there would be no interruption to\nthe light, but the whole month would be as a single day.\"\n\nv. 112.  This.]  St. John, who reclined on the bosom of our\nSaviour, and to whose charge Jesus recommended his mother.\n\nv. 121.  So I.]  He looked so earnestly, to descry whether St.\nJohn were present there in body, or in spirit only, having had\nhis doubts raised  by that saying of our Saviour\'s:  \"If I will,\nthat he tarry till I come  what is that to thee.\"\n\nv. 127.  The two.]  Christ and Mary, whom he has described, in\nthe last Canto but one, as rising above his sight\n\nCANTO XXVI\n\nv. 2.  The beamy flame.]  St. John.\n\nv. 13.  Ananias\' hand.]  Who, by putting his hand on St. Paul,\nrestored his sight.  Acts, c. ix.  17.\n\nv. 36.  From him.]  Some suppose that Plato is here meant, who,\nin his Banquet, makes Phaedrus say:  \"Love is confessedly amongst\nthe eldest of beings, and, being the eldest, is the cause to us\nof the greatest goods \" Plat. Op. t. x. p. 177.  Bip.  ed. Others\nhave understood it of Aristotle, and others, of the writer who\ngoes by the name of Dionysius the Areopagite, referred to in the\ntwenty-eighth Canto.\n\nv. 40.  I will make.]  Exodus, c. xxxiii. 19.\n\nv. 42.  At the outset.]  John, c. i. 1.  &c.\n\nv. 51.  The eagle of our Lord.]  St. John\n\nv. 62.  The leaves.]  Created beings.\n\nv. 82.  The first living soul.]  Adam.\n\nv. 107.  Parhelion.]  Who enlightens and comprehends all things;\nbut is himself enlightened and comprehended by none.\n\nv. 117.  Whence.]  That is, from Limbo.  See Hell, Canto II.  53.\nAdam says that 5232 years elapsed from his creation to the time\nof his deliverance, which followed the death of Christ.\n\nv. 133.  EL]  Some read UN, \"One,\" instead of EL:  but the latter\nof these readings is confirmed by a passage from Dante\'s Treatise\nDe Vulg. Eloq. 1. i. cap. 4. \"Quod prius vox primi loquentis\nsonaverit, viro sanae mentis in promptu esse non dubito ipsum\nfuisse quod Deus est, videlicet El.\"  St. Isidore in the\nOrigines, 1.  vii. c. 1. had said, \"Primum apud Hebraeos Dei\nnomen El dicitur.\"\n\nv. 135.  Use.]  From Horace, Ars. Poet. 62.\n\nv. 138.  All my life.]  \"I remained in the terrestrial Paradise\nonly tothe seventh hour.\"  In the Historia Scolastica of Petrus\nComestor, it is said of our first parents:  Quidam tradunt eos\nfuisse in Paradiso septem horae.\"  I. 9. ed. Par. 1513. 4to.\n\nCANTO XXVII\n\nv.  1.  Four torches.]  St. Peter, St. James, St. John, and Adam.\n\nv. 11.  That.]  St. Peter\' who looked as the planet Jupiter\nwould, if it assumed the sanguine appearance of liars.\n\nv. 20.  He.]  Boniface VIII.\n\nv. 26.  such colour.]\nQui color infectis adversi solis ab ietu\nNubibus esse solet; aut purpureae Aurorae.\nOvid, Met.  1. iii. 184.\n\nv. 37.  Of Linus and of Cletus.]  Bishops of Rome in the first\ncentury.\n\nv. 40.  Did Sextus, Pius, and Callixtus bleed\nAnd Urban.]\nThe former two, bishops of the same see, in the second; and the\nothers, in the fourth century.\nv. 42.  No purpose was of ours.]  \"We did not intend that our\nsuccessors should take any part in the political divisions among\nChristians, or that my figure (the seal of St. Peter) should\nserve as a mark to authorize iniquitous grants and privileges.\"\n\nv. 51.  Wolves.]  Compare Milton, P. L. b. xii. 508, &c.\n\nv. 53.  Cahorsines and Gascons.]  He alludes to Jacques d\'Ossa, a\nnative of Cahors, who filled the papal chair in 1316, after it\nhad been two years vacant, and assumed the name of John X");
    strcat(expected_filecontent, "XII.,\nand to Clement V, a Gascon, of whom see Hell, Canto XIX. 86, and\nNote.\n\nv. 63.  The she-goat.]  When the sun is in Capricorn.\n\nv. 72.  From the hour.]  Since he had last looked (see Canto\nXXII.) he perceived that he had passed from the meridian circle\nto the eastern horizon, the half of our hemisphere, and a quarter\nof the heaven.\n\nv. 76.  From Gades.]  See Hell, Canto XXVI. 106\n\nv. 78.  The shore.]  Phoenicia, where Europa, the daughter of\nAgenor mounted on the back of Jupiter, in his shape of a bull.\n\nv. 80.  The sun.]  Dante was in the constellation Gemini, and the\nsun  in Aries.  There was, therefore, part of those two\nconstellations, and the whole of Taurus, between them.\n\nv. 93.  The fair nest of Leda.]  \"From the Gemini;\" thus called,\nbecause Leda was the mother of the twins, Castor and Pollux\n\nv. 112.  Time\'s roots.]  \"Here,\" says Beatrice, \"are the roots,\nfrom whence time springs: for the parts, into which it is\ndivided, the other heavens must be considered.\"  And she then\nbreaks out into an exc");

                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "TRADE");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 5120; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 25: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST25(void)
{
    // informacje o teście
    test_start(25, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3508] = "";

                strcat(expected_filecontent, "wood.  But lo!  of those\nWho call \'Christ, Christ,\' there shall be many found,\n In judgment, further off from him by far,\nThan such, to whom his name was never known.\nChristians like these the Ethiop shall condemn:\nWhen that the two assemblages shall part;\nOne rich eternally, the other poor.\n     \"What may the Persians say unto your kings,\nWhen they shall see that volume, in the which\nAll their dispraise is written, spread to view?\nThere amidst Albert\'s works shall that be read,\nWhich will give speedy motion to the pen,\nWhen Prague shall mourn her desolated realm.\nThere shall be read the woe, that he doth work\nWith his adulterate money on the Seine,\nWho by the tusk will perish: there be read\nThe thirsting pride, that maketh fool alike\nThe English and Scot, impatient of their bound.\nThere shall be seen the Spaniard\'s luxury,\nThe delicate living there of the Bohemian,\nWho still to worth has been a willing stranger.\nThe halter of Jerusalem shall see\nA unit for his virtue, for his vices\nNo less a mark than million.  He, who guards\nThe isle of fire by old Anchises honour\'d\nShall find his avarice there and cowardice;\nAnd better to denote his littleness,\nThe writing must be letters maim\'d, that speak\nMuch in a narrow space.  All there shall know\nHis uncle and his brother\'s filthy doings,\nWho so renown\'d a nation and two crowns\nHave bastardized.  And they, of Portugal\nAnd Norway, there shall be expos\'d with him\nOf Ratza, who hath counterfeited ill\nThe coin of Venice.  O blest Hungary!\nIf thou no longer patiently abid\'st\nThy ill-entreating!  and, O blest Navarre!\nIf with thy mountainous girdle thou wouldst arm thee\nIn earnest of that day, e\'en now are heard\nWailings and groans in Famagosta\'s streets\nAnd Nicosia\'s, grudging at their beast,\nWho keepeth even footing with the rest.\"\n\n\n\nCANTO XX\n\nWhen, disappearing, from our hemisphere,\nThe world\'s enlightener vanishes, and day\nOn all sides wasteth, suddenly the sky,\nErewhile irradiate only with his beam,\nIs yet again unfolded, putting forth\nInnumerable lights wherein one shines.\nOf such vicissitude in heaven I thought,\nAs the great sign, that marshaleth the world\nAnd the world\'s leaders, in the blessed beak\nWas silent; for that all those living lights,\nWaxing in splendour, burst forth into songs,\nSuch as from memory glide and fall away.\n     Sweet love!  that dost apparel thee in smiles,\nHow lustrous was thy semblance in those sparkles,\nWhich merely are from holy thoughts inspir\'d!\n     After the precious and bright beaming stones,\nThat did ingem the sixth light, ceas\'d the chiming\nOf their angelic bells; methought I heard\nThe murmuring of a river, that doth fall\nFrom rock to rock transpicuous, making known\nThe richness of his spring-head: and as sound\nOf cistern, at the fret-board, or of pipe,\nIs, at the wind-hole, modulate and tun\'d;\nThus up the neck, as it were hollow, rose\nThat murmuring of the eagle, and forthwith\nVoice there assum\'d, and thence along the beak\nIssued in form of words, such as my heart\nDid look for, on whose tables I inscrib\'d them.\n     \"The part in me, that sees, and bears the sun,,\nIn mortal eagles,\" it began, \"must now\nBe noted steadfastly: for of the fires,\nThat figure me, those, glittering in mine eye,\nAre chief of all the greatest.  This, that shines\nMidmost for pupil, was the same, who sang\nThe Holy Spirit\'s song, and bare about\nThe ark from town to town; now doth he know\nThe merit of his soul-impassion\'d strains\nBy their well-fitted guerdon.  Of the five,\nThat make the circle ");

                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "REMEMBER");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3507; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 26: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST26(void)
{
    // informacje o teście
    test_start(26, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3878] = "";

                strcat(expected_filecontent, "\n\"What dost thou in this deep?  Go now and know,\nSince yet thou livest, that my neighbour here\nVitaliano on my left shall sit.\nA Paduan with these Florentines am I.\nOfttimes they thunder in mine ears, exclaiming\n\"O haste that noble knight! he who the pouch\nWith the three beaks will bring!\"  This said, he writh\'d\nThe mouth, and loll\'d the tongue out, like an ox\nThat licks his nostrils.  I, lest longer stay\nHe ill might brook, who bade me stay not long,\nBackward my steps from those sad spirits turn\'d.\n     My guide already seated on the haunch\nOf the fierce animal I found; and thus\nHe me encourag\'d.  \"Be thou stout; be bold.\nDown such a steep flight must we now descend!\nMount thou before:  for that no power the tail\nMay have to harm thee, I will be i\' th\' midst.\"\n     As one, who hath an ague fit so near,\nHis nails already are turn\'d blue, and he\nQuivers all o\'er, if he but eye the shade;\nSuch was my cheer at hearing of his words.\nBut shame soon interpos\'d her threat, who makes\nThe servant bold in presence of his lord.\n     I settled me upon those shoulders huge,\nAnd would have said, but that the words to aid\nMy purpose came not, \"Look thou clasp me firm!\"\n     But he whose succour then not first I prov\'d,\nSoon as I mounted, in his arms aloft,\nEmbracing, held me up, and thus he spake:\n\"Geryon! now move thee! be thy wheeling gyres\nOf ample circuit, easy thy descent.\nThink on th\' unusual burden thou sustain\'st.\"\n     As a small vessel, back\'ning out from land,\nHer station quits; so thence the monster loos\'d,\nAnd when he felt himself at large, turn\'d round\nThere where the breast had been, his forked tail.\nThus, like an eel, outstretch\'d at length he steer\'d,\nGath\'ring the air up with retractile claws.\n     Not greater was the dread when Phaeton\nThe reins let drop at random, whence high heaven,\nWhereof signs yet appear, was wrapt in flames;\nNor when ill-fated Icarus perceiv\'d,\nBy liquefaction of the scalded wax,\nThe trusted pennons loosen\'d from his loins,\nHis sire exclaiming loud, \"Ill way thou keep\'st!\"\nThan was my dread, when round me on each part\nThe air I view\'d, and other object none\nSave the fell beast.  He slowly sailing, wheels\nHis downward motion, unobserv\'d of me,\nBut that the wind, arising to my face,\nBreathes on me from below.  Now on our right\nI heard the cataract beneath us leap\nWith hideous crash; whence bending down to\' explore,\nNew terror I conceiv\'d at the steep plunge:\nFor flames I saw, and wailings smote mine ear:\nSo that all trembling close I crouch\'d my limbs,\nAnd then distinguish\'d, unperceiv\'d before,\nBy the dread torments that on every side\nDrew nearer, how our downward course we wound.\n     As falcon, that hath long been on the wing,\nBut lure nor bird hath seen, while in despair\nThe falconer cries, \"Ah me! thou stoop\'st to earth!\"\nWearied descends, and swiftly down the sky\nIn many an orbit wheels, then lighting sits\nAt distance from his lord in angry mood;\nSo Geryon lighting places us on foot\nLow down at base of the deep-furrow\'d rock,\nAnd, of his burden there discharg\'d, forthwith\nSprang forward, like an arrow from the string.\n\n\n\nCANTO XVIII\n\nTHERE is a place within the depths of hell\nCall\'d Malebolge, all of rock dark-stain\'d\nWith hue ferruginous, e\'en as the steep\nThat round it circling winds.  Right in the midst\nOf that abominable region, yawns\nA spacious gulf profound, whereof the frame\nDue time shall tell.  The circle, that remains,\nThroughout its round, between the gulf and base\nOf the high craggy banks, successive forms\nTen trenches, in its hollow bottom sunk.\n     As where to guard the walls, full many a foss\nBegirds some stately castle, sure defence\nAffording to the space within, so here\nWere model\'d these; and as like fortresses\nE\'en from their threshold to the brink without,\nAre flank\'d with bridges; from the rock\'s low base\nThus flinty paths advanc\'d, that \'cross the moles");

                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "INDICATE.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3877; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 27: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST27(void)
{
    // informacje o teście
    test_start(27, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(3366, 1);
            char expected_filecontent[3367] = "";

            strcat(expected_filecontent, "mayst see, he was a king, who ask\'d\nFor wisdom, to the end he might be king\nSufficient: not the number to search out\nOf the celestial movers; or to know,\nIf necessary with contingent e\'er\nHave made necessity; or whether that\nBe granted, that first motion is; or if\nOf the mid circle can, by art, be made\nTriangle with each corner, blunt or sharp.\n     \"Whence, noting that, which I have said, and this,\nThou kingly prudence and that ken mayst learn,\nAt which the dart of my intention aims.\nAnd, marking clearly, that I told thee, \'Risen,\'\nThou shalt discern it only hath respect\nTo kings, of whom are many, and the good\nAre rare.  With this distinction take my words;\nAnd they may well consist with that which thou\nOf the first human father dost believe,\nAnd of our well-beloved.  And let this\nHenceforth be led unto thy feet, to make\nThee slow in motion, as a weary man,\nBoth to the \'yea\' and to the \'nay\' thou seest not.\nFor he among the fools is down full low,\nWhose affirmation, or denial, is\nWithout distinction, in each case alike\nSince it befalls, that in most instances\nCurrent opinion leads to false: and then\nAffection bends the judgment to her ply.\n     \"Much more than vainly doth he loose from shore,\nSince he returns not such as he set forth,\nWho fishes for the truth and wanteth skill.\nAnd open proofs of this unto the world\nHave been afforded in Parmenides,\nMelissus, Bryso, and the crowd beside,\nWho journey\'d on, and knew not whither: so did\nSabellius, Arius, and the other fools,\nWho, like to scymitars, reflected back\nThe scripture-image, by distortion marr\'d.\n     \"Let not the people be too swift to judge,\nAs one who reckons on the blades in field,\nOr ere the crop be ripe.  For I have seen\nThe thorn frown rudely all the winter long\nAnd after bear the rose upon its top;\nAnd bark, that all the way across the sea\nRan straight and speedy, perish at the last,\nE\'en in the haven\'s mouth seeing one steal,\nAnother brine, his offering to the priest,\nLet not Dame Birtha and Sir Martin thence\nInto heav\'n\'s counsels deem that they can pry:\nFor one of these may rise, the other fall.\"\n\n\n\nCANTO XIV\n\nFrom centre to the circle, and so back\nFrom circle to the centre, water moves\nIn the round chalice, even as the blow\nImpels it, inwardly, or from without.\nSuch was the image glanc\'d into my mind,\nAs the great spirit of Aquinum ceas\'d;\nAnd Beatrice after him her words\nResum\'d alternate:  \"Need there is (tho\' yet\nHe tells it to you not in words, nor e\'en\nIn thought) that he should fathom to its depth\nAnother mystery.  Tell him, if the light,\nWherewith your substance blooms, shall stay with you\nEternally, as now: and, if it doth,\nHow, when ye shall regain your visible forms,\nThe sight may without harm endure the change,\nThat also tell.\"  As those, who in a ring\nTread the light measure, in their fitful mirth\nRaise loud the voice, and spring with gladder bound;\nThus, at the hearing of that pious suit,\nThe saintly circles in their tourneying\nAnd wond\'rous note attested new delight.\n     Whoso laments, that we must doff this garb\nOf frail mortality, thenceforth to live\nImmortally above, he hath not seen\nThe sweet refreshing, of that heav\'nly shower.\n     Him, who lives ever, and for ever reigns\nIn mystic union of the Three in One,\nUnbounded, bounding all, each spirit thrice\nSang, with such melody, as but to hear\nFor highest merit were an");

            struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "FLOWER.TX");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int i;
            for (i = 0; i < 561; ++i)
            {
                int res = file_read(filecontent + 6 * i, 6, 1, file);
                test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            }

            int res = file_read(filecontent + 6 * i, 6, 1, file);
            test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3366);

            // jeśli jest, to raportuj błąd
            test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

            onerror_compare_memory(expected_filecontent, filecontent, 3366);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 28: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST28(void)
{
    // informacje o teście
    test_start(28, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char *filecontent0 = (char *)calloc(5180, 1);
    char *filecontent1 = (char *)calloc(3366, 1);
    char *filecontent2 = (char *)calloc(4166, 1);
    char *filecontent3 = (char *)calloc(876, 1);
    char *filecontent4 = (char *)calloc(5120, 1);
    char *filecontent5 = (char *)calloc(3507, 1);
    char *filecontent6 = (char *)calloc(3877, 1);

            char expected_filecontent0[5181] = "";
    char expected_filecontent1[3367] = "";
    char expected_filecontent2[4167] = "";
    char expected_filecontent3[877] = "";
    char expected_filecontent4[5121] = "";
    char expected_filecontent5[3508] = "";
    char expected_filecontent6[3878] = "";

            strcat(expected_filecontent0, "or of the fires,\nThat figure me, those, glittering in mine eye,\nAre chief of all the greatest.  This, that shines\nMidmost for pupil, was the same, who sang\nThe Holy Spirit\'s song, and bare about\nThe ark from town to town; now doth he know\nThe merit of his soul-impassion\'d strains\nBy their well-fitted guerdon.  Of the five,\nThat make the circle of the vision, he\nWho to the beak is nearest, comforted\nThe widow for her son: now doth he know\nHow dear he costeth not to follow Christ,\nBoth from experience of this pleasant life,\nAnd of its opposite.  He next, who follows\nIn the circumference, for the over arch,\nBy true repenting slack\'d the pace of death:\nNow knoweth he, that the degrees of heav\'n\nAlter not, when through pious prayer below\nToday\'s is made tomorrow\'s destiny.\nThe other following, with the laws and me,\nTo yield the shepherd room, pass\'d o\'er to Greece,\nFrom good intent producing evil fruit:\nNow knoweth he, how all the ill, deriv\'d\nFrom his well doing, doth not helm him aught,\nThough it have brought destruction on the world.\nThat, which thou seest in the under bow,\nWas William, whom that land bewails, which weeps\nFor Charles and Frederick living: now he knows\nHow well is lov\'d in heav\'n the righteous king,\nWhich he betokens by his radiant seeming.\nWho in the erring world beneath would deem,\nThat Trojan Ripheus in this round was set\nFifth of the saintly splendours?  now he knows\nEnough of that, which the world cannot see,\nThe grace divine, albeit e\'en his sight\nReach not its utmost depth.\"  Like to the lark,\nThat warbling in the air expatiates long,\nThen, trilling out his last sweet melody,\nDrops satiate with the sweetness; such appear\'d\nThat image stampt by the\' everlasting pleasure,\nWhich fashions like itself all lovely things.\n     I, though my doubting were as manifest,\nAs is through glass the hue that mantles it,\nIn silence waited not: for to my lips\n\"What things are these?\"  involuntary rush\'d,\nAnd forc\'d a passage out: whereat I mark\'d\nA sudden lightening and new revelry.\nThe eye was kindled: and the blessed sign\nNo more to keep me wond\'ring and suspense,\nReplied:  \"I see that thou believ\'st these things,\nBecause I tell them, but discern\'st not how;\nSo that thy knowledge waits not on thy faith:\nAs one who knows the name of thing by rote,\nBut is a stranger to its properties,\nTill other\'s tongue reveal them.  Fervent love\nAnd lively hope with violence assail\nThe kingdom of the heavens, and overcome\nThe will of the Most high; not in such sort\nAs man prevails o\'er man; but conquers it,\nBecause \'t is willing to be conquer\'d, still,\nThough conquer\'d, by its mercy conquering.\n     \"Those, in the eye who live the first and fifth,\nCause thee to marvel, in that thou behold\'st\nThe region of the angels deck\'d with them.\nThey quitted not their bodies, as thou deem\'st,\nGentiles but Christians, in firm rooted faith,\nThis of the feet in future to be pierc\'d,\nThat of feet nail\'d already to the cross.\nOne from the barrier of the dark abyss,\nWhere never any with good will returns,\nCame back unto his bones.  Of lively hope\nSuch was the meed; of lively hope, that wing\'d\nThe prayers sent up to God for his release,\nAnd put power into them to bend his will.\nThe glorious Spirit, of whom I speak to thee,\nA little while returning to the flesh,\nBeliev\'d in him, who had the means to help,\nAnd, in believing, nourish\'d such a flame\nOf holy love, that at the second death\nHe was made sharer in our gamesome mirth.\nThe other, through the riches of that grace,\nWhich from so deep a fountain doth distil,\nAs never eye created saw its rising,\nPlac\'d all his love below on just and right:\nWherefore of grace God op\'d in him the eye\nTo the redemption of mankind to come;\nWherein believing, he endur\'d no more\nThe filth of paganism, and for their ways\nRebuk\'d the stubborn nations.  The three nymphs,\nWhom at the right wheel thou beheldst advancing,\nWere sponsors for him more than thousand years\nBefore baptizing.  O how far remov\'d,\nPredestination!  is thy root from such\nAs see not the First cause entire: and ye,\nO mortal men!  be wary how ye judge:\nFor w");
    strcat(expected_filecontent0, "e, who see our Maker, know not yet\nThe number of the chosen: and esteem\nSuch scantiness of knowledge our delight:\nFor all our good is in that primal good\nConcentrate, and God\'s will and ours are one.\"\n     So, by that form divine, was giv\'n to me\nSweet medicine to clear and strengthen sight,\nAnd, as one handling skillfully the harp,\nAttendant on some skilful songster\'s voice\nBids the chords vibrate, and therein the song\nAcquires more pleasure; so, the whilst it spake,\nIt doth remember me, that I beheld\nThe pair of blessed luminaries move.\nLike the accordant twinkling of two eyes,\nTheir beamy circlets, dancing to the sounds.\n\n\n\nCANTO XXI\n\nAgain mine eyes were fix\'d on Beatrice,\nAnd with mine eyes my soul, that in her looks\nFound all contentment.  Yet no smile she wore\nAnd, \"Did I smile,\" quoth she, \"thou wouldst be straight\nLike Semele when into ashes turn\'d:\nFor, mounting these eternal palace-stairs,\nMy beauty, which the loftier it climbs,\nAs thou hast noted, still doth kindle more,\nSo shines, that, were no temp\'ring interpos\'d,\nThy mortal puissance would from its rays");strcat(expected_filecontent1, "mayst see, he was a king, who ask\'d\nFor wisdom, to the end he might be king\nSufficient: not the number to search out\nOf the celestial movers; or to know,\nIf necessary with contingent e\'er\nHave made necessity; or whether that\nBe granted, that first motion is; or if\nOf the mid circle can, by art, be made\nTriangle with each corner, blunt or sharp.\n     \"Whence, noting that, which I have said, and this,\nThou kingly prudence and that ken mayst learn,\nAt which the dart of my intention aims.\nAnd, marking clearly, that I told thee, \'Risen,\'\nThou shalt discern it only hath respect\nTo kings, of whom are many, and the good\nAre rare.  With this distinction take my words;\nAnd they may well consist with that which thou\nOf the first human father dost believe,\nAnd of our well-beloved.  And let this\nHenceforth be led unto thy feet, to make\nThee slow in motion, as a weary man,\nBoth to the \'yea\' and to the \'nay\' thou seest not.\nFor he among the fools is down full low,\nWhose affirmation, or denial, is\nWithout distinction, in each case alike\nSince it befalls, that in most instances\nCurrent opinion leads to false: and then\nAffection bends the judgment to her ply.\n     \"Much more than vainly doth he loose from shore,\nSince he returns not such as he set forth,\nWho fishes for the truth and wanteth skill.\nAnd open proofs of this unto the world\nHave been afforded in Parmenides,\nMelissus, Bryso, and the crowd beside,\nWho journey\'d on, and knew not whither: so did\nSabellius, Arius, and the other fools,\nWho, like to scymitars, reflected back\nThe scripture-image, by distortion marr\'d.\n     \"Let not the people be too swift to judge,\nAs one who reckons on the blades in field,\nOr ere the crop be ripe.  For I have seen\nThe thorn frown rudely all the winter long\nAnd after bear the rose upon its top;\nAnd bark, that all the way across the sea\nRan straight and speedy, perish at the last,\nE\'en in the haven\'s mouth seeing one steal,\nAnother brine, his offering to the priest,\nLet not Dame Birtha and Sir Martin thence\nInto heav\'n\'s counsels deem that they can pry:\nFor one of these may rise, the other fall.\"\n\n\n\nCANTO XIV\n\nFrom centre to the circle, and so back\nFrom circle to the centre, water moves\nIn the round chalice, even as the blow\nImpels it, inwardly, or from without.\nSuch was the image glanc\'d into my mind,\nAs the great spirit of Aquinum ceas\'d;\nAnd Beatrice after him her words\nResum\'d alternate:  \"Need there is (tho\' yet\nHe tells it to you not in words, nor e\'en\nIn thought) that he should fathom to its depth\nAnother mystery.  Tell him, if the light,\nWherewith your substance blooms, shall stay with you\nEternally, as now: and, if it doth,\nHow, when ye shall regain your visible forms,\nThe sight may without harm endure the change,\nThat also tell.\"  As those, who in a ring\nTread the light measure, in their fitful mirth\nRaise loud the voice, and spring with gladder bound;\nThus, at the hearing of that pious suit,\nThe saintly circles in their tourneying\nAnd wond\'rous note attested new delight.\n     Whoso laments, that we must doff this garb\nOf frail mortality, thenceforth to live\nImmortally above, he hath not seen\nThe sweet refreshing, of that heav\'nly shower.\n     Him, who lives ever, and for ever reigns\nIn mystic union of the Three in One,\nUnbounded, bounding all, each spirit thrice\nSang, with such melody, as but to hear\nFor highest merit were an");strcat(expected_filecontent2, "monte was engaged to marry a lady of the\nAmidei family, but broke his promise and united himself to one of\nthe Donati.  This was so much resented by the former, that a\nmeeting of themselves and their kinsmen was held, to consider of\nthe best means of revenging the insult.  Mosca degli Uberti\npersuaded them to resolve on the assassination of Buondelmonte,\nexclaiming to them  \"the thing once done, there is an end.\"  The\ncounsel and its effects were the source of many terrible\ncalamities to the state of Florence.  \"This murder,\" says G.\nVillani, l. v. c. 38,  \"was the cause and beginning of the\naccursed Guelph and Ghibelline parties in Florence.\"  It happened\nin 1215.  See the Paradise, Canto XVI. 139.\n\nv. 111.  The boon companion.]\n        What stronger breastplate than a heart untainted?\nShakespeare, 2 Hen. VI. a. iii. s. 2.\n\nv. 160.  Bertrand.]  Bertrand de Born, Vicomte de Hautefort, near\nPerigueux in Guienne, who incited John to rebel against his\nfather, Henry II. of England.  Bertrand holds a distinguished\nplace among the Provencal poets.  He is quoted in Dante, \"De\nVulg. Eloq.\" l. ii. c. 2.  For the translation of some extracts\nfrom his poems, see Millot, Hist. Litteraire des Troubadors t. i.\np. 210; but the historical parts of that work are, I believe, not\nto be relied on.\n\nCANTO XXIX.\n\nv. 26.  Geri of Bello.]  A kinsman of the Poet\'s, who was\nmurdered by one of the Sacchetti family.  His being placed here,\nmay be considered as a proof that Dante was more impartial in the\nallotment of his punishments than has generally been supposed.\n\nv. 44.  As were the torment.]  It is very probable that these\nlines gave Milton the idea of his celebrated description:\n               Immediately a place\n        Before their eyes appear\'d, sad, noisome, dark,\n        A lasar-house it seem\'d, wherein were laid\n        Numbers of all diseas\'d, all maladies, &c.\n               P. L. b. xi. 477.\n\nv. 45.  Valdichiana.]  The valley through which passes the river\nChiana, bounded by Arezzo, Cortona, Montepulciano, and Chiusi. In\nthe heat of autumn it was formerly rendered unwholesome by the\nstagnation of the water, but has since been drained by the\nEmperor Leopold II.  The Chiana is mentioned as a remarkably\nsluggish stream, in the Paradise, Canto XIII. 21.\n\nv. 47.  Maremma\'s pestilent fen.]  See Note to Canto XXV. v. 18.\n\nv. 58.  In Aegina.] He alludes to the fable of the ants changed\ninto Myrmidons. Ovid, Met. 1. vii.\n\nv. 104.  Arezzo was my dwelling.]  Grifolino of Arezzo, who\npromised Albero, son of the Bishop of Sienna, that he would teach\nhim the art of flying; and because be did not keep his promise,\nAlbero prevailed on his father to have him burnt for a\nnecromancer.\n\nv. 117.\n               Was ever race\n        Light as Sienna\'s?]\nThe same imputation is again cast on the Siennese, Purg. Canto\nXIII. 141.\n\nv. 121.  Stricca.] This is said ironically.  Stricca, Niccolo\nSalimbeni, Caccia of Asciano, and Abbagliato, or Meo de\nFolcacchieri, belonged to a company of prodigal and luxurious\nyoung men in Sienna, called the \"brigata godereccia.\"  Niccolo\nwas the inventor of a new manner of using cloves in cookery, not\nvery well understood by the commentators, and which was termed\nthe  \"costuma ricca.\"\n\nv. 125.  In that garden.]  Sienna.\n\nv. 134.  Cappocchio\'s ghost.] Capocchio of Sienna, who is said to\nhave been a fellow-student of Dante\'s in natural philosophy.\n\nCANTO XXX.\n\nv. 4.  Athamas.]  From Ovid, Metam. 1. iv.\n        Protinos Aelides, &c.\n\nv. 16.  Hecuba. See Euripedes, Hecuba; and Ovid, Metnm. l. xiii.\n\nv. 33.  Schicchi.]  Gianni Schicci, who was of the family of\nCavalcanti, possessed such a faculty of moulding his features to\nthe resemblance of others, that he was employed by Simon Donati\nto personate Buoso Donati, then recently deceased, and to make a\nwill, leaving Simon his heir; for which service he was\nrenumerated with a mare of extraordinary value, here called \"the\nlady of the herd.\"\n\nv. 39.  Myrrha.] See Ovid, Metam. l. x.\n\nv. 60. Adamo\'s woe.]  Adamo of Breschia, at the instigation of\nCuido Alessandro, and their brother Aghinul");
    strcat(expected_filecontent2, "fo, lords of Romena,\ncoonterfeited the coin of Florence; for which crim");strcat(expected_filecontent3, "must perforce decline to worse, unaw\'d\nBy fear of other.  If thou doubt me, mark\nThe blade: each herb is judg\'d of by its seed.\nThat land, through which Adice and the Po\nTheir waters roll, was once the residence\nOf courtesy and velour, ere the day,\nThat frown\'d on Frederick; now secure may pass\nThose limits, whosoe\'er hath left, for shame,\nTo talk with good men, or come near their haunts.\nThree aged ones are still found there, in whom\nThe old time chides the new: these deem it long\nEre God restore them to a better world:\nThe good Gherardo, of Palazzo he\nConrad, and Guido of Castello, nam\'d\nIn Gallic phrase more fitly the plain Lombard.\nOn this at last conclude.  The church of Rome,\nMixing two governments that ill assort,\nHath miss\'d her footing, fall\'n into the mire,\nAnd there herself and burden much defil\'d.\"\n     \"O Marco!\" I replied, shine arguments\nConvince me");strcat(expected_filecontent4, "heaven.\n\nv. 67.  Hope.]  This is from the Sentences of Petrus Lombardus.\n\"Est autem spes virtus, qua spiritualia et aeterna bona speratam,\nid  est, beatitudinem aeternam.  Sine meritis enim aliquid\nsperare non spes, sed praesumptio, dici potest.\"  Pet. Lomb.\nSent.  1.  Iii.  Dist.  26.   Ed. Bas.  1486.  Fol.\n\nv. 74.  His anthem.]  Psalm ix.  10.\n\nv. 90.  Isaias ]  Chap. lxi. 10.\n\nv. 94.  Thy brother.]  St. John in the Revelation, c. vii.  9.\n\nv. 101.  Winter\'s month.]  \"If a luminary, like that which now\nappeared, were to shine throughout the month following the winter\nsolstice during which the constellation Cancer appears in the\neast at the setting of the sun, there would be no interruption to\nthe light, but the whole month would be as a single day.\"\n\nv. 112.  This.]  St. John, who reclined on the bosom of our\nSaviour, and to whose charge Jesus recommended his mother.\n\nv. 121.  So I.]  He looked so earnestly, to descry whether St.\nJohn were present there in body, or in spirit only, having had\nhis doubts raised  by that saying of our Saviour\'s:  \"If I will,\nthat he tarry till I come  what is that to thee.\"\n\nv. 127.  The two.]  Christ and Mary, whom he has described, in\nthe last Canto but one, as rising above his sight\n\nCANTO XXVI\n\nv. 2.  The beamy flame.]  St. John.\n\nv. 13.  Ananias\' hand.]  Who, by putting his hand on St. Paul,\nrestored his sight.  Acts, c. ix.  17.\n\nv. 36.  From him.]  Some suppose that Plato is here meant, who,\nin his Banquet, makes Phaedrus say:  \"Love is confessedly amongst\nthe eldest of beings, and, being the eldest, is the cause to us\nof the greatest goods \" Plat. Op. t. x. p. 177.  Bip.  ed. Others\nhave understood it of Aristotle, and others, of the writer who\ngoes by the name of Dionysius the Areopagite, referred to in the\ntwenty-eighth Canto.\n\nv. 40.  I will make.]  Exodus, c. xxxiii. 19.\n\nv. 42.  At the outset.]  John, c. i. 1.  &c.\n\nv. 51.  The eagle of our Lord.]  St. John\n\nv. 62.  The leaves.]  Created beings.\n\nv. 82.  The first living soul.]  Adam.\n\nv. 107.  Parhelion.]  Who enlightens and comprehends all things;\nbut is himself enlightened and comprehended by none.\n\nv. 117.  Whence.]  That is, from Limbo.  See Hell, Canto II.  53.\nAdam says that 5232 years elapsed from his creation to the time\nof his deliverance, which followed the death of Christ.\n\nv. 133.  EL]  Some read UN, \"One,\" instead of EL:  but the latter\nof these readings is confirmed by a passage from Dante\'s Treatise\nDe Vulg. Eloq. 1. i. cap. 4. \"Quod prius vox primi loquentis\nsonaverit, viro sanae mentis in promptu esse non dubito ipsum\nfuisse quod Deus est, videlicet El.\"  St. Isidore in the\nOrigines, 1.  vii. c. 1. had said, \"Primum apud Hebraeos Dei\nnomen El dicitur.\"\n\nv. 135.  Use.]  From Horace, Ars. Poet. 62.\n\nv. 138.  All my life.]  \"I remained in the terrestrial Paradise\nonly tothe seventh hour.\"  In the Historia Scolastica of Petrus\nComestor, it is said of our first parents:  Quidam tradunt eos\nfuisse in Paradiso septem horae.\"  I. 9. ed. Par. 1513. 4to.\n\nCANTO XXVII\n\nv.  1.  Four torches.]  St. Peter, St. James, St. John, and Adam.\n\nv. 11.  That.]  St. Peter\' who looked as the planet Jupiter\nwould, if it assumed the sanguine appearance of liars.\n\nv. 20.  He.]  Boniface VIII.\n\nv. 26.  such colour.]\nQui color infectis adversi solis ab ietu\nNubibus esse solet; aut purpureae Aurorae.\nOvid, Met.  1. iii. 184.\n\nv. 37.  Of Linus and of Cletus.]  Bishops of Rome in the first\ncentury.\n\nv. 40.  Did Sextus, Pius, and Callixtus bleed\nAnd Urban.]\nThe former two, bishops of the same see, in the second; and the\nothers, in the fourth century.\nv. 42.  No purpose was of ours.]  \"We did not intend that our\nsuccessors should take any part in the political divisions among\nChristians, or that my figure (the seal of St. Peter) should\nserve as a mark to authorize iniquitous grants and privileges.\"\n\nv. 51.  Wolves.]  Compare Milton, P. L. b. xii. 508, &c.\n\nv. 53.  Cahorsines and Gascons.]  He alludes to Jacques d\'Ossa, a\nnative of Cahors, who filled the papal chair in 1316, after it\nhad been two years vacant, and assumed the name of John X");
    strcat(expected_filecontent4, "XII.,\nand to Clement V, a Gascon, of whom see Hell, Canto XIX. 86, and\nNote.\n\nv. 63.  The she-goat.]  When the sun is in Capricorn.\n\nv. 72.  From the hour.]  Since he had last looked (see Canto\nXXII.) he perceived that he had passed from the meridian circle\nto the eastern horizon, the half of our hemisphere, and a quarter\nof the heaven.\n\nv. 76.  From Gades.]  See Hell, Canto XXVI. 106\n\nv. 78.  The shore.]  Phoenicia, where Europa, the daughter of\nAgenor mounted on the back of Jupiter, in his shape of a bull.\n\nv. 80.  The sun.]  Dante was in the constellation Gemini, and the\nsun  in Aries.  There was, therefore, part of those two\nconstellations, and the whole of Taurus, between them.\n\nv. 93.  The fair nest of Leda.]  \"From the Gemini;\" thus called,\nbecause Leda was the mother of the twins, Castor and Pollux\n\nv. 112.  Time\'s roots.]  \"Here,\" says Beatrice, \"are the roots,\nfrom whence time springs: for the parts, into which it is\ndivided, the other heavens must be considered.\"  And she then\nbreaks out into an exc");strcat(expected_filecontent5, "wood.  But lo!  of those\nWho call \'Christ, Christ,\' there shall be many found,\n In judgment, further off from him by far,\nThan such, to whom his name was never known.\nChristians like these the Ethiop shall condemn:\nWhen that the two assemblages shall part;\nOne rich eternally, the other poor.\n     \"What may the Persians say unto your kings,\nWhen they shall see that volume, in the which\nAll their dispraise is written, spread to view?\nThere amidst Albert\'s works shall that be read,\nWhich will give speedy motion to the pen,\nWhen Prague shall mourn her desolated realm.\nThere shall be read the woe, that he doth work\nWith his adulterate money on the Seine,\nWho by the tusk will perish: there be read\nThe thirsting pride, that maketh fool alike\nThe English and Scot, impatient of their bound.\nThere shall be seen the Spaniard\'s luxury,\nThe delicate living there of the Bohemian,\nWho still to worth has been a willing stranger.\nThe halter of Jerusalem shall see\nA unit for his virtue, for his vices\nNo less a mark than million.  He, who guards\nThe isle of fire by old Anchises honour\'d\nShall find his avarice there and cowardice;\nAnd better to denote his littleness,\nThe writing must be letters maim\'d, that speak\nMuch in a narrow space.  All there shall know\nHis uncle and his brother\'s filthy doings,\nWho so renown\'d a nation and two crowns\nHave bastardized.  And they, of Portugal\nAnd Norway, there shall be expos\'d with him\nOf Ratza, who hath counterfeited ill\nThe coin of Venice.  O blest Hungary!\nIf thou no longer patiently abid\'st\nThy ill-entreating!  and, O blest Navarre!\nIf with thy mountainous girdle thou wouldst arm thee\nIn earnest of that day, e\'en now are heard\nWailings and groans in Famagosta\'s streets\nAnd Nicosia\'s, grudging at their beast,\nWho keepeth even footing with the rest.\"\n\n\n\nCANTO XX\n\nWhen, disappearing, from our hemisphere,\nThe world\'s enlightener vanishes, and day\nOn all sides wasteth, suddenly the sky,\nErewhile irradiate only with his beam,\nIs yet again unfolded, putting forth\nInnumerable lights wherein one shines.\nOf such vicissitude in heaven I thought,\nAs the great sign, that marshaleth the world\nAnd the world\'s leaders, in the blessed beak\nWas silent; for that all those living lights,\nWaxing in splendour, burst forth into songs,\nSuch as from memory glide and fall away.\n     Sweet love!  that dost apparel thee in smiles,\nHow lustrous was thy semblance in those sparkles,\nWhich merely are from holy thoughts inspir\'d!\n     After the precious and bright beaming stones,\nThat did ingem the sixth light, ceas\'d the chiming\nOf their angelic bells; methought I heard\nThe murmuring of a river, that doth fall\nFrom rock to rock transpicuous, making known\nThe richness of his spring-head: and as sound\nOf cistern, at the fret-board, or of pipe,\nIs, at the wind-hole, modulate and tun\'d;\nThus up the neck, as it were hollow, rose\nThat murmuring of the eagle, and forthwith\nVoice there assum\'d, and thence along the beak\nIssued in form of words, such as my heart\nDid look for, on whose tables I inscrib\'d them.\n     \"The part in me, that sees, and bears the sun,,\nIn mortal eagles,\" it began, \"must now\nBe noted steadfastly: for of the fires,\nThat figure me, those, glittering in mine eye,\nAre chief of all the greatest.  This, that shines\nMidmost for pupil, was the same, who sang\nThe Holy Spirit\'s song, and bare about\nThe ark from town to town; now doth he know\nThe merit of his soul-impassion\'d strains\nBy their well-fitted guerdon.  Of the five,\nThat make the circle ");strcat(expected_filecontent6, "\n\"What dost thou in this deep?  Go now and know,\nSince yet thou livest, that my neighbour here\nVitaliano on my left shall sit.\nA Paduan with these Florentines am I.\nOfttimes they thunder in mine ears, exclaiming\n\"O haste that noble knight! he who the pouch\nWith the three beaks will bring!\"  This said, he writh\'d\nThe mouth, and loll\'d the tongue out, like an ox\nThat licks his nostrils.  I, lest longer stay\nHe ill might brook, who bade me stay not long,\nBackward my steps from those sad spirits turn\'d.\n     My guide already seated on the haunch\nOf the fierce animal I found; and thus\nHe me encourag\'d.  \"Be thou stout; be bold.\nDown such a steep flight must we now descend!\nMount thou before:  for that no power the tail\nMay have to harm thee, I will be i\' th\' midst.\"\n     As one, who hath an ague fit so near,\nHis nails already are turn\'d blue, and he\nQuivers all o\'er, if he but eye the shade;\nSuch was my cheer at hearing of his words.\nBut shame soon interpos\'d her threat, who makes\nThe servant bold in presence of his lord.\n     I settled me upon those shoulders huge,\nAnd would have said, but that the words to aid\nMy purpose came not, \"Look thou clasp me firm!\"\n     But he whose succour then not first I prov\'d,\nSoon as I mounted, in his arms aloft,\nEmbracing, held me up, and thus he spake:\n\"Geryon! now move thee! be thy wheeling gyres\nOf ample circuit, easy thy descent.\nThink on th\' unusual burden thou sustain\'st.\"\n     As a small vessel, back\'ning out from land,\nHer station quits; so thence the monster loos\'d,\nAnd when he felt himself at large, turn\'d round\nThere where the breast had been, his forked tail.\nThus, like an eel, outstretch\'d at length he steer\'d,\nGath\'ring the air up with retractile claws.\n     Not greater was the dread when Phaeton\nThe reins let drop at random, whence high heaven,\nWhereof signs yet appear, was wrapt in flames;\nNor when ill-fated Icarus perceiv\'d,\nBy liquefaction of the scalded wax,\nThe trusted pennons loosen\'d from his loins,\nHis sire exclaiming loud, \"Ill way thou keep\'st!\"\nThan was my dread, when round me on each part\nThe air I view\'d, and other object none\nSave the fell beast.  He slowly sailing, wheels\nHis downward motion, unobserv\'d of me,\nBut that the wind, arising to my face,\nBreathes on me from below.  Now on our right\nI heard the cataract beneath us leap\nWith hideous crash; whence bending down to\' explore,\nNew terror I conceiv\'d at the steep plunge:\nFor flames I saw, and wailings smote mine ear:\nSo that all trembling close I crouch\'d my limbs,\nAnd then distinguish\'d, unperceiv\'d before,\nBy the dread torments that on every side\nDrew nearer, how our downward course we wound.\n     As falcon, that hath long been on the wing,\nBut lure nor bird hath seen, while in despair\nThe falconer cries, \"Ah me! thou stoop\'st to earth!\"\nWearied descends, and swiftly down the sky\nIn many an orbit wheels, then lighting sits\nAt distance from his lord in angry mood;\nSo Geryon lighting places us on foot\nLow down at base of the deep-furrow\'d rock,\nAnd, of his burden there discharg\'d, forthwith\nSprang forward, like an arrow from the string.\n\n\n\nCANTO XVIII\n\nTHERE is a place within the depths of hell\nCall\'d Malebolge, all of rock dark-stain\'d\nWith hue ferruginous, e\'en as the steep\nThat round it circling winds.  Right in the midst\nOf that abominable region, yawns\nA spacious gulf profound, whereof the frame\nDue time shall tell.  The circle, that remains,\nThroughout its round, between the gulf and base\nOf the high craggy banks, successive forms\nTen trenches, in its hollow bottom sunk.\n     As where to guard the walls, full many a foss\nBegirds some stately castle, sure defence\nAffording to the space within, so here\nWere model\'d these; and as like fortresses\nE\'en from their threshold to the brink without,\nAre flank\'d with bridges; from the rock\'s low base\nThus flinty paths advanc\'d, that \'cross the moles");


            struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            
                    struct file_t* file0 = file_open(volume, "LET.TXT");
                    test_error(file0 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file1 = file_open(volume, "FLOWER.TX");
                    test_error(file1 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file2 = file_open(volume, "BETTER.TX");
                    test_error(file2 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file3 = file_open(volume, "VOICE.TXT");
                    test_error(file3 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file4 = file_open(volume, "TRADE");
                    test_error(file4 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file5 = file_open(volume, "REMEMBER");
                    test_error(file5 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file6 = file_open(volume, "INDICATE.TX");
                    test_error(file6 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
            
                size_t size0 = file_read(filecontent0, 1, 5180, file0);
                test_error(size0 == 5180, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 5180 bajtów, a wczytała %lu", size0);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos0 = mem_find_first_difference(filecontent0, expected_filecontent0, 5180);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos0 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos0, mem_get_byte(filecontent0, diff_pos0), mem_get_byte(expected_filecontent0, diff_pos0));
        
                onerror_compare_memory(expected_filecontent0, filecontent0, 5180);
            
                size_t size1 = file_read(filecontent1, 1, 3366, file1);
                test_error(size1 == 3366, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3366 bajtów, a wczytała %lu", size1);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos1 = mem_find_first_difference(filecontent1, expected_filecontent1, 3366);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos1 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos1, mem_get_byte(filecontent1, diff_pos1), mem_get_byte(expected_filecontent1, diff_pos1));
        
                onerror_compare_memory(expected_filecontent1, filecontent1, 3366);
            
                size_t size2 = file_read(filecontent2, 1, 4166, file2);
                test_error(size2 == 4166, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 4166 bajtów, a wczytała %lu", size2);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos2 = mem_find_first_difference(filecontent2, expected_filecontent2, 4166);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos2 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos2, mem_get_byte(filecontent2, diff_pos2), mem_get_byte(expected_filecontent2, diff_pos2));
        
                onerror_compare_memory(expected_filecontent2, filecontent2, 4166);
            
                size_t size3 = file_read(filecontent3, 1, 876, file3);
                test_error(size3 == 876, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 876 bajtów, a wczytała %lu", size3);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos3 = mem_find_first_difference(filecontent3, expected_filecontent3, 876);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos3 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos3, mem_get_byte(filecontent3, diff_pos3), mem_get_byte(expected_filecontent3, diff_pos3));
        
                onerror_compare_memory(expected_filecontent3, filecontent3, 876);
            
                size_t size4 = file_read(filecontent4, 1, 5120, file4);
                test_error(size4 == 5120, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 5120 bajtów, a wczytała %lu", size4);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos4 = mem_find_first_difference(filecontent4, expected_filecontent4, 5120);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos4 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos4, mem_get_byte(filecontent4, diff_pos4), mem_get_byte(expected_filecontent4, diff_pos4));
        
                onerror_compare_memory(expected_filecontent4, filecontent4, 5120);
            
                size_t size5 = file_read(filecontent5, 1, 3507, file5);
                test_error(size5 == 3507, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3507 bajtów, a wczytała %lu", size5);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos5 = mem_find_first_difference(filecontent5, expected_filecontent5, 3507);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos5 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos5, mem_get_byte(filecontent5, diff_pos5), mem_get_byte(expected_filecontent5, diff_pos5));
        
                onerror_compare_memory(expected_filecontent5, filecontent5, 3507);
            
                size_t size6 = file_read(filecontent6, 1, 3877, file6);
                test_error(size6 == 3877, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3877 bajtów, a wczytała %lu", size6);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos6 = mem_find_first_difference(filecontent6, expected_filecontent6, 3877);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos6 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos6, mem_get_byte(filecontent6, diff_pos6), mem_get_byte(expected_filecontent6, diff_pos6));
        
                onerror_compare_memory(expected_filecontent6, filecontent6, 3877);
            

            free(filecontent0);
    free(filecontent1);
    free(filecontent2);
    free(filecontent3);
    free(filecontent4);
    free(filecontent5);
    free(filecontent6);

            file_close(file0);
    file_close(file1);
    file_close(file2);
    file_close(file3);
    file_close(file4);
    file_close(file5);
    file_close(file6);


            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 29: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST29(void)
{
    // informacje o teście
    test_start(29, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(5180, 1);
            char expected_filecontent[5181] = "";

            strcat(expected_filecontent, "or of the fires,\nThat figure me, those, glittering in mine eye,\nAre chief of all the greatest.  This, that shines\nMidmost for pupil, was the same, who sang\nThe Holy Spirit\'s song, and bare about\nThe ark from town to town; now doth he know\nThe merit of his soul-impassion\'d strains\nBy their well-fitted guerdon.  Of the five,\nThat make the circle of the vision, he\nWho to the beak is nearest, comforted\nThe widow for her son: now doth he know\nHow dear he costeth not to follow Christ,\nBoth from experience of this pleasant life,\nAnd of its opposite.  He next, who follows\nIn the circumference, for the over arch,\nBy true repenting slack\'d the pace of death:\nNow knoweth he, that the degrees of heav\'n\nAlter not, when through pious prayer below\nToday\'s is made tomorrow\'s destiny.\nThe other following, with the laws and me,\nTo yield the shepherd room, pass\'d o\'er to Greece,\nFrom good intent producing evil fruit:\nNow knoweth he, how all the ill, deriv\'d\nFrom his well doing, doth not helm him aught,\nThough it have brought destruction on the world.\nThat, which thou seest in the under bow,\nWas William, whom that land bewails, which weeps\nFor Charles and Frederick living: now he knows\nHow well is lov\'d in heav\'n the righteous king,\nWhich he betokens by his radiant seeming.\nWho in the erring world beneath would deem,\nThat Trojan Ripheus in this round was set\nFifth of the saintly splendours?  now he knows\nEnough of that, which the world cannot see,\nThe grace divine, albeit e\'en his sight\nReach not its utmost depth.\"  Like to the lark,\nThat warbling in the air expatiates long,\nThen, trilling out his last sweet melody,\nDrops satiate with the sweetness; such appear\'d\nThat image stampt by the\' everlasting pleasure,\nWhich fashions like itself all lovely things.\n     I, though my doubting were as manifest,\nAs is through glass the hue that mantles it,\nIn silence waited not: for to my lips\n\"What things are these?\"  involuntary rush\'d,\nAnd forc\'d a passage out: whereat I mark\'d\nA sudden lightening and new revelry.\nThe eye was kindled: and the blessed sign\nNo more to keep me wond\'ring and suspense,\nReplied:  \"I see that thou believ\'st these things,\nBecause I tell them, but discern\'st not how;\nSo that thy knowledge waits not on thy faith:\nAs one who knows the name of thing by rote,\nBut is a stranger to its properties,\nTill other\'s tongue reveal them.  Fervent love\nAnd lively hope with violence assail\nThe kingdom of the heavens, and overcome\nThe will of the Most high; not in such sort\nAs man prevails o\'er man; but conquers it,\nBecause \'t is willing to be conquer\'d, still,\nThough conquer\'d, by its mercy conquering.\n     \"Those, in the eye who live the first and fifth,\nCause thee to marvel, in that thou behold\'st\nThe region of the angels deck\'d with them.\nThey quitted not their bodies, as thou deem\'st,\nGentiles but Christians, in firm rooted faith,\nThis of the feet in future to be pierc\'d,\nThat of feet nail\'d already to the cross.\nOne from the barrier of the dark abyss,\nWhere never any with good will returns,\nCame back unto his bones.  Of lively hope\nSuch was the meed; of lively hope, that wing\'d\nThe prayers sent up to God for his release,\nAnd put power into them to bend his will.\nThe glorious Spirit, of whom I speak to thee,\nA little while returning to the flesh,\nBeliev\'d in him, who had the means to help,\nAnd, in believing, nourish\'d such a flame\nOf holy love, that at the second death\nHe was made sharer in our gamesome mirth.\nThe other, through the riches of that grace,\nWhich from so deep a fountain doth distil,\nAs never eye created saw its rising,\nPlac\'d all his love below on just and right:\nWherefore of grace God op\'d in him the eye\nTo the redemption of mankind to come;\nWherein believing, he endur\'d no more\nThe filth of paganism, and for their ways\nRebuk\'d the stubborn nations.  The three nymphs,\nWhom at the right wheel thou beheldst advancing,\nWere sponsors for him more than thousand years\nBefore baptizing.  O how far remov\'d,\nPredestination!  is thy root from such\nAs see not the First cause entire: and ye,\nO mortal men!  be wary how ye judge:\nFor w");
    strcat(expected_filecontent, "e, who see our Maker, know not yet\nThe number of the chosen: and esteem\nSuch scantiness of knowledge our delight:\nFor all our good is in that primal good\nConcentrate, and God\'s will and ours are one.\"\n     So, by that form divine, was giv\'n to me\nSweet medicine to clear and strengthen sight,\nAnd, as one handling skillfully the harp,\nAttendant on some skilful songster\'s voice\nBids the chords vibrate, and therein the song\nAcquires more pleasure; so, the whilst it spake,\nIt doth remember me, that I beheld\nThe pair of blessed luminaries move.\nLike the accordant twinkling of two eyes,\nTheir beamy circlets, dancing to the sounds.\n\n\n\nCANTO XXI\n\nAgain mine eyes were fix\'d on Beatrice,\nAnd with mine eyes my soul, that in her looks\nFound all contentment.  Yet no smile she wore\nAnd, \"Did I smile,\" quoth she, \"thou wouldst be straight\nLike Semele when into ashes turn\'d:\nFor, mounting these eternal palace-stairs,\nMy beauty, which the loftier it climbs,\nAs thou hast noted, still doth kindle more,\nSo shines, that, were no temp\'ring interpos\'d,\nThy mortal puissance would from its rays");

            struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "LET.TXT");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 1349, SEEK_SET);
        
            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[1349] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[1349], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 30: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST30(void)
{
    // informacje o teście
    test_start(30, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(3366, 1);
            char expected_filecontent[3367] = "";

            strcat(expected_filecontent, "mayst see, he was a king, who ask\'d\nFor wisdom, to the end he might be king\nSufficient: not the number to search out\nOf the celestial movers; or to know,\nIf necessary with contingent e\'er\nHave made necessity; or whether that\nBe granted, that first motion is; or if\nOf the mid circle can, by art, be made\nTriangle with each corner, blunt or sharp.\n     \"Whence, noting that, which I have said, and this,\nThou kingly prudence and that ken mayst learn,\nAt which the dart of my intention aims.\nAnd, marking clearly, that I told thee, \'Risen,\'\nThou shalt discern it only hath respect\nTo kings, of whom are many, and the good\nAre rare.  With this distinction take my words;\nAnd they may well consist with that which thou\nOf the first human father dost believe,\nAnd of our well-beloved.  And let this\nHenceforth be led unto thy feet, to make\nThee slow in motion, as a weary man,\nBoth to the \'yea\' and to the \'nay\' thou seest not.\nFor he among the fools is down full low,\nWhose affirmation, or denial, is\nWithout distinction, in each case alike\nSince it befalls, that in most instances\nCurrent opinion leads to false: and then\nAffection bends the judgment to her ply.\n     \"Much more than vainly doth he loose from shore,\nSince he returns not such as he set forth,\nWho fishes for the truth and wanteth skill.\nAnd open proofs of this unto the world\nHave been afforded in Parmenides,\nMelissus, Bryso, and the crowd beside,\nWho journey\'d on, and knew not whither: so did\nSabellius, Arius, and the other fools,\nWho, like to scymitars, reflected back\nThe scripture-image, by distortion marr\'d.\n     \"Let not the people be too swift to judge,\nAs one who reckons on the blades in field,\nOr ere the crop be ripe.  For I have seen\nThe thorn frown rudely all the winter long\nAnd after bear the rose upon its top;\nAnd bark, that all the way across the sea\nRan straight and speedy, perish at the last,\nE\'en in the haven\'s mouth seeing one steal,\nAnother brine, his offering to the priest,\nLet not Dame Birtha and Sir Martin thence\nInto heav\'n\'s counsels deem that they can pry:\nFor one of these may rise, the other fall.\"\n\n\n\nCANTO XIV\n\nFrom centre to the circle, and so back\nFrom circle to the centre, water moves\nIn the round chalice, even as the blow\nImpels it, inwardly, or from without.\nSuch was the image glanc\'d into my mind,\nAs the great spirit of Aquinum ceas\'d;\nAnd Beatrice after him her words\nResum\'d alternate:  \"Need there is (tho\' yet\nHe tells it to you not in words, nor e\'en\nIn thought) that he should fathom to its depth\nAnother mystery.  Tell him, if the light,\nWherewith your substance blooms, shall stay with you\nEternally, as now: and, if it doth,\nHow, when ye shall regain your visible forms,\nThe sight may without harm endure the change,\nThat also tell.\"  As those, who in a ring\nTread the light measure, in their fitful mirth\nRaise loud the voice, and spring with gladder bound;\nThus, at the hearing of that pious suit,\nThe saintly circles in their tourneying\nAnd wond\'rous note attested new delight.\n     Whoso laments, that we must doff this garb\nOf frail mortality, thenceforth to live\nImmortally above, he hath not seen\nThe sweet refreshing, of that heav\'nly shower.\n     Him, who lives ever, and for ever reigns\nIn mystic union of the Three in One,\nUnbounded, bounding all, each spirit thrice\nSang, with such melody, as but to hear\nFor highest merit were an");

            struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "FLOWER.TX");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, -2519, SEEK_END);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[847] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[847], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 31: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST31(void)
{
    // informacje o teście
    test_start(31, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(3507, 1);
            char expected_filecontent[3508] = "";

            strcat(expected_filecontent, "wood.  But lo!  of those\nWho call \'Christ, Christ,\' there shall be many found,\n In judgment, further off from him by far,\nThan such, to whom his name was never known.\nChristians like these the Ethiop shall condemn:\nWhen that the two assemblages shall part;\nOne rich eternally, the other poor.\n     \"What may the Persians say unto your kings,\nWhen they shall see that volume, in the which\nAll their dispraise is written, spread to view?\nThere amidst Albert\'s works shall that be read,\nWhich will give speedy motion to the pen,\nWhen Prague shall mourn her desolated realm.\nThere shall be read the woe, that he doth work\nWith his adulterate money on the Seine,\nWho by the tusk will perish: there be read\nThe thirsting pride, that maketh fool alike\nThe English and Scot, impatient of their bound.\nThere shall be seen the Spaniard\'s luxury,\nThe delicate living there of the Bohemian,\nWho still to worth has been a willing stranger.\nThe halter of Jerusalem shall see\nA unit for his virtue, for his vices\nNo less a mark than million.  He, who guards\nThe isle of fire by old Anchises honour\'d\nShall find his avarice there and cowardice;\nAnd better to denote his littleness,\nThe writing must be letters maim\'d, that speak\nMuch in a narrow space.  All there shall know\nHis uncle and his brother\'s filthy doings,\nWho so renown\'d a nation and two crowns\nHave bastardized.  And they, of Portugal\nAnd Norway, there shall be expos\'d with him\nOf Ratza, who hath counterfeited ill\nThe coin of Venice.  O blest Hungary!\nIf thou no longer patiently abid\'st\nThy ill-entreating!  and, O blest Navarre!\nIf with thy mountainous girdle thou wouldst arm thee\nIn earnest of that day, e\'en now are heard\nWailings and groans in Famagosta\'s streets\nAnd Nicosia\'s, grudging at their beast,\nWho keepeth even footing with the rest.\"\n\n\n\nCANTO XX\n\nWhen, disappearing, from our hemisphere,\nThe world\'s enlightener vanishes, and day\nOn all sides wasteth, suddenly the sky,\nErewhile irradiate only with his beam,\nIs yet again unfolded, putting forth\nInnumerable lights wherein one shines.\nOf such vicissitude in heaven I thought,\nAs the great sign, that marshaleth the world\nAnd the world\'s leaders, in the blessed beak\nWas silent; for that all those living lights,\nWaxing in splendour, burst forth into songs,\nSuch as from memory glide and fall away.\n     Sweet love!  that dost apparel thee in smiles,\nHow lustrous was thy semblance in those sparkles,\nWhich merely are from holy thoughts inspir\'d!\n     After the precious and bright beaming stones,\nThat did ingem the sixth light, ceas\'d the chiming\nOf their angelic bells; methought I heard\nThe murmuring of a river, that doth fall\nFrom rock to rock transpicuous, making known\nThe richness of his spring-head: and as sound\nOf cistern, at the fret-board, or of pipe,\nIs, at the wind-hole, modulate and tun\'d;\nThus up the neck, as it were hollow, rose\nThat murmuring of the eagle, and forthwith\nVoice there assum\'d, and thence along the beak\nIssued in form of words, such as my heart\nDid look for, on whose tables I inscrib\'d them.\n     \"The part in me, that sees, and bears the sun,,\nIn mortal eagles,\" it began, \"must now\nBe noted steadfastly: for of the fires,\nThat figure me, those, glittering in mine eye,\nAre chief of all the greatest.  This, that shines\nMidmost for pupil, was the same, who sang\nThe Holy Spirit\'s song, and bare about\nThe ark from town to town; now doth he know\nThe merit of his soul-impassion\'d strains\nBy their well-fitted guerdon.  Of the five,\nThat make the circle ");

            struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "REMEMBER");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 1061, SEEK_SET);
            file_seek(file, 444, SEEK_CUR);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[1505] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[1505], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 32: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST32(void)
{
    // informacje o teście
    test_start(32, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "SOON");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (SOON) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 33: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST33(void)
{
    // informacje o teście
    test_start(33, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "SHORE");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (SHORE) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 34: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST34(void)
{
    // informacje o teście
    test_start(34, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "ROUND");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (ROUND) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 35: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST35(void)
{
    // informacje o teście
    test_start(35, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "THROUGH");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (THROUGH) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 36: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST36(void)
{
    // informacje o teście
    test_start(36, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "MINE");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (MINE) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 37: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST37(void)
{
    // informacje o teście
    test_start(37, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "PLANTLEA");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (PLANTLEA) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 38: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST38(void)
{
    // informacje o teście
    test_start(38, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "IRON.TX");
            test_error(file == NULL, "Funkcja file_open() nie powinna otworzyć pliku o nazwie IRON.TX, ponieważ nie istnieje on w katalogu głównym");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 39: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST39(void)
{
    // informacje o teście
    test_start(39, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(NULL, "IRON.TX");
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 40: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST40(void)
{
    // informacje o teście
    test_start(40, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, NULL);
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 41: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST41(void)
{
    // informacje o teście
    test_start(41, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(NULL, NULL);
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 42: Sprawdzanie poprawności działania funkcji file_close
//
void UTEST42(void)
{
    // informacje o teście
    test_start(42, "Sprawdzanie poprawności działania funkcji file_close", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            file_close(NULL);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 43: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST43(void)
{
    // informacje o teście
    test_start(43, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "LET.TXT");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int res = file_read(NULL, 1, 1, file);
            test_error(res == -1, "Funkcja file_read() powinna zwrócić wartość -1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 44: Sprawdzanie poprawności działania funkcji dir_read
//
void UTEST44(void)
{
    // informacje o teście
    test_start(44, "Sprawdzanie poprawności działania funkcji dir_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char* expected_names[13] = { "LET.TXT", "FLOWER.TX", "BETTER.TX", "VOICE.TXT", "TRADE", "REMEMBER", "INDICATE.TX", "SOON", "SHORE", "ROUND", "THROUGH", "MINE", "PLANTLEA" };
            int found_names[13] = { 0 };

            struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t* pdir = dir_open(volume, "\\");
            test_error(pdir != NULL, "Funkcja dir_open() niepoprawnie otworzyła katalog");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            for (int i = 0; i < 13; ++i)
            {
                struct dir_entry_t entry;
                int res = dir_read(pdir, &entry);
                test_error(res == 0, "Funkcja dir_read() niepoprawnie odczytała wpis z katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int name_found = 0;

                for (int j = 0; j < 13; ++j)
                {
                    if (strcmp(entry.name, expected_names[j]) == 0)
                    {
                        test_error(found_names[j] == 0, "Funkcja dir_read() ponownie zwróciła informację o wpisie %s", expected_names[j]);
                        found_names[j] = 1;
                        name_found = 1;
                        break;
                    }
                }

                test_error(name_found == 1, "Funkcja dir_read() zwróciła informację o wpisie %s, który nie znajduje się w katalogu", entry.name);
            }

            struct dir_entry_t entry;
            int res = dir_read(pdir, &entry);
            test_error(res == 1, "Funkcja dir_read() zwróciła niepoprawną wartość, po odczytaniu wszystkich wpisów z katalogu powinna zwrócić %d, a zwróciła %d", 1, res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            dir_close(pdir);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 45: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST45(void)
{
    // informacje o teście
    test_start(45, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "LET.TXT");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 46: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST46(void)
{
    // informacje o teście
    test_start(46, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "FLOWER.TX");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 47: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST47(void)
{
    // informacje o teście
    test_start(47, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "BETTER.TX");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 48: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST48(void)
{
    // informacje o teście
    test_start(48, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "VOICE.TXT");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 49: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST49(void)
{
    // informacje o teście
    test_start(49, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "TRADE");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 50: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST50(void)
{
    // informacje o teście
    test_start(50, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "REMEMBER");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 51: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST51(void)
{
    // informacje o teście
    test_start(51, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "INDICATE.TX");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 52: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST52(void)
{
    // informacje o teście
    test_start(52, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("she_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t*  dir = dir_open(volume, "spoke");
            test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}




enum run_mode_t { rm_normal_with_rld = 0, rm_unit_test = 1, rm_main_test = 2 };

int __wrap_main(volatile int _argc, char** _argv, char** _envp)
{
    int volatile vargc = _argc;
    char ** volatile vargv = _argv, ** volatile venvp = _envp;
	volatile enum run_mode_t run_mode = rm_unit_test; // -1
	volatile int selected_test = -1;

    if (vargc > 1)
	{
	    char* smode = strtok(vargv[1], ",");
	    char* stest = strtok(NULL, "");
		char *errptr = NULL;
		run_mode = (enum run_mode_t)strtol(smode, &errptr, 10);
		if (*errptr == '\x0')
		{
			memmove(vargv + 1, vargv + 2, sizeof(char*) * (vargc - 1));
			vargc--;

			if (stest != NULL)
			{
			    int val = (int)strtol(stest, &errptr, 10);
			    if (*errptr == '\x0')
			        selected_test = val;
			}
		}
	}

    // printf("runmode=%d; selected_test=%d\n", run_mode, selected_test);

    // inicjuj testy jednostkowe
    unit_test_init(run_mode, "unit_test_v2.c");
    test_limit_init();
    rldebug_set_reported_severity_level(MSL_FAILURE);

    if (run_mode == rm_normal_with_rld)
    {
        // konfiguracja ograniczników
        rldebug_reset_limits();
        

        // uruchom funkcję main Studenta a potem wyświetl podsumowanie sterty i zasobów
        volatile int ret_code = rdebug_call_main(tested_main, vargc, vargv, venvp);

        rldebug_reset_limits();
        

        int leaks_detected = rldebug_show_leaked_resources(0);
        if (leaks_detected)
            raise(SIGHEAP);

        return ret_code;
    }

    
    if (run_mode == rm_unit_test)
    {
        test_title("Testy jednostkowe");

        void (*pfcn[])(void) =
        { 
            UTEST1, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST2, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST3, // Sprawdzanie poprawności działania funkcji disk_close
            UTEST4, // Sprawdzanie poprawności działania funkcji fat_open
            UTEST5, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST6, // Sprawdzanie poprawności działania funkcji file_read
            UTEST7, // Sprawdzanie poprawności działania funkcji file_read
            UTEST8, // Sprawdzanie poprawności działania funkcji file_read
            UTEST9, // Sprawdzanie poprawności działania funkcji file_read
            UTEST10, // Sprawdzanie poprawności działania funkcji file_read
            UTEST11, // Sprawdzanie poprawności działania funkcji file_read
            UTEST12, // Sprawdzanie poprawności działania funkcji file_read
            UTEST13, // Sprawdzanie poprawności działania funkcji file_read
            UTEST14, // Sprawdzanie poprawności działania funkcji file_read
            UTEST15, // Sprawdzanie poprawności działania funkcji file_read
            UTEST16, // Sprawdzanie poprawności działania funkcji file_read
            UTEST17, // Sprawdzanie poprawności działania funkcji file_read
            UTEST18, // Sprawdzanie poprawności działania funkcji file_read
            UTEST19, // Sprawdzanie poprawności działania funkcji file_read
            UTEST20, // Sprawdzanie poprawności działania funkcji file_read
            UTEST21, // Sprawdzanie poprawności działania funkcji file_read
            UTEST22, // Sprawdzanie poprawności działania funkcji file_read
            UTEST23, // Sprawdzanie poprawności działania funkcji file_read
            UTEST24, // Sprawdzanie poprawności działania funkcji file_read
            UTEST25, // Sprawdzanie poprawności działania funkcji file_read
            UTEST26, // Sprawdzanie poprawności działania funkcji file_read
            UTEST27, // Sprawdzanie poprawności działania funkcji file_read
            UTEST28, // Sprawdzanie poprawności działania funkcji file_read
            UTEST29, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST30, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST31, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST32, // Sprawdzanie poprawności działania funkcji file_open
            UTEST33, // Sprawdzanie poprawności działania funkcji file_open
            UTEST34, // Sprawdzanie poprawności działania funkcji file_open
            UTEST35, // Sprawdzanie poprawności działania funkcji file_open
            UTEST36, // Sprawdzanie poprawności działania funkcji file_open
            UTEST37, // Sprawdzanie poprawności działania funkcji file_open
            UTEST38, // Sprawdzanie poprawności działania funkcji file_open
            UTEST39, // Sprawdzanie poprawności działania funkcji file_read
            UTEST40, // Sprawdzanie poprawności działania funkcji file_read
            UTEST41, // Sprawdzanie poprawności działania funkcji file_read
            UTEST42, // Sprawdzanie poprawności działania funkcji file_close
            UTEST43, // Sprawdzanie poprawności działania funkcji file_read
            UTEST44, // Sprawdzanie poprawności działania funkcji dir_read
            UTEST45, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST46, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST47, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST48, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST49, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST50, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST51, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST52, // Sprawdzanie poprawności działania funkcji dir_open
            NULL
        };

        for (int idx = 0; pfcn[idx] != NULL && !test_get_session_termination_flag(); idx++)
        {
            if (selected_test == -1 || selected_test == idx + 1)
                pfcn[idx]();

            // limit niezaliczonych testów, po jakim testy jednostkowe zostaną przerwane
            if (test_session_get_fail_count() >= 1000)
                test_terminate_session();
        }


        test_title("RLDebug :: Analiza wycieku zasobów");
        // sprawdź wycieki pamięci
        int leaks_detected = rldebug_show_leaked_resources(1);
        test_set_session_leaks(leaks_detected);

        // poinformuj serwer Mrówka o wyniku testu - podsumowanie
        test_title("Podsumowanie");
        if (selected_test == -1)
            test_summary(52); // wszystkie testy muszą zakończyć się sukcesem
        else
            test_summary(1); // tylko jeden (selected_test) test musi zakończyć się  sukcesem
        return EXIT_SUCCESS;
    }
    

    if (run_mode == rm_main_test)
    {
        test_title("Testy funkcji main()");

        void (*pfcn[])(int, char**, char**) =
        { 
            NULL
        };

        for (volatile int idx = 0; pfcn[idx] != NULL && !test_get_session_termination_flag(); idx++)
        {
            if (selected_test == -1 || selected_test == idx + 1)
                pfcn[idx](vargc, vargv, venvp);

            // limit niezaliczonych testów, po jakim testy jednostkowe zostaną przerwane
            if (test_session_get_fail_count() >= 1000)
                test_terminate_session();
        }


        test_title("RLDebug :: Analiza wycieku zasobów");
        // sprawdź wycieki pamięci
        int leaks_detected = rldebug_show_leaked_resources(1);
        test_set_session_leaks(leaks_detected);

        // poinformuj serwer Mrówka o wyniku testu - podsumowanie
        test_title("Podsumowanie");
        if (selected_test == -1)
            test_summary(0); // wszystkie testy muszą zakończyć się sukcesem
        else
            test_summary(1); // tylko jeden (selected_test) test musi zakończyć się  sukcesem

        return EXIT_SUCCESS;
    }

    printf("*** Nieznana wartość RunMode: %d", (int)run_mode);
    abort();
}