#include <stdio.h>
#include <stdlib.h>

void adresini_degistir(int *add1, int *add2)
{
    int gecici;

    gecici = *add1;
    *add1 = *add2;
    *add2 = gecici;

}

int main()
{
    int a = 0, b = 20;

    printf("Fonksiyona girmeden once a nin degeri %d, b nin degeri %d \n",a,b);

    adresini_degistir(&a, &b);

    printf("Fonksiyon uygulandiktan sonra a nin degeri %d, b nin degeri %d \n", a, b);


    return 0;
}
