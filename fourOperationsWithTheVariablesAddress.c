#include <stdio.h>
#include <stdlib.h>

// 4 islemi gerceklestiren fonksiyon
void dortIslem(char *secilenISlem, float *sayi1, float *sayi2){

    switch(*secilenISlem){

    case '+':
        printf("Toplama isleminin sonucu: %.2f\n", *sayi1 + *sayi2);
        break;

    case '-':
        printf("Cikarma isleminin sonucu: %.2f\n", *sayi1 - *sayi2);
        break;

    case '/':
        if(*sayi1 == 0 && *sayi2 == 0){

            printf("Sifirin sifira bolumu matematikte belirsizlik olarak ifade edilir.");
            break;
        }
        else if(*sayi1 != 0 && *sayi2 == 0){

            printf("Sifir haric herhangi bir sayinin sifira bolumu matematikte tanimsizlik olarak ifade edilir.");
            break;
        }
        else{

            printf(" Bolme islemin sonucu: %.2f", *sayi1/ *sayi2);
            break;
        }

    case '*':
        printf("Carpma isleminin sonucu: %.2f", *sayi1 * *sayi2);
        break;

    default:
        printf("Lutfen gecerli bir islem seciniz!");
        break;
    }

}

int main()
{
    float girilenSayi1, girilenSayi2;
    char secilenIslem;

    printf("Lutfen birinci sayiyi giriniz: \n");
    scanf("%f", &girilenSayi1);

    printf("Lutfen ikinci sayiyi giriniz: \n");
    scanf("%f", &girilenSayi2);

    printf("Lutfen yapmak istediginiz islemi seciniz: Toplama(+), Cikarma(-), Bolme(/), Carpma(*) \n");
    getchar();  // Önceki scanf ile girilen yeni satır karakterini temizler.
    scanf("%c", &secilenIslem);

    dortIslem(&secilenIslem, &girilenSayi1, &girilenSayi2);

    return 0;
}
