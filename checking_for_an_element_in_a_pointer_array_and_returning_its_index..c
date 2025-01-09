#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int main()
{
    int arr[100];
    int elemanSayisi;
    int *arr_ptr;
    int sorgulananElaman;
    bool tutucu = false;

    printf("Lutfen dizinin eleman sayisini giriniz: (max = 100) \n");
    scanf("%d", &elemanSayisi);

    printf("Lutfen dizinin elemanlarini giriniz: \n");

    arr_ptr = arr;
    for(int i = 0; i < elemanSayisi; i++)
    {
        scanf("%d", arr_ptr);
        arr_ptr++;
    }


    printf("Dizinin icinde hangi degeri sorgulatmak istersiniz: \n");
    scanf("%d", &sorgulananElaman);

    arr_ptr = arr;
    int j;
    for(j = 0; j < elemanSayisi; j++)
    {

        if(*arr_ptr == sorgulananElaman)
        {
            tutucu = true;
            break;
        }
        arr_ptr++;
    }


    if(tutucu == true)
    {
        printf("%d degeri %d. indexte bulunur.",sorgulananElaman,j);
    }
    else
    {
        printf("%d degeri dizide yer almamaktadir.", sorgulananElaman);
    }

    return 0;
}


