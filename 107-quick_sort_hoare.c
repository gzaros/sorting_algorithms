#include "sort.h"

/**
 * swap - Swaps two integer values in an array.
 *
 * @array: The integer array.
 * @size: The size of the array.
 * @a: Address of the first value.
 * @b: Address of the second value.
 *
 * Return: void.
 */
void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
	}
	print_array((const int *)array, size);
}

/**
 * hoare_partition - Partitions an integer array for sorting.
 *
 * @array: The integer array to sort.
 * @size: The size of the array.
 * @lo: The low index of the sorting range.
 * @hi: The high index of the sorting range.
 *
 * Return: void.
 */
size_t hoare_partition(int *array, ssize_t size, ssize_t lo, ssize_t hi)
{
	ssize_t inc = lo - 1, j = hi + 1;
	int pivot = array[hi];

	while (inc < size)
	{
		while (array[++inc] < pivot)
			;
		while (array[--j] > pivot)
			;
		if (inc < j)
			swap(array, size, &array[inc], &array[j]);
		else if (inc >= j)
			break;
	}
	return (inc);
}

/**
 * quickSort - Sorts an integer array using the Hoare partitioning scheme.
 *
 * @array: The integer array to sort.
 * @size: The size of the array.
 * @lo: The low index of the sorting range.
 * @hi: The high index of the sorting range.
 *
 * Return: void.
 */
void quicksort(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	if (lo < hi)
	{
		size_t p = hoare_partition(array, size, lo, hi);

		quicksort(array, size, lo, p - 1);
		quicksort(array, size, p, hi);
	}
}

/**
 * quick_sort_hoare - Calls the quicksort algorithm using the Hoare partitioning scheme.
 *
 * @array: The integer array to sort.
 * @size: The size of the array.
 *
 * Return: void.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort(array, size, 0, size - 1);
}
