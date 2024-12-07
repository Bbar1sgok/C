#include <stdio.h>
#include <stdlib.h>


int main() {

    // Girilen 3 basamaklı  sayının Armstrong sayı olup olmadığını sorgulama

     int girilenSayi, i, carpim = 0, orijinalSayi, kalan;

     printf("Lutfen 3 basamakli bir sayi giriniz: \n");
     scanf("%d", &girilenSayi);

    orijinalSayi = girilenSayi;

    while(girilenSayi != 0){

        kalan = girilenSayi % 10;
        carpim += kalan * kalan * kalan;
        girilenSayi /= 10;
    }

    if(orijinalSayi == carpim){

        printf("Girilen sayi: %d Armstrong sayidir.", orijinalSayi);
    }
    else{

        printf("Girilen sayi: %d Armstrong sayi degildir.", orijinalSayi);
    }

    return 0;
}
