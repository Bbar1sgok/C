#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    


    int n,i;
    double sonuc;

    printf("Lutfen hesaplamak istediginiz sayiyi giriniz: \n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){

        sonuc += 1.0/i;

    }

    printf("%.2f", sonuc);




    return 0;
}
