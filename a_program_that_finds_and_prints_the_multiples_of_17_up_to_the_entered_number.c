#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main() {

    int limit, i = 0, rowElements = 0;

    printf("Please enter the number you want to check: ");
    scanf("%d", &limit);

    while(i <= limit){

        if( i % 17 == 0){

            printf("%5d", i);

            // Used to move to a new line after printing 10 values in the console.
            rowElements++; 
            if(rowElements % 10 == 0){
                printf("\n");
            }

        }

        i++;

    }

    return 0;
}
