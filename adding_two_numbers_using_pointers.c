#include <stdio.h>
#include <stdlib.h>


int main()
{
   int girilenSayi1, girilenSayi2, toplam;
    int *ptr1, *ptr2;

    printf("Lutfen birinci sayiyi giriniz: \n");
    scanf("%d", &girilenSayi1);

    printf("Lutfen ikinci sayiyi giriniz: \n");
    scanf("%d", &girilenSayi2);

    ptr1 = &girilenSayi1;
    ptr2 = &girilenSayi2;

    toplam = *ptr1 + *ptr2;

    printf("Girilen sayilarin toplami: %d", toplam);


    return 0;
}
