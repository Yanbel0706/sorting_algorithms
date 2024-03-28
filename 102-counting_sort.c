#include "sort.h"

/**
 * counting_sort - a function that sorts an array
 * of integers in ascending order
 * using Counting sort
 * @array: array to be sorted
 * @size: size of the array
 * Return: Nothing.
 */
void counting_sort(int *array, size_t size)
{
	int *c_array, *s_array;
	size_t i;
	int m = 0;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > m)
			m = array[i];
	}
	c_array = malloc(sizeof(int) * (m + 1));
	if (c_array == NULL)
		return;
	for (i = 0; i <= (size_t)m; i++)
	{
		c_array[i] = 0;
	}
	for (i = 0; i < size; i++)
	{
		c_array[array[i]]++;
	}
	print_array(c_array, m + 1);
	for (i = 1; i <= (size_t)m; i++)
	{
		c_array[i] += c_array[i - 1];
	}

	s_array = malloc(sizeof(int) * size);
	if (s_array == NULL)
	{
		free(c_array);
		return;
	}
	for (i = 0; i < size; i++)
	{
		s_array[c_array[array[i]] - 1] = array[i];
		c_array[array[i]]--;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = s_array[i];
	}

	free(c_array);
	free(s_array);
}

