#include "sort.h"

/**
 * cocktail_sort_list - a function that sorts a doubly
 * linked list of integers in ascending order using the
 * cocktail Shaker sort algorithm.
 * @list:  a pointer to a pointer to the head of the list
 * Return: Nothing.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *ptr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do {
		swapped = 0;
		for (ptr = *list; ptr->next != NULL; ptr = ptr->next)
		{
			if (ptr->n > ptr->next->n)
			{
			if (ptr->prev != NULL)
				ptr->prev->next = ptr->next;
			else
				*list = ptr->next;

			if (ptr->next->next != NULL)
				ptr->next->next->prev = ptr;
			ptr->next->prev = ptr->prev;
			ptr->prev = ptr->next;
			ptr->next = ptr->next->next;
			ptr->prev->next = ptr;
			swapped = 1;
			print_list(*list);
			}
		}
		if (swapped == 0)
			break;
		swapped = 0;
		for (; ptr->prev != NULL; ptr = ptr->prev)
		{
			if (ptr->n < ptr->prev->n)
			{
				if (ptr->next != NULL)
					ptr->next->prev = ptr->prev;
				ptr->prev->next = ptr->next;
				if (ptr->prev->prev != NULL)
					ptr->prev->prev->next = ptr;
				ptr->next = ptr->prev;
				ptr->prev = ptr->next->prev;
				ptr->next->prev = ptr;
				if (ptr->prev == NULL)
					*list = ptr;
				swapped = 1;
				print_list(*list);
			}
		}
	} while (swapped);
}

