#include "sort.h"

/**
 * swap - a function that swaps two integers
 * @a: the first integer
 * @b: the second integer
 * Return: Nothing
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * sift_down - a function that performs the
 * sift-down operation in the heap sort algorithm.
 * @array: array to sort
 * @start: start index for sift-down
 * @end: end index for sift-down
 * @size: the size of the array
 * Return: Nothing.
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t rt = start;

	while (rt * 2 + 1 <= end)
	{
		size_t child = rt * 2 + 1;
		size_t swap_idx = rt;

		if (array[swap_idx] < array[child])
		{
			swap_idx = child;
		}

		if (child + 1 <= end && array[swap_idx] < array[child + 1])
		{
			swap_idx = child + 1;
		}

		if (swap_idx == rt)
		{
			return;
		}
		else
		{
			swap(&array[rt], &array[swap_idx]);
			print_array(array, size);
			rt = swap_idx;
		}
	}
}

/**
 * heap_sort - a function that sorts an array of
 * integers in ascending
 * order using the Heap sort algorithm
 * @array: an array to sort
 * @size: the size of the array
 * Return: Nothing.
 */
void heap_sort(int *array, size_t size)
{
	int i, j;

	if (size == 0)
	{
		return;
	}

	for (i = (size - 2) / 2; i >= 0; i--)
	{
		sift_down(array, i, size - 1, size);
	}

	for (j = size - 1; j > 0; j--)
	{
		swap(&array[j], &array[0]);
		print_array(array, size);
		sift_down(array, 0, j - 1, size);
	}
}

