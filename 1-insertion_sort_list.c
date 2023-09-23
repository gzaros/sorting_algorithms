#include "sort.h"

/**
 * @a: Address of the first node to be swapped.
 * @b: Address of the second node to be swapped.
 * swap - Swaps two nodes in a doubly-linked list.
 * Return: void
 */
 
void swap(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;

}

 /**
 * @list: Address of a pointer to the head node of the list.
 * insertion_sort_list - Sorts a doubly-linked list using insertion sort.
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *inc, *inf;

	if (!list || !*list || !(*list)->next)
		return;
	inc = (*list)->next;
	while (inc)
	{
		inf = inc;
		inc = inc->next;
		while (inf && inf->prev)
		{
			if (inf->prev->n > inf->n)
			{
				swap(inf->prev, inf);
				if (!inf->prev)
					*list = inf;
				print_list((const listint_t *)*list);
			}
			else
				inf = inf->prev;
		}

	}
}
