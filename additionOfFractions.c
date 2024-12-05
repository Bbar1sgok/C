#include <stdio.h>
#include <stdlib.h>

int main() {
    /*
        Aşağıdaki belitilen işlemleri yapan bir C program yazınız.

        Toplma(+) veya çıkarma(-) operatörü giriniz.

        '+' operatörü için  1/a + 1/b, '-' operatörü için 1/a - 1/b işlemlerinin sonucunu basit kesir cinsinden bulunuz.
        Girilen a ve b değerlerinin biri 0 ise işlemin yapılamayacağını bir mesaj ile beliritiniz.


    */

    char girilenOp;
    int girilenA, girilenB;
    float sonuc;

    printf("Lutfen 'a' degerini giriniz:\n");
    scanf("%d", &girilenA);
    printf("Lutfen 'b' degerini giriniz: \n");
    scanf("%d", &girilenB);

    printf("Toplamak icin '+' cikarmak icin '-' operatorlerinden birini giriniz:\n");
    getchar();
    scanf("%c",&girilenOp);

    if(girilenOp == '+' || girilenOp == '-'){

        if(girilenA != 0 && girilenB != 0){

            if(girilenOp == '+'){

                sonuc = 1.0/girilenA + 1.0/girilenB;
                printf("Kesirlerin toplaminin sonucu: %.2f",sonuc);
            }
            else{

                sonuc = 1.0/girilenA - 1.0/girilenB;
                printf("Kesirlerin farki: %.2f",sonuc);

            }
        }
        else{

            printf("Bir sayinin sifira bolumu tanimsizdir.İslem yapilamaz.");

        }

    }
    else{

        printf("Yanlis giris yapildi.");
    }



    return 0;
}
