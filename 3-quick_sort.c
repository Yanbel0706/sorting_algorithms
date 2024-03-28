#include "sort.h"

/**
 * swap - a function that swaps two integers.
 * @a: the first integer
 * @b: the second integer
 * Return: Nothing.
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - a function that partitions
 * the array using Lomuto scheme
 * @array: array to be partitioned
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 * Return: index where the pivot element is placed after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - a function that recursively sorts
 * the array using Lomuto partition scheme.
 * @array: array to be sorted
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 * Return: Nothing.
 */
void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int partition_index = lomuto_partition(array, low, high, size);

		quicksort(array, low, partition_index - 1, size);
		quicksort(array, partition_index + 1, high, size);
	}
}

/**
 * quick_sort - a function that initiates the
 * Quick Sort algorithm on the provided array
 * @array: array to be sorted
 * @size: size of the array
 * Return: Nothing.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	quicksort(array, 0, size - 1, size);
}

