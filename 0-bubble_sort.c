#include "sort.h"
#include <stdlib.h>

/**
 * bubble_sort - sorts an array with the bubble sort algorithm
 *
 * @array: an array of integers
 * @size: the size of the array
 */

void bubble_sort(int *array, size_t size)
{
	int temp, sorted;
	size_t i;

	if (size < 2)
		return;

	if (array == NULL)
		return;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
				sorted = 0;
			}
		}
	}
}
