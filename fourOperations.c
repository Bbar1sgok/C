#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main() {

    char islem;
    float sayi1, sayi2;

    printf("Lutfen yapmak istediginiz islemi seciniz:\n");
    printf(" Toplama : +\n Cikarma: -\n Bolme : / \n Carpma: * \n");
    scanf("%c", &islem);

    printf("Lutfen birinci sayiyi giriniz: \n");
    scanf("%f", &sayi1);
    printf("Lutfen  ikinci sayiyi giriniz: \n");
    scanf("%f", &sayi2);

    switch(islem){

    case '+':
        printf("%.2f ile %.2f  sayisinin toplami: %.2f", sayi1, sayi2, sayi1+sayi2);
        break;
    case '-':
        printf("%.2f ile %.2f sayisinin farki: %.2f", sayi1, sayi2, sayi1-sayi2);
        break;
    case '/':
        if(sayi2 != 0){

            printf("%.2f ile %.2f sayisinin bolumu: %.2f", sayi1, sayi2, sayi1/sayi2);
            break;
        }
        else if(sayi2 == 0 && sayi1 != 0){

            printf("Bir sayinin sifira bolumu tanimsizliklik dogurur.");
            break;
        }
        else if( sayi1 == 0 && sayi2 == 0){

            printf("Sifirin sifira bolumu belirsizlik dogurur.");
            break;
        }

     case'*':
         printf("%.2f ile %.2f sayisinin carpimi: %.2f", sayi1, sayi2, sayi1*sayi2);
         break;
     default:
        printf("Gecerli bir islem girmediniz.");

    }





    return 0;
}
