#include "sort.h"
#include <stddef.h>
#include <stdio.h>

/**
 * bitonic_sort - sorts an array of integers using the bitonic
 * sort algorithm
 *
 * @size: the size of the array
 * @array: an array of integers
 */

void bitonic_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;
	bitonic_split(array, size, size, 1);
}

/**
 * bitonic_split - splits an array into two at the mid point
 * using following the bitonic sort splitting method
 *
 * @array: the array to be split
 * @size: the size of the array
 * @o_size: the size of the original array
 * @state: 1 for up and 0 for down
 *
 * Return: the split array
 */

int *bitonic_split(int *array, size_t size, size_t o_size, int state)
{
	size_t mid, i;
	int *dup, *first, *sec;

	if (size == 1)
		return (array);

	printf("Merging [%ld/%ld] ", size, o_size);
	if (state == 1)
		printf("(UP):\n");
	else
		printf("(DOWN):\n");
	print_array(array, size);

	dup = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
		dup[i] = array[i];

	mid = size / 2;
	first = bitonic_split(dup, mid, o_size, 1);
	sec = bitonic_split(&(dup[mid]), size - mid, o_size, 0);
	bitonic_merge(first, sec, array, size, o_size, state);
	free(dup);
	return (array);
}

/**
 * bitonic_merge - merges array in sorted manner
 *
 * @first: the first section
 * @sec: the second section
 * @parent: the parent array
 * @size: the size of the parent array
 * @o_size: the size of the original_array
 * @state: 1 for ascending and 0 for descending
 */

void bitonic_merge(int *first, int *sec, int *parent,
		size_t size, size_t o_size, int state)
{
	printf("Result [%ld/%ld] ", size, o_size);
	if (state == 1)
	{
		mergeUp(first, sec, parent, size);
		printf("(UP):\n");
	}
	else
	{
		mergeDown(first, sec, parent, size);
		printf("(DOWN):\n");
	}
	print_array(parent, size);
}

/**
 * mergeUp - merges two arrays of integers in ascending order
 *
 * @first: the first array
 * @sec: the second array
 * @parent: the parent array
 * @size: the size of the array
 */

void mergeUp(int *first, int *sec, int *parent, size_t size)
{
	size_t firstSize, i, j, k;

	firstSize = size / 2;
	i = 0;
	j = size - firstSize - 1;
	k = 0;
	while (i < firstSize || j < size)
	{
		if (i < firstSize && j < (size - firstSize))
		{
			if (first[i] < sec[j])
			{
				parent[k] = first[i];
				i++;
			}
			else
			{
				parent[k] = sec[j];
				if (j == 0)
					j = size;
				else
					j--;
			}
		}
		else if (i < firstSize)
		{
			parent[k] = first[i];
			i++;
		}
		else
		{
			parent[k] = sec[j];
			if (j == 0)
				j = size;
			else
				j--;
		}
		k++;
	}
}

/**
 * mergeDown - merges two arrays of integers in descending order
 *
 * @first: the first array
 * @sec: the second array
 * @parent: the parent array
 * @size: the size of the array
 */

void mergeDown(int *first, int *sec, int *parent, size_t size)
{
	size_t firstSize, i, j, k;

	firstSize = size / 2;
	i = firstSize - 1;
	j = 0;
	k = 0;
	while (i < firstSize || j < (size - firstSize))
	{
		if (i < firstSize && j < (size - firstSize))
		{
			if (first[i] > sec[j])
			{
				parent[k] = first[i];
				if (i == 0)
					i = firstSize;
				else
					i--;
			}
			else
			{
				parent[k] = sec[j];
				j++;
			}
		}
		else if (i < firstSize)
		{
			parent[k] = first[i];
			if (i == 0)
				i = firstSize;
			else
				i--;
		}
		else
		{
			parent[k] = sec[j];
			j++;
		}
		k++;
	}
}
