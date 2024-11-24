#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <ctype.h>

int main() {
    setlocale(LC_ALL,"Turkish");

    int girilenSayi;
    char evet = 'e', hayir = 'h', girilenDeger;

    printf("Lütfen bir tam sayı giriniz: \n");
    scanf("%d", &girilenSayi);

    while(true) {


        if(girilenSayi % 2 == 0) {
            printf("%d sayısı çift sayıdır.\n", girilenSayi);
        } else {
            printf("%d sayısı tek sayıdır.\n", girilenSayi);
        }


        printf("Başka sayı sorgulamak ister misiniz? (e/h)\n");

        // Buffer'ý temizlemek için getchar kullanýlýr (önceki scanf'nin newline karakterini temizler)
        getchar();
        scanf("%c", &girilenDeger);

        if (tolower(girilenDeger) == hayir) {
            printf("İşlem başarıyla sonlandırıldı.\n");
            break;
        } else if (tolower(girilenDeger) == evet) {

            printf("Lütfen yeni bir tam sayı giriniz: \n");
            scanf("%d", &girilenSayi);
        } else {
            printf("Geçersiz giriþ! 'e' veya 'h' giriniz.\n");
        }
    }

    return 0;
}
