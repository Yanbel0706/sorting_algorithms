#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order using
 * the selection sort algorithm
 * @array: the array that we have to sort
 * @size: the size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, k = 0, ind;
	int tmp, a;

	if (size == 0)
		return;
	for (i = 0; i < size - 1; i++)
	{
		tmp = array[i];
		a = 0;
		for (j = i + 1; j < size; j++)
		{
			if (tmp > array[j])
			{
				tmp = array[j];
				ind = j;
				a = 1;
			}
		}
		if (a == 1)
		{
			tmp = array[i];
			array[i] = array[ind];
			array[ind] = tmp;
			for (k = 0; k < size; k++)
			{
				printf("%d", array[k]);
				if (k < size - 1)
					printf(", ");
				else
					printf("\n");
			}
		}
	}
}
