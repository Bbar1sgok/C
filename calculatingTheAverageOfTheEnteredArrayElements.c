#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    float sayi[100], ortalama, toplam = 0.0; 

    
    printf("Kac tane sayi giriceksiniz: \n");
    scanf("%d", &n);

    // Kullanıcıdan alınan sayı adedi kontrol ediliyor
    while (n >= 100 || n <= 0) {
        printf("Lutfen 1 ile 99 arasinda bir sayi giriniz: \n");
        scanf("%d", &n);
    }

    // Kullanıcıdan sayıları alıyoruz
    for (i = 0; i < n; i++) {
        printf("Lutfen %d. sayiyi giriniz: \n", i + 1);
        scanf("%f", &sayi[i]);
    }

    // Sayıların toplamını hesaplıyoruz
    for (i = 0; i < n; i++) {
        toplam += sayi[i];
    }

    // Ortalamayı hesaplayıp yazdırıyoruz
    ortalama = toplam / n;
    printf("Girmis oldugunuz dizi elemanlarinin ortalamasi: %.2f", ortalama); 

    return 0;
}
