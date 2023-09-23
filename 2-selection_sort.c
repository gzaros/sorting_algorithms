#include "sort.h"
/**
 * @array: The array to be sorted.
 * @size: The size of the array.
 * selection_sort - Sorts an array using the selection sort algorithm.
 */
 
 
void selection_sort(int *array, size_t size)
{
	size_t inc, ind, inf;
	int temp;

	if (!array || !size)
		return;
	for (inc = 0; inc < size - 1; inc++)
	{
		for (ind = size - 1, inf = inc + 1; ind > inc; ind--)
		{
			if (array[ind] < array[inf])
			{
				inf = ind;
			}
		}
		if (array[inc] > array[inf])
		{
			temp = array[inc];
			array[inc] = array[inf];
			array[inf] = temp;
			print_array(array, size);
		}
	}
}
