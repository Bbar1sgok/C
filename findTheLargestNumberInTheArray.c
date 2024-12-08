#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    float sayi[100], maxSayi;

    printf("Kac tane sayi giriceksiniz: \n");
    scanf("%d", &n);

    // Kullanıcıdan alınan sayı adedi kontrol ediliyor
    while (n >= 100 || n <= 0) {
        printf("Lutfen 1 ile 99 arasinda bir sayi giriniz: \n");
        scanf("%d", &n);
    }

    // Kullanıcıdan sayıları alıyoruz ve diziye ekliyoruz
    for (i = 0; i < n; i++) {
        printf("Lutfen %d. sayiyi giriniz: \n", i + 1);
        scanf("%f", &sayi[i]);
    }

    // maxSayi'yı ilk sayı ile başlatıyoruz
    maxSayi = sayi[0];

    // Diğer sayılarla karşılaştırarak en büyüğü buluyoruz
    for (i = 1; i < n; i++) {  // İlk elemanı zaten maxSayi olarak atadık, o yüzden 1'den başlıyoruz
        if (sayi[i] > maxSayi) {
            maxSayi = sayi[i];
        }
    }

    printf("Girmis oldugunuz dizi elemanlarinin en buyugu: %.2f\n", maxSayi);

    return 0;
}
