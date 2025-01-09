#include <stdio.h>
#include <stdlib.h>

void bastir(int *arr, int elemanSayisi);

int main()
{
    int source_arr[100];
    int dest_arr[100];
    int elemanSayisi;
    int *source_ptr;
    int *dest_ptr;


    printf("Lutfen dizinin kac elemanli olucagini giriniz: (max = 100) \n");
    scanf("%d", &elemanSayisi);

    printf("Lutfen dizinin elemalarini giriniz:\n");
    source_ptr = source_arr;
    for(int i = 0; i < elemanSayisi; i++)
    {
        scanf("%d", source_ptr);
        source_ptr++;
    }

    printf("Girdiginiz degerler:\n");
    bastir(source_arr,elemanSayisi);

    source_ptr = source_arr;
    dest_ptr = dest_arr;

    for(int i = 0; i < elemanSayisi; i++)
    {
        *dest_ptr = *source_ptr;
        source_ptr++;
        dest_ptr++;
    }

    printf("Yedeklenen degerler:\n");
    bastir(dest_arr,elemanSayisi);


    return 0;
}

void bastir(int *arr, int elemanSayisi)
{

    for(int i = 0; i < elemanSayisi; i++)
    {
        printf("%d \n", *arr);
        arr++;

    }

}
