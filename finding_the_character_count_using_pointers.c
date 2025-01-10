#include <stdio.h>
#include <stdlib.h>

/* Example Output:
   Please enter a character string: (max = 100)
   Software
   The entered character string consists of 8 characters.
*/

int main()
{
    char arr[100];
    char *arr_ptr;

    printf("Please enter a character string: (max = 100) \n");
    gets(arr);

    for(arr_ptr = arr; *arr_ptr; arr_ptr++)
    {
    }

    printf("The string '%s' consists of %d characters.", arr, arr_ptr - arr);

    return 0;
}
