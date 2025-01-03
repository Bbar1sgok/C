#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

// Sabitler
define TABLO_BOYUTU 8 // Tablo boyutu
define NORMALE 3  // İstediğimiz kadar değiştirebileceğimiz mayın sayısı
define KAZANDI 1   // Oyunu kazandığımızda
define KAYBETTI -1  // Oyunu kaybettiğimizde
define DEVAM 0   // Oyuna devam ettiğimizde

// Global Değişkenler
char tablo[TABLO_BOYUTU+2][TABLO_BOYUTU+2];    // Görünen karakter tablosu
int gizliTablo[TABLO_BOYUTU+2][TABLO_BOYUTU+2];   // Mayınlar ve komşu mayın bilgilerini içeren tablo
int mayin_sayisi, bayrak_sayisi = 0; // Mayın sayısı ve yerleştirilen bayrak sayısı

// Fonksiyonların İsimleri ve Görevleri
void gizli_tablo_olustur();
void tabloyu_baslat();
void tabloyu_goster();
void gizli_tabloyu_goster();
void mayin_yerlestir();
int kazanma_durumu_kontrol();
void komsulari_ac(int satir, int sutun);
int kaz(int satir, int sutun);

int main(void)
{
    int satir, sutun, durum;
    char islem; // Kullanıcıdan alınan işlem ('c', 'd', 'e')

    printf("Mayın Tarlası oyunumuza hoş geldiniz!\n");
    gizli_tablo_olustur();
    tabloyu_baslat();

    do {
        tabloyu_goster();
        printf("\nLütfen şu formatta giriniz: c,satır,sütun veya d,satır,sütun veya e,satır,sütun\n");
        scanf(" %c,%d,%d", &islem, &satir, &sutun);
        printf("\n");

        if (islem == 'c') {
            durum = kaz(satir, sutun);
        } else if (islem == 'd') {
            if (bayrak_sayisi < NORMALE) {
                bayrak_sayisi++;
                tablo[satir][sutun] = 'D';
                durum = kazanma_durumu_kontrol();
            }
        } else if (islem == 'e') {
            if (bayrak_sayisi > 0) {
                bayrak_sayisi--;
                tablo[satir][sutun] = '#';
                durum = kaz(satir, sutun);
            }
        }

        if (durum == KAYBETTI) {
            printf("Oyunu kaybettiniz!\n");
            gizli_tabloyu_goster();
            return 0;
        }

        if (durum == KAZANDI) {
            printf("Tebrikler! Oyunu kazandınız.\n");
            gizli_tabloyu_goster();
            return 0;
        }

    } while (1);

    return 0;
}

// Gizli tabloyu oluşturur ve mayınları yerleştirir.
void gizli_tablo_olustur() {
    int i, j;

    for (i = 0; i <= TABLO_BOYUTU + 1; i++) {
        for (j = 0; j <= TABLO_BOYUTU + 1; j++) {
            gizliTablo[i][j] = 0;
        }
    }
    mayin_yerlestir();
}

// Görünen tabloyu başlatır ve tüm hücreleri '#'
void tabloyu_baslat() {
    int i, j;

    for (i = 0; i <= TABLO_BOYUTU + 1; i++) {
        for (j = 0; j <= TABLO_BOYUTU + 1; j++) {
            tablo[i][j] = '#';
        }
    }
}

// Tabloyu ekrana yazdırır.
void tabloyu_goster() {
    int i, j;

    printf("\n");
    for (i = 1; i <= TABLO_BOYUTU; i++) {
        printf("%3d", i);
    }
    printf("\n---\n");

    for (i = 1; i <= TABLO_BOYUTU; i++) {
        for (j = 1; j <= TABLO_BOYUTU; j++) {
            printf("%3c", tablo[i][j]);
        }
        printf(" |%d\n", i);
    }
}

// Gizli tabloyu ekrana yazdırır (sadece debugging amaçlı).
void gizli_tabloyu_goster() {
    int i, j;

    printf("\n");
    for (i = 1; i <= TABLO_BOYUTU; i++) {
        printf("%3d", i);
    }
    printf("\n---\n");

    for (i = 1; i <= TABLO_BOYUTU; i++) {
        for (j = 1; j <= TABLO_BOYUTU; j++) {
            printf("%3d", gizliTablo[i][j]);
        }
        printf(" |%d\n", i);
    }
}

// Mayınları tabloya rastgele yerleştirir.
void mayin_yerlestir() {
    srand(time(NULL));
    int i, satir, sutun;

    for (i = 1; i <= NORMALE; i++) {
        satir = 1 + rand() % TABLO_BOYUTU;
        sutun = 1 + rand() % TABLO_BOYUTU;

        if (gizliTablo[satir][sutun] == -1) {
            i--; // Aynı yere mayın koymamak için geri döneriz.
        } else {
            gizliTablo[satir][sutun] = -1;
        }
    }
}

// Oyuncunun kazandığını kontrol eder.
int kazanma_durumu_kontrol() {
    int i, j, dogru_bayrak = 0;

    for (i = 1; i <= TABLO_BOYUTU; i++) {
        for (j = 1; j <= TABLO_BOYUTU; j++) {
            if (tablo[i][j] == 'D' && gizliTablo[i][j] == -1) {
                dogru_bayrak++;
            }
        }
    }

    return (dogru_bayrak == NORMALE) ? KAZANDI : DEVAM;
}

// Belirtilen hücreyi açar ve gerektiğinde komşularını açar.
int kaz(int satir, int sutun) {
    if (gizliTablo[satir][sutun] == -1) {
        return KAYBETTI; // Mayına bastık, kaybettik.
    } else {
        komsulari_ac(satir, sutun);
        return DEVAM;
    }
}

// Komşu hücreleri açar.
void komsulari_ac(int satir, int sutun) {
    int i, j;

    tablo[satir][sutun] = '0' + gizliTablo[satir][sutun];

    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (gizliTablo[satir + i][sutun + j] >= 0 && tablo[satir + i][sutun + j] == '#') {
                komsulari_ac(satir + i, sutun + j);
            }
        }
    }
}
