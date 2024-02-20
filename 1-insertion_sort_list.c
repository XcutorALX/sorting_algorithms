#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list
 *
 * @list: the list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current, *ptr, *head;

	if (list == NULL)
		return;
	if (*list == NULL)
		return;
	current = *list;
	while (current->prev != NULL)
		current = current->prev;
	head = current;
	if (current->next == NULL)
		return;
	while (current->next != NULL)
	{
		ptr = current->next;
		if (current->n <= ptr->n)
			current = current->next;
		else
		{
			temp = ptr->next;
			ptr->next = current;
			current->next = temp;
			if (temp != NULL)
				temp->prev = current;
			ptr->prev = current->prev;
			if (current->prev != NULL)
				current->prev->next = ptr;
			current->prev = ptr;
			if (current == head)
			{
				head = ptr;
			}
			current = head;
			print_list(head);
		}
	}
	*list = head;
}
