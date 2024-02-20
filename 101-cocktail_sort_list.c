#include "sort.h"

/**
 * cocktail_sort_list - sorts a linked list using
 * the cocktail shaker algorithm
 *
 * @list: a double linked list to be sorted
 */

void cocktail_sort_list(listint_t **list)
{
	int sorted = 0;
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = *list;
	while (current->prev != NULL)
		current = current->prev;
	while (!sorted)
	{
		sorted = 1;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				temp = current->next;
				if (current->prev == NULL)
					*list = temp;
				sorted = swap(current, temp);
				print_list(*list);
			}
			else
				current = current->next;
		}
		if (sorted)
			return;
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				temp = current->prev;
				if (temp->prev == NULL)
					*list = current;
				sorted = swap(temp, current);
				print_list(*list);
			}
			else
				current = current->prev;
		}
	}
}

/**
 * swap - a function that swaps two nodes of a linked list
 *
 * @firstNode: a node to be swapped
 * @secondNode: the second node
 *
 * Return: 0 on success 1 on failure
 */

int swap(listint_t *firstNode, listint_t *secondNode)
{
	firstNode->next = secondNode->next;
	if (firstNode->prev != NULL)
		firstNode->prev->next = secondNode;
	if (secondNode->next != NULL)
		secondNode->next->prev = firstNode;
	secondNode->next = firstNode;
	secondNode->prev = firstNode->prev;
	firstNode->prev = secondNode;

	return (0);
}
