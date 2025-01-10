#include <stdio.h>
#include <stdlib.h>

// Checking if the number is divisible by 2
int isMultipleOfTwo(int number){
    if(number % 2 == 0){
        return 1;  
    }
    else{
        return 0;  
    }
}

// Checking if the number is divisible by 3
int isMultipleOfThree(int number){
    if(number % 3 == 0){
        return 1;  
    }
    else{
        return 0;  
    }
}

int main()
{
    int enteredNumber;

    printf("Please enter an integer:\n");
    scanf("%d", &enteredNumber);

    if(isMultipleOfTwo(enteredNumber) == 1){
        printf("The number is even.\n");
    }

    if(isMultipleOfThree(enteredNumber) == 1){
        printf("The number is divisible by 3.\n");
    }

    if(isMultipleOfTwo(enteredNumber) == 1 && isMultipleOfThree(enteredNumber) == 1){
        printf("The number is divisible by 6.\n");
    }

    return 0;
}
