#include <stdlib.h>
#include <stdio.h>

 /**
 * @array: The array of integers to be printed.
 * print_array - Prints an array of integers.
 * @size: The number of elements in the @array.
 */
void print_array(const int *array, size_t size)
{
    size_t inc;

    inc = 0;
    while (array && inc < size)
    {
        if (inc > 0)
            printf(", ");
        printf("%d", array[inc]);
        ++inc;
    }
    printf("\n");
}
