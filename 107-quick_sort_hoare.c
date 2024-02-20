#include "sort.h"
#include <stdlib.h>

/**
 * quick_sort_hoare_helper - helper function for the quick sort function
 *
 * @start: the start of the partition being sorted
 * @array: an array of integers
 * @size: the size of the array
 */

void quick_sort_hoare_helper(int *array, size_t start,
		size_t size)
{
	size_t i, j;
	int temp, pivot;

	if (size < 2 || array == NULL || start >= size)
		return;

	i = 0;
	pivot = array[size - 1];
	j = size - 1;

	while (i < j)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;

		if (i < j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	quick_sort_hoare_helper(array, start + 1, size);
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
	quick_sort_hoare_helper(array, 0, size);
}
