#include "sort.h"

/**
 * get_max_gap - Calculates the largest Knuth Sequence gap for a given size.
 * @size: The size of the array.
 * Returns: The gap size.
 */
size_t get_max_gap(size_t size)
{
	size_t nb;

	nb = 1;
	while (nb < size)
		nb = nb * 3 + 1;
	return ((nb - 1) / 3);
}

/**
 * Perform a Shell Sort on an integer array.
 *
 * @array: Pointer to the integer array to be sorted.
 * @size: The number of elements in the array.
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, inc, inf;
	int temp;

	if (!array || !size)
		return;


	for (gap = get_max_gap(size); gap; gap = (gap - 1) / 3)
	{
		for (inc = gap; inc < size; inc++)
		{
			temp = array[inc];
			for (inf = inc; inf > gap - 1 && array[inf - gap] > temp; inf -= gap)
			{
				array[inf] = array[inf - gap];
			}
			array[inf] = temp;
		}
		print_array(array, size);
	}
}
