#include <stdio.h>
#include <stdlib.h>

int main() {
    /*
        Bir telefon şirketi telefonda 3 dakikaya kadar olan konuşmanın ücretini
        4 TL olarak belirlemiştir. Ancak şirket konuşma süresi 3 dakikayı geçtiği durumda,
        bundan sonraki her dakika için ek olarak 1 TL almaktadır.
        Telefon görüşmesinin süresini dakika cinsinden girdi olarak alan ve
        konuşmanın ücretini hesaplayan bir c programı yazınız.
    */

    int sure,ucret;

    printf("Lutfen telefon konusma surenizi giriniz (dakika cinsinden):\n");
    scanf("%d", &sure);

    if(sure <= 3){

        ucret = 4;
    }
    else{

        ucret = 4 + (sure - 3) * 1;
    }

    printf("Toplam odemeniz gereken fatura: %d", ucret);

    
    return 0;
}
