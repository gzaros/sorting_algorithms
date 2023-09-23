#include "sort.h"

 /**
 * bubble_sort - Sorts an array of integers using the bubble sort algorithm.
 *using bubble sort
 * @size: The number of elements in the array.
 * @array: The array of integers to be sorted.
 */
void bubble_sort(int *array, size_t size)
{
	size_t inc, ni;
	int tmp_;

	if (!array || !size)
		return;

	inc = 0;
	while (inc < size)
	{
		for (ni = 0; ni < size - 1; ni++)
		{
			if (array[ni] > array[ni + 1])
			{
				tmp_ = array[ni];
				array[ni] = array[ni + 1];
				array[ni + 1] = tmp_;
				print_array(array, size);
			}
		}
		inc++;
	}
}
