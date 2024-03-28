#include "sort.h"

/**
 * get_max - a function to get the maximum value
 * in the array
 * @array: an rray
 * @size: the size of the array
 * Return: the maximum value in the array.
 */
int get_max(int array[], size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return (max);
}

/**
 * count_sort - a function that perform counting
 * sort based on the digit represented by exp
 * @array: array to be sorted
 * @size: the size of the array
 * @exp: The exponent for the current significant digit.
 * Return: Nothing.
 */
void count_sort(int *array, size_t size, int exp)
{
	int *output = (int *)malloc(size * sizeof(int));
	int count[10] = {0};
	size_t i;
	int j;

	for (i = 0; i < size; i++)
	{
		count[(array[i] / exp) % 10]++;
	}
	for (j = 1; j < 10; j++)
	{
		count[j] += count[j - 1];
	}
	for (j = size - 1; j >= 0; j--)
	{
		output[count[(array[j] / exp) % 10] - 1] = array[j];
		count[(array[j] / exp) % 10]--;
	}
	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}
	free(output);
}

/**
 * radix_sort - a function to implement Radix sort using
 * LSD algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: Nothing.
 */
void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size), exp;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp);
		print_array(array, size);
	}
}

