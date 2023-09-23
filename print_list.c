#include <stdio.h>
#include "sort.h"

/**
 * @list: The list of integers to be printed.
  * print_list - Prints a list of integers.
 */
void print_list(const listint_t *list)
{
    int inc;

    inc = 0;
    while (list)
    {
        if (inc > 0)
            printf(", ");
        printf("%d", list->n);
        ++inc;
        list = list->next;
    }
    printf("\n");
}
