#include "sort.h"
#include <stddef.h>

/**
 * counting_sort - sorts an array using the counting sort
 * algorithm
 *
 * @array: an array of integers to be sorted
 * @size: the size of the array
 */

void counting_sort(int *array, size_t size)
{
	int max_number, *counting_array, prev, *copyArray;
	size_t i;

	if (array == NULL || size < 2)
		return;

	max_number = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max_number)
			max_number = array[i];
	}

	counting_array = malloc(sizeof(int) * (max_number + 1));
	copyArray = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
	{
		copyArray[i] = array[i];
		counting_array[array[i]] = 0;
	}
	for (i = 0; i < size; i++)
		counting_array[copyArray[i]]++;
	prev = counting_array[0];
	for (i = 1; i < ((size_t)max_number + 1); i++)
	{
		counting_array[i] += prev;
		prev = counting_array[i];
	}
	print_array(counting_array, max_number + 1);
	for (i = 0; i < size; i++)
	{
		array[counting_array[copyArray[i]] - 1] = copyArray[i];
		counting_array[copyArray[i]]--;
	}
	free(counting_array);
	free(copyArray);
}
