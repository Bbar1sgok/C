#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main() {

    int girilenSayi;

    printf("Lutfen sorgulamak istediginiz sayiyi giriniz: ");
    scanf("%d", &girilenSayi);

    if(girilenSayi % 13 == 0 && girilenSayi % 17 == 0){

        printf("Girilen sayi: %d, 13 ve 17 sayilarina tam bolunur.", girilenSayi);
    }
    else if(girilenSayi % 13 == 0){
        
        printf("Girilen sayi: %d, sadece 13 e tam bolunur. ", girilenSayi);
    }
    else if(girilenSayi % 17 == 0){

        printf("Girilen sayi: %d, sadece 17 e tam bolunur. ", girilenSayi);
    }
    else{

        printf("Girilen sayi: %d, 13 veya 17 tam olarak bolunmez.", girilenSayi);
    }

    return 0;
}
