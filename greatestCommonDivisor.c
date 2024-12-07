#include <stdio.h>
#include <stdlib.h>

int main() {
    /*
        En büyük ortak bölen hesaplama.
    */

    int sayi1, sayi2, i, geciciAtama, ebob;

    printf("Lutfen birinci sayiyi giriniz: \n");
    scanf("%d", &sayi1);
    printf("Lutfen ikinci sayiyi giriniz: \n");
    scanf("%d", &sayi2);

    if(sayi2 > sayi1){

        geciciAtama = sayi2;
        sayi2 = sayi1;
        sayi1 = geciciAtama;

    }

    for(i = 1; i <= sayi2; i++){

        if(sayi1 % i == 0 && sayi2 % i == 0){

            ebob = i ;
        }

    }

    printf("Sonuc: %d", ebob);

    return 0;
}
