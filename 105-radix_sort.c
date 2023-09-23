#include "sort.h"

/**
 * get_digit - Retrieves a digit from an integer.
 *
 * @number: The integer.
 * @digit: The position of the digit to retrieve.
 *
 * Return: The value of the digit at the given position.
 */
int get_digit(long number, int digit)
{
	long inc = 0L, pow = 1L, ret;

	for (inc = 0; inc < digit; inc++)
		pow *= 10L;
	ret = ((number / pow) % 10);
	return (ret);
}

/**
 * radix_pass - Sorts an integer array using the radix sort algorithm.
 *
 * @array: The integer array to sort.
 * @size: The size of the array.
 * @digit: The current digit to check.
 * @new_array: The target array of the same size.
 *
 * Return: void.
 */
int radix_pass(int *array, ssize_t size, int digit, int *new_array)
{
	ssize_t inc;
	int buckets[10] = {0};

	for (inc = 0; inc < size; inc++)
		buckets[get_digit(array[inc], digit)]++;
	for (inc = 1; inc <= 9; inc++)
		buckets[inc] += buckets[inc - 1];
	for (inc = size - 1; inc > -1; inc--)
		new_array[buckets[get_digit(array[inc], digit)]-- - 1] = array[inc];
	return (1);
}

/**
 * radix_sort - Sorts an integer array using the radix sort algorithm.
 *
 * @size: The size of the array.
 * @array: The integer array to sort.
 *
 * Return: The gap size.
 */
void radix_sort(int *array, size_t size)
{
	int *old_array, *new_array, *temp_ptr, *ptr, max = 0;
	size_t inc, sd = 1;

	if (!array || size < 2)
		return;

	for (inc = 0; inc < size; inc++)
		if (array[inc] > max)
			max = array[inc];
	while (max /= 10)
		sd++;
	old_array = array;
	new_array = ptr = malloc(sizeof(int) * size);
	if (!new_array)
		return;
	for (inc = 0; inc < sd; inc++)
	{
		radix_pass(old_array, (ssize_t)size, inc, new_array);
		temp_ptr = old_array;
		old_array = new_array;
		new_array = temp_ptr;
		print_array(old_array, size);
	}
	for (inc = 0; inc < size; inc++)
		array[inc] = old_array[inc];
	free(ptr);
}
