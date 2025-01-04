#include <stdio.h>
#include <stdlib.h>

void yerDegistir(int *sayi1, int *sayi2)
{
    int tutucu;

    tutucu = *sayi1;
    *sayi1 = *sayi2;
    *sayi2 = tutucu;


}

int main()
{

    int girilenSayi1, girilenSayi2;

    printf("Lutfen birinci sayiyi giriniz: \n");
    scanf("%d", &girilenSayi1);
    printf("Lutfen ikinci sayiyi giriniz: \n");
    scanf("%d", &girilenSayi2);

    printf("Sayilarin yeri degistirilmeden onceki degerleri Sayi 1: %d , Sayi 2: %d\n",girilenSayi1, girilenSayi2);

    // Sayıların yerini değiştirme fonksiyonu
    yerDegistir(&girilenSayi1, &girilenSayi2);

    printf("Sayilarin yeri degistirildikten sonraki degerleri Sayi 1: %d , Sayi 2: %d",girilenSayi1, girilenSayi2);



    return 0;
}
