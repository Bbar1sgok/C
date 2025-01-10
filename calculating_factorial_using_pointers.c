#include <stdio.h>
#include <stdlib.h>

void calculateFactorial(int *enteredNumber);

int main()
{
    // Calculate the factorial of a positive integer N using a function and pointer

    int enteredNumber;

    printf("Please enter the number for which you want to calculate the factorial: \n");
    scanf("%d", &enteredNumber);

    calculateFactorial(&enteredNumber);

    return 0;
}

void calculateFactorial(int *enteredNumber)
{
    int factorial = 1;

    for(int i = *enteredNumber; i >= 1; i--)
    {
        factorial = i * factorial;
    }

    printf("The factorial of the entered number is: %d", factorial);
}
