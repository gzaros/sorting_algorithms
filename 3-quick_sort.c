#include "sort.h"

/**
 * swap - Swaps two integer values.
 * @size: The size of the array.
 * @array: The integer array containing the values.
 * @a: Pointer to the first value.
 * @b: Pointer to the second value.
 * Returns: void
 */
void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}

/**
 * @array: The integer array to partition.
 * lomuto_partition - Partitions an integer array.
 * @size: The size of the array.
 * @hi: The high index of the partitioning range.
 * @lo: The low index of the partitioning range.
 *
 * Returns: void
 */
 
size_t lomuto_partition(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	int inc, inf, pivot = array[hi];

	for (inc = inf = lo; inf < hi; inf++)
		if (array[inf] < pivot)
			swap(array, size, &array[inf], &array[inc++]);
	swap(array, size, &array[inc], &array[hi]);

	return (inc);
}

/**
 * @array: The integer array to be sorted.
 * quicksort - Sorts an integer array using the Lomuto partitioning scheme.
 * @size: The size of the array.
 * @hi: The high index of the sorting range.
 * @lo: The low index of the sorting range.
 *
 * Returns: void
 */
 
void quicksort(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	if (lo < hi)
	{
		size_t p = lomuto_partition(array, size, lo, hi);

		quicksort(array, size, lo, p - 1);
		quicksort(array, size, p + 1, hi);
	}
}

/**
 * quick_sort - Sorts an integer array using the quicksort algorithm.
 * @array: The integer array to be sorted.
 * @size: The size of the array.
 *
 * Returns: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);
}
