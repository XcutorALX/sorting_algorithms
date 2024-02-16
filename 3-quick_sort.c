#include "sort.h"
#include <stdlib.h>

/**
 * quick_sort_helper - helper function for the quick sort function
 *
 * @array: an array of integers
 * @size: the size of the array
 * @original: the original array
 * @totalSize: the size of the original array
 */

void quick_sort_helper(int *array, size_t size,
		int *original, size_t totalSize)
{
	size_t i, j;
	int temp, pivot;

	if (size < 2 || array == NULL)
		return;

	pivot = array[size - 1];
	j = 0;
	for (i = 0; i < size; i++)
	{
		if (array[i] <= pivot)
		{
			temp = array[i];
			if (i != j)
			{
				array[i] = array[j];
				array[j] = temp;
				print_array(original, totalSize);
			}
			j++;
		}
	}
	quick_sort_helper(array, j - 1, original, totalSize);
	quick_sort_helper(&(array[j]), size - (j), original, totalSize);
}

/**
 * quick_sort - sorts an array of integers using the quick sort algorithm
 *
 * @size: the size of the array
 * @array: an array of integers
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return
	quick_sort_helper(array, size, array, size);
}
