#include "sort.h"
#include <stdlib.h>

/**
 * quick_sort_hoare_helper - helper function for the quick sort function
 *
 * @start: the start of the partition being sorted
 * @array: an array of integers
 * @o_array: original array
 * @o_size: original size
 * @size: the size of the array
 */

void quick_sort_hoare_helper(int *array, size_t size,
		int *o_array, size_t o_size)
{
	size_t i, j, pivotIndex;
	int temp, pivot;

	if (size < 2 || array == NULL)
		return;

	i = 0;
	pivotIndex = size - 1;
	pivot = array[pivotIndex];
	j = size - 1;

	while (i < j)
	{
		while (array[i] <= pivot)
			i++;
		while (array[j] > pivot)
			j--;

		if (i < j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(o_array, o_size);
			if (j == size - 1)
				pivotIndex = i;
		}
	}
	temp = array[pivotIndex];
	array[pivotIndex] = array[j];
	array[j] = temp;
	quick_sort_hoare_helper(array, j, o_array, o_size);
	quick_sort_hoare_helper(&(array[j + 1]), size - j, o_array, o_size);
}

/**
 * quick_sort_hoare - sorts an array of integers using the quick sort algorithm
 *
 * @size: the size of the array
 * @array: an array of integers
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;
	quick_sort_hoare_helper(array, size, array, size);
}
