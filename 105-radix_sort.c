#include "sort.h"
#include <stdio.h>

/**
 * radix_sort - sorts an array of integers using the radix
 * sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */

void radix_sort(int *array, size_t size)
{
	size_t i, digits;
	int maxNumber;

	if (size < 2 || array == NULL)
		return;
	maxNumber = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > maxNumber)
			maxNumber = array[i];
	}
	if (maxNumber == 0)
		digits = 1;
	else
	{
		for (digits = 0; maxNumber != 0; digits++, maxNumber /= 10)
			;
	}

	for (i = 0; i < digits; i++)
	{
		counting_sort_radix(array, size, i + 1);
		print_array(array, size);
	}
}


/**
 * significant_digit - finds the nth digit from the end of the number
 *
 * @place: the place of the digit to find ranging from 1 to infinity
 * @num: the number to search
 *
 * Return: returns the nth digit
 */

int significant_digit(size_t place, int num)
{
	size_t i, temp;

	temp = num;
	for (i = 1; i < place; i++)
	{
		if (temp == 0)
			return (0);
		temp /= 10;
	}

	return (temp % 10);
}

/**
 * counting_sort_radix - implementation of the counting sort algorithm
 * alongsisde radix sort algorithm
 *
 * @array: the array being sorted
 * @size: the size of the array
 * @place: the current place being sorted
 */

void counting_sort_radix(int *array, size_t size, size_t place)
{
	int *counting_array, prev, *copyArray, num, digit;
	size_t i;

	if (array == NULL || size < 2)
		return;

	counting_array = malloc(sizeof(int) * 10);
	copyArray = malloc(sizeof(int) * size);
	for (i = 0; i < 10; i++)
		counting_array[i] = 0;

	for (i = 0; i < size; i++)
	{
		copyArray[i] = array[i];
		num = copyArray[i];
		digit = significant_digit(place, num);
		counting_array[digit]++;
	}
	prev = counting_array[0];
	for (i = 1; i < 10; i++)
	{
		counting_array[i] += prev;
		prev = counting_array[i];
	}
	for (i = size - 1; i != size; i--)
	{
		num = copyArray[i];
		digit = significant_digit(place, num);
		array[counting_array[digit] - 1] = copyArray[i];
		counting_array[digit]--;
		if (i == 0)
			i = size + 1;
	}
	free(counting_array);
	free(copyArray);
}
