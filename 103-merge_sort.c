#include "sort.h"
/**
 * merge_sort - sorts an array of integers in ascending order using
 * the merge sort algorithm
 * @array: the array that we have to sort
 * @size: the size of the array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, k = 0, mid = size / 2;
	int *tmp;

	if (size <= 1)
		return;
	merge_sort(array, mid);
	merge_sort(array + mid, size - mid);
	printf("Merging...\n");
	tmp = malloc(size * sizeof(int));
	j = mid;
	while (i < mid && j < size)
	{
		if (array[i] < array[j])
		{
			tmp[k] = array[i];
			i++;
		}
		else
		{
			tmp[k] = array[j];
			j++;
		}
		k++;
	}
	while (i < mid)
	{
		tmp[k] = array[i];
		i++;
		k++;
	}
	while (j < size)
	{
		tmp[k] = array[j];
		j++;
		k++;
	}
	print_sides(array, size, mid);
	_memcpy(array, tmp, size);
	print_Done(array, size);
	free(tmp);
}
/**
 * print_sides - to print the two sides of the array
 * @array: the array
 * @size: the size
 * @mid: the mid of the array
 * Return: void
 */
void print_sides(int *array, int size, int mid)
{
	int a = 0;

	for (a = 0; a < size; a++)
	{
		if (a < mid)
		{
			if (a == 0)
				printf("[left]: ");
			if (a < mid - 1)
				printf("%d, ", array[a]);
			else
				printf("%d\n", array[a]);
		}
		else
		{
			if (a == mid)
				printf("[right]: ");
			if (a < size - 1)
				printf("%d, ", array[a]);
			else
				printf("%d\n", array[a]);
		}
	}
}
/**
 * print_Done - to print the last array
 * @array: the array
 * @size: the size
 * Return: void
 */
void print_Done(int *array, int size)
{
	int a = 0;

	printf("[Done]: ");
	for (a = 0; a < size; a++)
	{
		if (a < size - 1)
			printf("%d, ", array[a]);
		else
			printf("%d\n", array[a]);
	}
}
/**
 * _memcpy - copies memory area
 * @src: source string
 * @dest: destination string
 * @n: number of bytes from src
 * Return: string
 */
void _memcpy(int *dest, int *src, int n)
{
	int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
}
