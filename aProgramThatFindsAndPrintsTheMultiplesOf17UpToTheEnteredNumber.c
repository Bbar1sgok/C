#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main() {

    int limit, i = 0, satirElemani = 0;

    printf("Lutfen sorgulamak istediginiz sayiyi giriniz: ");
    scanf("%d", &limit);


    while(i <= limit){

        if( i % 17 == 0){

            printf("%5d", i);
            satirElemani++;
            if(satirElemani % 10 == 0){

                printf("\n");

            }

        }

        i++;

    }






    return 0;
}
