#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    float sayi[100], minSayi;

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

    // minSayi'yı ilk sayı ile başlatıyoruz
    minSayi = sayi[0];

    // Diğer sayılarla karşılaştırarak en küçük sayıyı buluyoruz
    for (i = 1; i < n; i++) {  // İlk elemanı zaten minSayi olarak atadık, o yüzden 1'den başlıyoruz
        if (sayi[i] < minSayi) {
            minSayi = sayi[i];
        }
    }

    // Sonuç: en küçük sayıyı yazdırıyoruz
    printf("Girmis oldugunuz dizi elemanlarinin en kucugu: %.2f\n", minSayi);

    return 0;
}
