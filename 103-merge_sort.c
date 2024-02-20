#include "sort.h"
#include <stddef.h>
#include <stdio.h>

/**
 * merge_sort - sorts an array using the merge sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */

void merge_sort(int *array, size_t size)
{
	split(array, size);
}

/**
 * split - splits an array into two at the mid point
 *
 * @array: the array to be split
 * @size: the size of the array
 *
 * Return: the split array
 */

int *split(int *array, size_t size)
{
	size_t mid;
	int *dup, *first, *sec;

	if (size == 1)
		return (array);

	dup = copy(array, size);
	mid = size / 2;

	first = split(dup, mid);
	sec = split(&(dup[mid]), size - mid);
	merge(first, sec, array, size);
	free(dup);
	return (array);
}

/**
 * merge - merges array in sorted manner
 *
 * @first: the first section
 * @sec: the second section
 * @parent: the parent array
 * @size: the size of the parent array
 */

void merge(int *first, int *sec, int *parent, size_t size)
{
	size_t firstSize, secSize, i, j, k;

	printf("Merging...\n");
	printf("[left]: ");

	firstSize = size / 2;
	secSize = size - firstSize;

	print_array(first, firstSize);
	printf("[right]: ");
	print_array(sec, secSize);
	i = 0;
	j = 0;
	k = 0;
	while (i < firstSize || j < secSize)
	{
		if (i < firstSize && j < secSize)
		{
			if (first[i] < sec[j])
			{
				parent[k] = first[i];
				i++;
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
			i++;
		}
		else
		{
			parent[k] = sec[j];
			j++;
		}
		k++;
	}
	printf("[Done]: ");
	print_array(parent, size);
}

/**
 * copy - creates a copy of an array of integers
 *
 * @array: the array to copy
 * @size: the size of the array
 *
 * Return: a pointer to the copy of the array
 */

int *copy(int *array, size_t size)
{
	size_t i;
	int *arrCpy;

	arrCpy = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
		arrCpy[i] = array[i];

	return (arrCpy);
}
