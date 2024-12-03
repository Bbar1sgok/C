#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

int main()
{
    /*
            Kullanıcıdan pozitif bir sayı girmesini isteyiniz
            Girilen sayının karekökünü hesaplayın
            Girilen sayı negatifse kullanıcıdan yeni bir sayı girmesini isteyiniz
            Girilen sayı 0 ise program çalışmayı durdursun
            Girilen sayı pozitifse karekökünü hesaplayınız

    */

    float girilenSayi;

    do{

        printf("Lutfen pozitif bir  sayi giriniz: \n");
        scanf("%f",&girilenSayi);

        if(girilenSayi < 0){

            printf("Hatali giris yapildi: \n");

        }

        if(girilenSayi < 0) continue;

        printf("Girilen sayinin karekoku: %.2f",sqrt(girilenSayi));
        break;

    }while(girilenSayi);


    return 0;
}
