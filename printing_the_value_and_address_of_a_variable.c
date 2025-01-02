#include <stdio.h>
#include <stdlib.h>


int main()
{
    char karakter = 'B';
    int integer_degerim = 1;
    float float_sayim = 5.43;
    double double_sayim = 2321321321321321323213213213321;

    printf("Karakterim : %c, Karakterimin Adresi: %d \n", karakter, &karakter);
    printf("Integer degerim : %d, Integer Adresi: %d \n", integer_degerim, &integer_degerim);
    printf("Float degerim : %f, Float Adresi: %d \n", float_sayim, &float_sayim);
    printf("Double degerim : %lf, Double Adresi: %d \n", double_sayim, &double_sayim);


    return 0;
}
