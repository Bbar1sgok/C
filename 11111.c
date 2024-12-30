#include <stdio.h>
#include <stdlib.h>

// Projede kullanýlan sabit deðerler

#define MAYIN_TARLASI_BOYUTLANDIRMA 8 // Mayýn tarlasýnýn boyutunu ayarlama.
#define MAYIN_SAYISI 7
#define KAZANILDI 1 // Oyuncu kazandýðýysa geriyee 1 deðeri döndürülür.
#define KAYBEDILDI -1 // Oyuncu kaybettiðinde dönen deðer.
#define CONTINUE 0 // Oyuna devam ediliyor.

// Global Veriables

int alt_sekme[MAYIN_TARLASI_BOYUTLANDIRMA + 2][MAYIN_TARLASI_BOYUTLANDIRMA + 2];
char sekme[MAYIN_TARLASI_BOYUTLANDIRMA + 2][MAYIN_TARLASI_BOYUTLANDIRMA + 2];
int mayin_sayim, yerlestirilen_mayin_sayisi = 0;
int d_sayac;

// Projede Kullanýlan Fonksiyonlar

void alt_tablo_olusturma(); // Alt tabloyu oluþturmayý saðlar.
void initialiser_tableau(); // Ýlk olarak tablonun initialiser etmesini saðlar.
void alt_tablo_bastirma(); // Alt tablomu bastýrmamý saðlar.
void afficher_tableau(); // Tablomu bastuýrmamý saðlar.
void mayin_yerlestirme(); // Mayýnlarý yerleþtir.
void verifiermatchgagner(); // Oyuncunun kazanýp kazanmadýðýnýn kontrolünü saðlar.
void explorer(); // Mayýn tarlasýnýn keþfini saðlar.
int creuser(int ligne, int colonne); // MAyýn tarlasýnýn içerisindeki istenilen koordinatýn açýlmasýnda görev alýr.

int main()
{
    int satir,sutun,ilerleme,tekrar;
    char aksiyon;// hangi harf
    printf(" ***   Mayin Tarlasi   ***\n\n");

    alt_tablo_olusturma();
    baslangic_dizisi();
    alt_tablo_bastirma();
    do
    {

        printf("\n");
        printf("Lutfen su formatta giriniz: c,3,5 veya d,1,2 \n");
        scanf("%c,%d,%d", &aksiyon, &satir, &sutun);
        printf("\n");

        if(aksiyon == 'c')
        {
           ilerleme = komsulari_kesfetme(satir,sutun);
        }
        else if(aksiyon == 'd')
        {
            if(MAYIN_SAYISI > d_sayac)
            {
                d_sayac++;
                sekme[satir][sutun] = 'D';
                ilerleme =  oyunun_durumu();
            }
        }
        else if(aksiyon == 'e')
        {
            if(d_sayac > 0)
            {
                d_sayac--;

            }

            sekme[satir][sutun] = '#';
            ilerleme = komsulari_kesfetme(satir,sutun);
        }

        if(ilerleme == KAYBEDILDI)
        {
            printf("Oyunu kaybettiniz \n");
            alt_tablo_bastirma();
            printf("oyunu yeniden oynamak ister misiniz? [1-) Evet][0-) Hayir] \n");
            scanf("%d", &tekrar);
            switch(tekrar)
            {
                case 0: printf("Tesekkurler Gorusuruz \n");
                        return 0;
                        break;
                case 1:
                    {
                         d_sayac = 0;
                         ilerleme = CONTINUE;
                         alt_tablo_olusturma();
                         baslangic_dizisi();
                         break;


                    }
                default:printf("Yanlis bir deger girildi \n");
                        break;
            }


        }
        if(ilerleme == KAZANILDI)
        {
            printf("Tebrikler kazandiniz.\n");
            alt_tablo_bastirma();
            printf("oyunu tekrar oynamak ister misiniz? [1-) Evet][0-) Hayir] \n");
            scanf("%d", &tekrar);
            switch(tekrar)
            {
                case 0: printf("Tesekkurler Gorusuruz \n");
                        return 0;
                        break;
                case 1:
                    {
                         d_sayac = 0;
                         ilerleme = CONTINUE;
                         alt_tablo_olusturma();
                         baslangic_dizisi();
                         break;


                    }
                default:printf("Yanlis bir deger girdiniz \n");
                        break;
            }
        }

    }while(1);

    return 0;
}



void alt_tablo_olusturma()
{

    int i,j,mayin_sayisi;

    for(i = 0; i <=MAYIN_TARLASI_BOYUTLANDIRMA + 1; i++)
    {
        for(j = 0; j<= MAYIN_TARLASI_BOYUTLANDIRMA + 1; j++)
            {
                alt_sekme[i][j] = 0;
            }
    }


    for(i = 0; i <= MAYIN_TARLASI_BOYUTLANDIRMA + 1; i++)
    {

        alt_sekme[i][0] = 1;
        alt_sekme[i][MAYIN_TARLASI_BOYUTLANDIRMA + 1] = 1;
    }

    for(j = 0; j <= MAYIN_TARLASI_BOYUTLANDIRMA; j++)
    {
        alt_sekme[0][j] = 1;
        alt_sekme[MAYIN_TARLASI_BOYUTLANDIRMA + 1][j] = 1;
    }


    mayin_sayisi = MAYIN_SAYISI;

    mayin_yerlestirme();


}

void baslangic_dizisi()
{
    int i,j;

    for(i = 0; i <=MAYIN_TARLASI_BOYUTLANDIRMA + 1; i++)
    {
        for(j = 0; j<= MAYIN_TARLASI_BOYUTLANDIRMA + 1; j++)
        {
            sekme[i][j] = '#';
        }
    }


    for(i = 0; i <= MAYIN_TARLASI_BOYUTLANDIRMA + 1; i++)
    {

        sekme[i][0] = '*';
        sekme[i][MAYIN_TARLASI_BOYUTLANDIRMA + 1] = '*';
    }

    for(j = 0; j <= MAYIN_TARLASI_BOYUTLANDIRMA; j++)
    {
        sekme[0][j] = '*';
        sekme[MAYIN_TARLASI_BOYUTLANDIRMA + 1][j] = '*';
    }

}


void alt_tablo_bastirma()
{
    int i, j;

    for(i = 1; i <= MAYIN_TARLASI_BOYUTLANDIRMA; i++)
    {
       printf("%3d",i);

    }
    printf("\n");

    for(i = 1; i <= MAYIN_TARLASI_BOYUTLANDIRMA; i++)
    {
        for(j = 1; j <= MAYIN_TARLASI_BOYUTLANDIRMA; j++)
        {
            printf("%3c",sekme[i][j]);
        }
        printf("  |%d \n",i);


    }

    for(i = 1; i <= MAYIN_TARLASI_BOYUTLANDIRMA; i++)
    {
        printf("---");
    }

}


void mayin_yerlestirme()
{
    srand(time(NULL));

    mayin_sayim = MAYIN_SAYISI;

    int i,j,q,s,satir, sutun;

    for(i = 1; i <= mayin_sayim; i++)
    {
       satir = 1 + rand()% MAYIN_TARLASI_BOYUTLANDIRMA;
       sutun = 1 + rand()% MAYIN_TARLASI_BOYUTLANDIRMA;

       if(alt_sekme[satir][sutun] == -1)
            i--;

        alt_sekme[satir][sutun] = -1;

        for(q = -1; q <= 1; q++)
        {
            for(s = -1; s <=1; s++)
            {
                if(alt_sekme[i][j]== -1)
                {
                    if(alt_sekme[satir + q][sutun + s] != -1)
                    {
                        alt_sekme[satir + q][sutun + s]++;
                    }

                }

            }
        }


    }


}

int koordinat_acma(int satir, int sutun)
{
    int x = 0;

    if(alt_sekme[satir][sutun] == -1)
    {
        x = KAYBEDILDI;

    }
    else if(alt_sekme[satir][sutun] > 0)
    {
        sekme[satir][sutun] = ('0'+ alt_sekme[satir][sutun]);//AÇ
        x = oyunun_durumu();
        x = CONTINUE;
    }
    else
    {
        komsulari_kesfetme(satir,sutun);

    }

    return x;

}


void komsulari_kesfetme(int satir, int sutun)
{
    int i,j;
    sekme[satir + i][sutun + j] = '0' + alt_sekme[satir + i][sutun + j];

    for(i = -1; i <= 1; i++)
    {
        for(j = -1; j <= 1; j++)
        {
            if(alt_sekme[satir + i][sutun + i] > 0 && sekme[satir + i][sutun + j] == '#')
            {
                sekme[satir + i][sutun + j] = '0' + alt_sekme[satir + i][sutun + j];

            }
            else if(alt_sekme[satir + i][sutun + j] == 0 && sekme[satir + i][sutun + j] == '#')
            {
                komsulari_kesfetme(satir + i,sutun + i);

            }

        }

    }

int oyunun_durumu()
{
    int i,j;
    int durum;
    for(i = 1; i <= MAYIN_TARLASI_BOYUTLANDIRMA; i++)
    {
        for(j = 1; j <= MAYIN_TARLASI_BOYUTLANDIRMA; j++)
        {
            if (sekme[i][j] == 'D')
            {
                if(alt_sekme[i][j] == -1)
                {
                  yerlestirilen_mayin_sayisi++;

                }
            }

        }

    }

    if(yerlestirilen_mayin_sayisi == MAYIN_SAYISI)
    {
        durum = KAZANILDI;

    }
    else
    {
        durum = CONTINUE;

    }

    return durum;
}



}








