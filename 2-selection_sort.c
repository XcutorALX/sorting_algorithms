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
	size_t i, j, min_index;

	if (size < 2 || array == NULL)
		return;

	i = 0;
	min_index = 0;
	while (i < size)
	{
		min_index = i;
		j = i;
		while (j < size)
		{
			if (array[j] < array[min_index])
				min_index = j;
			j++;
		}

		if (min_index != i)
		{
			temp = array[min_index];
			array[min_index] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
		i++;
	}
}
