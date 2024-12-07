#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    
    // Kullanıcıdan bir n değeri girmesini isteyin 1 + 1/2 + 1/3 + 1/n değerini hesaplayınız    

   int n,i;
    double sonuc;

    do{
        printf("Lutfen pozitif bir tam sayi giriniz: \n");
        scanf("%d ", &n);

        for(i = 1; i <= n; i++){

            sonuc += 1.0/i;
        }

    }while(n < 1);

    printf("Sonuc: %.2f", sonuc);

    return 0;
}
