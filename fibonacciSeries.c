#include <stdio.h>
#include <stdlib.h>

int main() {
    /*
        Kullanıcının girdiği sayı kadar Fibonacci saysını hesaplayıp ekrana bastırma
        Fibonacci serisi: 0, 1, 1, 2, 3, 5, 8, 13, 21
    */


    int girilenSayi, deger1 = 0, deger2 = 1, i, sonrakiDeger;

    printf("Fibonacci serisinin kaca kadar hesaplanmasini istiyorsunuz:\n");
    scanf("%d", &girilenSayi);

    for(i = 1; i <=n; i++){

            if(i == 1){

                printf("%d", deger1);
                continue;
            }
            if(i == 2){

                printf("%d", deger2);
                continue;
            }

        sonrakiDeger = deger1 + deger2;
        deger1 = deger2;
        deger2 = sonrakiDeger;
        printf("%d", sonrakiDeger);

    }



    }


    return 0;
}
