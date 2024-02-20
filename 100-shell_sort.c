#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * shell_sort - sorts an array using the shell sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, sorted;

	i = 1;
	while (i < (size - 1) / 3)
		i = 3 * i + 1;

	while (i > 1)
	{
		sorted = 0;
		while (!sorted)
		{
			sorted = 1;
			for (j = 0; j + i < size; j++)
			{
				if (array[j] > array[j + i])
				{
					temp = array[j];
					array[j] = array[j + i];
					array[j + i] = temp;
					sorted = 0;
				}
			}
		}
		i = (i - 1) / 3;
		print_array(array, size);
	}
	insertion_sort(array, size);
}

/**
 * insertion_sort - sorts an array with the insertion sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */

void insertion_sort(int *array, size_t size)
{
	size_t i;
	int temp, sorted;

	if (array == NULL || size < 2)
		return;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				i = size;
				sorted = 0;
			}
		}
	}
	print_array(array, size);
}
