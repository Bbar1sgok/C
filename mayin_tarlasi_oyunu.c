#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

// Sabitler
#define TABELA_BOYUTU 15 // Tablo boyutu istege baglı degisebilir
#define NORMAL 3          // Mayın sayısı, isteğe göre değiştirilebilir
#define KAZAN 1
#define KAYBET -1
#define DEVAM 0

// Global degiskenler
char tablo[TABELA_BOYUTU + 2][TABELA_BOYUTU + 2];  // Gosterilen tablo
int alt_tablo[TABELA_BOYUTU + 2][TABELA_BOYUTU + 2];  // Mayin ve komsu mayin bilgileri
int mayin_sayisi, y = 0;
int bayrak_sayisi = 0;

// Kullanilan fonksiyonlar
void alt_tablo_olustur();
void tabloyu_baslat();
void alt_tabloyu_goster();
void tabloyu_goster();
void mayinlari_yerlestir();
int oyunu_kazandimi();
void etraflari_kesfet(int satir, int sutun);
int kazma(int satir, int sutun);

int main(void)
{
    int satir, sutun;
    int ilerleme;

    int yeniden;
    char eylem;  // Hangi eylem yapilacak
    printf("Mayin Tarlasi oyununa hosgeldiniz\n");
    alt_tablo_olustur();
    tabloyu_baslat();

    do
    {
        tabloyu_goster();
        printf("\n");
        printf("Lutfen su formatta giriniz:(kazma) c,satir,sutun veya (isaretleme) d,satir,sutun veya (isareti kaldirma) e,satir,sutun\n");
        scanf(" %c,%d,%d", &eylem, &satir, &sutun);  // Boşluk ekledim, karakterlerin alınması sorunu çözümü
        printf("\n");

        if(eylem == 'c')
        {
            ilerleme = kazma(satir, sutun);
        }
        else if(eylem == 'd')
        {
            if(mayin_sayisi > bayrak_sayisi)
            {
                bayrak_sayisi++;
                tablo[satir][sutun] = 'D';
                ilerleme = oyunu_kazandimi();
            }
        }
        else if(eylem == 'e')
        {
            if(bayrak_sayisi > 0)
            {
                bayrak_sayisi--;
            }
            tablo[satir][sutun] = '#';
            ilerleme = kazma(satir, sutun);
        }

        if(ilerleme == KAYBET)
        {
            printf("Arkadasim, oyunu kaybettin \n");
            alt_tabloyu_goster();
            printf("Oyunu yendiden oynamak istiyor musunuz? [1-Evet][0-Hayir] \n");
            scanf("%d", &yeniden);
            switch(yeniden)
            {
            case 0:
                printf("Tesekkurler, Gorusuruz\n");
                return 0;
            case 1:
                bayrak_sayisi = 0;
                ilerleme = DEVAM;
                alt_tablo_olustur();
                tabloyu_baslat();
                break;
            default:
                printf("Yanlis bir deger girdiniz\n");
                break;
            }
        }

        if(ilerleme == KAZAN)
        {
            printf("Bravo, harika bir is cikardin\n");
            alt_tabloyu_goster();
            printf("Oyunu yendiden oynamak istiyor musunuz? [1-Evet][0-Hayir] \n");
            scanf("%d", &yeniden);
            switch(yeniden)
            {
            case 0:
                printf("Tesekkurler, Gorusuruz\n");
                return 0;
            case 1:
                bayrak_sayisi = 0;
                ilerleme = DEVAM;
                alt_tablo_olustur();
                tabloyu_baslat();
                break;
            default:
                printf("Yanlis bir deger girdiniz\n");
                break;
            }
        }

    }
    while(1);
    return 0;
}

void alt_tablo_olustur()
{
    int i, j, satir, sutun, k, p;
    mayin_sayisi = NORMAL;

    // Alt tabloyu olustur
    for(i = 0; i <= TABELA_BOYUTU + 1; i++)
    {
        for(j = 0; j <= TABELA_BOYUTU + 1; j++)
        {
            alt_tablo[i][j] = 0;
        }
    }
    // Tabloyu sinirlama
    for(i = 0; i <= TABELA_BOYUTU; i++)
    {
        alt_tablo[i][0] = 1;
        alt_tablo[i][TABELA_BOYUTU + 1] = 1;
    }
    for(j = 0; j <= TABELA_BOYUTU; j++)
    {
        alt_tablo[0][j] = 1;
        alt_tablo[TABELA_BOYUTU + 1][j] = 1;
    }

    mayinlari_yerlestir();
}

void tabloyu_baslat()
{
    int i, j;

    // Tabloyu olustur
    for(i = 0; i <= TABELA_BOYUTU + 1; i++)
    {
        for(j = 0; j <= TABELA_BOYUTU + 1; j++)
        {
            tablo[i][j] = '#';
        }
    }
    // Sinirlari yerleştir
    for(i = 0; i <= TABELA_BOYUTU; i++)
    {
        tablo[i][0] = '*';
        tablo[i][TABELA_BOYUTU + 1] = '*';
    }
    for(j = 0; j <= TABELA_BOYUTU; j++)
    {
        tablo[0][j] = '*';
        tablo[TABELA_BOYUTU + 1][j] = '*';
    }
}

void tabloyu_goster()
{
    int i, j;

    printf("\n");
    // Sutun numaralarini yazdir
    for(i = 1; i <= TABELA_BOYUTU; i++)
    {
        printf("%3d", i);
    }
    printf("\n");

    // Tabloyu sinirla
    for(i = 1; i <= TABELA_BOYUTU; i++)
    {
        printf("---");
    }
    printf("\n");

    // Tabloyu ekrana yazdir
    for(i = 1; i <= TABELA_BOYUTU; i++)
    {
        for(j = 1; j <= TABELA_BOYUTU; j++)
        {
            printf("%3c", tablo[i][j]);
        }
        printf(" |%d", i);  // Satir numaralarini yazdir
        printf("\n");
    }

    // Tabloyu alt sinirla
    for(i = 1; i <= TABELA_BOYUTU; i++)
    {
        printf("___");
    }
}

void alt_tabloyu_goster()
{
    int i, j;

    printf("\n");
    // Sutun numaralarini yazdir
    for(i = 1; i <= TABELA_BOYUTU; i++)
    {
        printf("%3d", i);
    }
    printf("\n");

    // Alt tabloyu sinirla
    for(i = 1; i <= TABELA_BOYUTU; i++)
    {
        printf("---");
    }
    printf("\n");

    // Alt tabloyu ekrana yazdir
    for(i = 1; i <= TABELA_BOYUTU; i++)
    {
        for(j = 1; j <= TABELA_BOYUTU; j++)
        {
            printf("%3d", alt_tablo[i][j]);
        }
        printf(" |%d", i);  // Satir numaralarini yazdir
        printf("\n");
    }

    // Alt tabloyu sinirla
    for(i = 1; i <= TABELA_BOYUTU; i++)
    {
        printf("___");
    }
    printf("\n");
}

void mayinlari_yerlestir()
{
    srand(time(NULL));  // Rastgele sayi üretme
    int i, j, k, p, satir, sutun;
    mayin_sayisi = NORMAL;

    // Mayinlari rastgele yerleştir
    for(i = 1; i <= mayin_sayisi; i++)
    {
        satir = 1 + rand() % TABELA_BOYUTU;
        sutun = 1 + rand() % TABELA_BOYUTU;
        if(alt_tablo[satir][sutun] == -1)
            i--; // Mayin varsa, bir daha yerleştir
        alt_tablo[satir][sutun] = -1;  // Mayini yerleştir

        // Komsu hücrelerdeki sayilari güncelle
        for(k = -1; k <= 1; k++)
        {
            for(p = -1; p <= 1; p++)
            {
                if(alt_tablo[satir][sutun] == -1)
                {
                    if(alt_tablo[satir + k][sutun + p] != -1)
                    {
                        alt_tablo[satir + k][sutun + p]++;
                    }
                }
            }
        }
    }
}

int oyunu_kazandimi()
{
    int i, j, bayrakli_hucre = 0;
    for(i = 1; i <= TABELA_BOYUTU; i++)
    {
        for(j = 1; j <= TABELA_BOYUTU; j++)
        {
            if(tablo[i][j] == 'D')  // Bayraklı hücreleri say
            {
                if(alt_tablo[i][j] == -1)
                {
                    bayrakli_hucre++;
                }
            }
        }
    }

    if(bayrakli_hucre == NORMAL)  // Bayrak sayisi ve kesfedilmemis hücrelerin toplamı mayın sayısına eşitse
    {
        return KAZAN;
    }
    else
    {
        return DEVAM;
    }
}

void etraflari_kesfet(int satir, int sutun)
{
    int i, j;

    tablo[satir][sutun] = '0' + alt_tablo[satir][sutun];  // Hücreyi keşfet

    // Tum komsu hücreleri kesfet
    for(i = -1; i <= 1; i++)
    {
        for(j = -1; j <= 1; j++)
        {
            if(satir + i >= 1 && satir + i <= TABELA_BOYUTU && sutun + j >= 1 && sutun + j <= TABELA_BOYUTU)
            {
                if(alt_tablo[satir + i][sutun + j] > 0 && tablo[satir + i][sutun + j] == '#')  // Sayi varsa ve henüz açılmamışsa
                {
                    tablo[satir + i][sutun + j] = '0' + alt_tablo[satir + i][sutun + j];
                }
                else if(alt_tablo[satir + i][sutun + j] == 0 && tablo[satir + i][sutun + j] == '#')  // 0 sayısı varsa ve henüz açılmamışsa
                {
                    etraflari_kesfet(satir + i, sutun + j);  // Komsu hücreyi kesfet
                }
            }
        }
    }
}

int kazma(int satir, int sutun)
{
    int durum = 0;
    if(alt_tablo[satir][sutun] == -1)  // Mayin mi
    {
        durum = KAYBET;  // Eğer mayınsa kaybet
    }
    else if(alt_tablo[satir][sutun] > 0)  // Sayi varsa
    {
        tablo[satir][sutun] = '0' + alt_tablo[satir][sutun];
    }
    else  // Boş alansa
    {
        etraflari_kesfet(satir, sutun);  // Etrafını kesfet
    }
    return durum;
}
