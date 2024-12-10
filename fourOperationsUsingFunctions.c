#include <stdio.h>
#include <stdlib.h>

void dortIslem(char islemTutucu, int girilenSayi1, int girilenSayi2){

    //Dort Islem Fonksiyonu
    switch(islemTutucu){

        case '+':

            printf("Iki sayinin toplaminin sonucu: %d", girilenSayi1 + girilenSayi2);
            break;

        case '-':

            printf("Iki sayinin farkinin sonucu: %d", girilenSayi1 - girilenSayi2);
            break;

        case '*':

            printf("Iki sayinin carpiminin sonucu: %d", girilenSayi1 * girilenSayi2);
            break;

        case '/':{

            if(girilenSayi1 == 0 && girilenSayi2 == 0){

                printf("Sıfırın sıfıra bolumu matematikte belirsizlik oluşturur.");
                break;

            }
            else if(girilenSayi1 == 0 && girilenSayi2 != 0){

                printf("Sonuc: %d", girilenSayi1 / girilenSayi2);
                break;

            }
            else{

                printf("Sonuc: %d", girilenSayi1 / girilenSayi2);
                break;

            }
         default:
            printf("Hatali islem girisi yapildi.");
            break;


        }

    }

}


int main()
{

    /*
        Klavyeden girilen iki tamsayının toplamını, farkını, çarpımını ve bölümünü gerçekleştiren C programını fonksiyonla yazınız.
    */


    int girilenSayi1, girilenSayi2;
    char islemTutucu;

    printf("Lutfen yapmak istediginiz islemi seciniz: Toplama(+), Cikarma(-), Bolme(/), Carpma(*) \n");
    scanf(" %c", &islemTutucu);

    printf("Lutfen birinci sayiyi giriniz: \n");
    scanf("%d", &girilenSayi1);

    printf("Lutfen ikinci sayiyi giriniz: \n");
    scanf("%d", &girilenSayi2);


    dortIslem(islemTutucu,girilenSayi1,girilenSayi2);




    return 0;
}
