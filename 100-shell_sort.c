#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * shell_sort: sorts an array using the shell sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, loop, prevloop;
	int temp;

	i = 1;
	while (i < (size - 1) / 3)
		i = 3 * i + 1;

	while (i >= 1)
	{
		loop  = 0;
		while (loop < size)
		{
			prevloop = loop;
			if (loop + i >= size)
			      loop = size;	
			for (j = prevloop; j + i < size && (j - prevloop) < i; j++)
			{	
				if (array[j] > array[j + i])
				{
					temp = array[j + i];
					array[j + i] = array[j];
					array[j] = temp;
				}
				loop = j + i + 1;
			}
			prevloop = loop;
		}
		i = (i - 1) / 3;
		print_array(array, size);
	}
	insertion_sort(array, size);
}

/**
 * insertion_sort_list - sorts an array with the insertion sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */

void insertion_sort(int *array, size_t size)
{
	size_t i, swapped;
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
				swapped++;
				sorted = 0;
			}
		}
	}
	printf("%ld\n", swapped);
}
