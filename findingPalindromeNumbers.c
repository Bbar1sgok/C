#include <stdio.h>
#include <stdlib.h>

int main() {
    /*
        Bir sayının PALINDROM sayı olup olmadığını bulma,
        Tersten yazımıda kendisine eşit sayılar palindrom sayılardır.
    */

    int girilenSayi, olusturulanSayi = 0, kalan, orijinalSayi;

    printf("Lutfen bir sayi giriniz: \n");
    scanf("%d", &girilenSayi);


    orijinalSayi = girilenSayi;

    while(girilenSayi != 0){
        kalan = girilenSayi % 10;
        olusturulanSayi = olusturulanSayi * 10 + kalan;
        girilenSayi /= 10;
    }

    printf("Sayimizin tersi: %d\n", olusturulanSayi);
    printf("Girilen sayi: %d\n", orijinalSayi);

    if(orijinalSayi == olusturulanSayi){
        printf("Girilen sayi bir PALINDROM sayidir: %d = %d\n", orijinalSayi, olusturulanSayi);
    } else {
        printf("Girilen sayi bir PALINDROM sayi degildir: %d != %d\n", orijinalSayi, olusturulanSayi);
    }

    return 0;
}
