#include "sort.h"

/**
 * merge_compare - Compares and merges elements in an integer array.
 *
 * @array: The integer array to sort.
 * @start: The start index.
 * @stop: The stop index.
 * @new: The output array.
 *
 * Return: void.
 */
void merge_compare(int *array, size_t start, size_t stop, int *new)
{
	size_t inc = start, inf, k, mid;

	inf = mid = (start + stop) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, stop - mid);
	for (k = start; k < stop; k++)
		if (inc < mid && (inf >= stop || array[inc] <= array[inf]))
		{

			new[k] = array[inc++];
		}
		else
		{
			new[k] = array[inf++];
		}
	printf("[Done]: ");
	print_array(new + start, stop - start);
}

/**
 * merge_sort_top_down - Sorts an integer array using a top-down recursive approach.
 *
 * @array: The integer array to sort.
 * @start: The start index.
 * @stop: The stop index.
 * @new: The output array.
 *
 * Return: void.
 */
void merge_sort_top_down(int *array, size_t start, size_t stop, int *new)
{
	size_t mid;

	mid = (start + stop) / 2;
	if (stop - start < 2)
	{
		return;
	}
	merge_sort_top_down(new, start, mid, array);
	merge_sort_top_down(new, mid, stop, array);
	merge_compare(new, start, stop, array);
}


/**
 * merge_sort - Sorts an integer array using the merge sort algorithm.
 *
 * @array: The integer array to sort.
 * @size: The size of the array.
 *
 * Return: void.
 */
void merge_sort(int *array, size_t size)
{
	int *new;
	size_t inc;


	if (!array || size < 2)
		return;

	new = malloc(sizeof(int) * size);
	if (!new)
		return;
	for (inc = 0; inc < size; inc++)
		new[inc] = array[inc];
	merge_sort_top_down(array, 0, size, new);
	free(new);
}
