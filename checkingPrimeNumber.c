#include <stdio.h>
#include <stdlib.h>

int main() {
    /*
        Asal sayı sorgulama
    */


    int girilenSayi, i, sorgulama;

    printf("Lutfen sorgulamak istediginiz sayiyi giriniz: \n");
    scanf("%d", &girilenSayi);

    if(girilenSayi <= 1){

        printf("Girilen sayi: %d asal degildir.", girilenSayi);

    }
    else{


        for(i = 2; i < girilenSayi; i++){

            sorgulama = girilenSayi % i;

            if(sorgulama == 0){

                printf("Girilen sayi: %d asal sayi degildir.", girilenSayi);
                break;
            }


        }

    }

    if(sorgulama != 0){

        printf("Girilen sayi: %d  asal sayidir.", girilenSayi);
    }




    return 0;
}
