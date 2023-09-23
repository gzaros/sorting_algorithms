#include "sort.h"

/**
 * swap - Swaps two integer values.
 *
 * @a: Address of the first value.
 * @b: Address of the second value.
 *
 * Return: void.
 */
void swap(int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
	}
}

/**
 * bitonic_compare - Compares elements in a bitonic sequence.
 *
 * @up: True if sorting in ascending order.
 * @array: Pointer to the array.
 * @start: The start index.
 * @end: The stop index.
 */
void bitonic_compare(int up, int *array, size_t start, size_t end)
{
	size_t half = (end - start + 1) / 2, inc;

	for (inc = start; inc < start + half; inc++)
		if ((array[inc] > array[inc + half]) == up)
			swap(&array[inc], &array[inc + half]);
}

/**
 * bitonic_merge - Merges elements in a bitonic sequence.
 *
 * @up: True if sorting in ascending order.
 * @array: Pointer to the array.
 * @start: The start index.
 * @end: The stop index.
 */
void bitonic_merge(int up, int *array, size_t start, size_t end)
{
	size_t mid = (start + end) / 2;

	if (end - start < 1)
		return;
	bitonic_compare(up, array, start, end);
	bitonic_merge(up, array, start, mid);
	bitonic_merge(up, array, mid + 1, end);
}

/**
 * _bitonic_sort - Sorts an array bitonically using recursion.
 *
 * @up: True if sorting in ascending order.
 * @array: Pointer to the array.
 * @size: The length of the array.
 * @start: The start index.
 * @end: The stop index.
 */
void _bitonic_sort(int up, int *array, size_t size, size_t start, size_t end)
{
	size_t mid = (start + end) / 2;

	if (end - start < 1)
		return;
	printf("Merging [%lu/%lu] (%s):\n", end - start + 1, size,
		up ? "UP" : "DOWN");
	print_array(array + start, end - start + 1);
	_bitonic_sort(1, array, size, start, mid);
	_bitonic_sort(0, array, size, mid + 1, end);
	bitonic_merge(up, array, start, end);
	printf("Result [%lu/%lu] (%s):\n", end - start + 1, size,
		up ? "UP" : "DOWN");
	print_array(array + start, end - start + 1);
}

/**
 * bitonic_sort - Sorts an array bitonically.
 *
 * @array: Pointer to the array.
 * @size: The length of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	_bitonic_sort(1, array, size, 0, size - 1);
}
