#include <stdio.h>
#include <stdlib.h>


int main()
{
    // 10 tane integer tipinde elemani alan bir dizi tanimlayin ve bu elemanlari kullanicinin girmesini saðlayin
    // Pointer yardimiyla dizideki eleamanlarin en buyuk ve en en kücük degerini bulun


    int arr[10];
    int *arr_ptr;
    int max, min;

    printf("Lutfen max, min  degerlerini ogrenmek istediginiz 10 tamsayi giriniz: \n");

    arr_ptr = arr;

    for(int i = 0; i < 10; i++)
    {
        scanf("%d", arr_ptr);
        arr_ptr++;

    }

    arr_ptr = arr;
    max = *arr_ptr;
    min = *arr_ptr;

    for(int i = 0; i < 10; i++)
    {

        if(max < *arr_ptr)
        {
            max = *arr_ptr;
        }

        if( min > *arr_ptr)
        {
            min = *arr_ptr;
        }

        arr_ptr++;
    }

    printf("Girilen 10 deger arasindaki en buyuk deger: %d \n", max);
    printf("Girilen 10 deger arasindaki en kucuk deger: %d \n", min);




    return 0;
}


