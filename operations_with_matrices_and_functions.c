#include <stdio.h>
#include <stdlib.h>
#define A 3
#define B 2

// Function to initialize the matrix by taking user input
void init_table(int matrix[A][B])
{
    int i, j;
    printf("Please note that the matrix is %dx%d in size.\n", A, B);
    printf("Please fill in the matrix: \n");

    for (i = 0; i < A; i++)
    {
        for (j = 0; j < B; j++)
        {
            scanf("%d", &matrix[i][j]); 
        }
    }
}

// Function to print the matrix in a formatted way
void print_table(int matrix[A][B])
{
    int i, j;

    printf("Your table looks like this: \n");

    for (i = 0; i < A; i++)
    {
        for (j = 0; j < B; j++)
        {
            printf("%4d", matrix[i][j]); 
        }
        printf("\n");
    }
}

// Function to calculate the minimum, maximum, and sum of all elements in the matrix
void calculate(int matrix[A][B], int *min, int *max, int *sum)
{
    int i, j;

    
    *min = matrix[0][0];
    *max = matrix[0][0];
    *sum = 0;

    
    for (i = 0; i < A; i++)
    {
        for (j = 0; j < B; j++)
        {
            if (*min > matrix[i][j])
            {
                *min = matrix[i][j]; 
            }
            if (*max < matrix[i][j])
            {
                *max = matrix[i][j]; 
            }
            *sum += matrix[i][j]; 
        }
    }

    
    printf("The smallest value in the matrix is: %d\n", *min);
    printf("The largest value in the matrix is: %d\n", *max);
    printf("The sum of all values in the matrix is: %d\n", *sum);
}

int main()
{
    int min, max, sum = 0;
    int matrix[A][B];

    // Call the function to initialize the matrix
    init_table(matrix);

    // Call the function to display the matrix
    print_table(matrix);

    // Call the function to calculate and print min, max, and sum
    calculate(matrix, &min, &max, &sum);

    return 0;
}
