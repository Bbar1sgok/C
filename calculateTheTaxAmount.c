#include <stdio.h>
#include <stdlib.h>

int main() {
    /*
        3 adet ürünümüz var: Kitap, Temel Gıda ve Lüks
        Her grup farklı oranlarda vergilendiriliyor.
        Kitap %4.0 / Temel Gıda %5.6 / Lüks %19.6

        Her ürünün ayrı bir kodu var: Kitap 0, Temel Gıda 1, Lüks 2

        Kullanıcıdan istediğini ürünün kodunu ve fiyatını aldıktan sonra vergiler
        dahil fiyatını ekrana bastırınız.
    */

    int urunKodu;
    float urunFiyati;


    const float kitapVergiOrani = 0.04;
    const float temelGidaVergiorani = 0.056;
    const float luksVergiorani = 0.196;

    printf("Lutfen urun kodunu giriniz: Kitap(0), Temel Gida(1), luks(2) \n");
    scanf("%d", &urunKodu);

    printf("Lutfen urununuzun fiyatini giriniz: \n");
    scanf("%f", &urunFiyati);

    // Negatif fiyat girilmesi durumunda kontrol
    if (urunFiyati < 0) {
        printf("Fiyat negatif olamaz. Lütfen geçerli bir fiyat giriniz.\n");
        return 1; // Programı sonlandır
    }

    // Ürün koduna göre işlem yapalım
    switch(urunKodu) {
        case 0: // Kitap
            urunFiyati *= (1 + kitapVergiOrani);
            printf("Vergiler dahil kitabin son fiyati: %.2f\n", urunFiyati);
            break;

        case 1: // Temel Gıda
            urunFiyati *= (1 + temelGidaVergiorani);
            printf("Vergiler dahil temel gidanin son fiyati: %.2f\n", urunFiyati);
            break;

        case 2: // Lüks
            urunFiyati *= (1 + luksVergiorani);
            printf("Vergiler dahil luks urunun son fiyati: %.2f\n", urunFiyati);
            break;

        default:
            printf("Girdiginiz urun kodu yanlis. Lutfen Kitap(0), Temel Gida(1) veya Luks(2) giriniz.\n");
            break;
    }

    return 0;
}
