#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Kullaniciya kaç elemanli bir sayi dizisi olusturmak istedigini sorun
    // Pointer kullanarak elemanlari tek tek alin ve console a bastirin

    int arr[100];
    int n;
    int *ptr;

    ptr = arr;

    printf("Dizi kac elemanli olsun: \n");
    scanf("%d", &n);

    printf("Elamanlari giriniz: \n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d",ptr);
        ptr++;
    }

    ptr = arr;
    printf("Girmis oldugunuz degerler: \n");

    for(int i = 0; i < n; i++)
    {
        printf("%d \n",*ptr); //*ptr adresin gösterdiği değeri bastirir  sadece ptr adresi bastirir.
        ptr++;
    }


    return 0;
}
