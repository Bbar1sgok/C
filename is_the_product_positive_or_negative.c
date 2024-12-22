#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main() {


    int girilenSayi1, girilenSayi2;
    double carpim;

    printf("Lutfen birinci sayiyi giriniz: \n");
    scanf("%d", &girilenSayi1);
    printf("Lutfen ikinci sayiyi giriniz: \n");
    scanf("%d", &girilenSayi2);

    carpim = girilenSayi1 * girilenSayi2;

    if(carpim == 0){

        printf("Sonuc: %.0f Sifir sayisi pozitiflik ve negatiflik temsil etmez.", carpim);
    }
    else if(carpim < 0){

        printf("Sonuc: %.0f carpimin sonucu negatif bir sayidir.", carpim);
    }
    else{

        printf("Sonuc: %.0f carpimin sonucu pozitif bir tam sayidir.", carpim);
    }

    return 0;
}
