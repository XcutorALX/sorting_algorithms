#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * selection_sort - sorts an array using the selection sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */

void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i, j;

	if (size < 2)
		return;

	if (array == NULL)
		return;

	i = 0;
	while (i < size)
	{
		for (j = i; j < size - 1 && array[i] <= array[j]; j++)
			;

		if (array[i] > array[j])
		{
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
		else
			i++;
	}
}
