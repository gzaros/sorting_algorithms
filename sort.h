#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <time.h>

#include <stdlib.h>


 /**
 * struct listint_s - A node in a doubly linked list.
 *
 * @n: The integer value stored in the node.
 * @prev: A pointer to the previous element in the list.
 * @next: A pointer to the next element in the list.
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/* function prototypes*/
void check_list(const listint_t *list);
void check_array(const int *array, size_t size);
int *rand_array(int len, int max);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);


void bubble_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void merge_sort(int *array, size_t size);

#endif
