#include "sort.h"
#include <stddef.h>
#include <stdio.h>

/**
 * heap_sort - sorts an array using the heap sort algorithm
 *
 * @array: the array of integers to be sorted
 * @size: the size of the array
 */

void heap_sort(int *array, size_t size)
{
	size_t i;

	if (size < 2 || array == NULL)
		return;

	heapify(array, size);
	for (i = size - 1; i > 0; i--)
	{
		swapArr(array, size, 0, i);
		siftDown(array, size, i, 0);
	}
}

/**
 * heapify - converts an array into a heap
 *
 * @array: an array of integers to be converted
 * @size: the size of the array
 */

void heapify(int *array, size_t size)
{
	int start;

	start = (size / 2) - 1;
	for (; start >= 0; start--)
	{
		siftDown(array, size, size, start);
	}
}

/**
 * siftDown - fixes a broken branch of a heap tree
 *
 * @unsorted: the size of the unsorted region
 * @index: the index of the branch node
 * @array: the node of the branch that needs fixing
 * @size: the size of the array
 */

void siftDown(int *array, size_t size, size_t unsorted, size_t index)
{
	size_t leftChild, rightChild, maxChild;

	leftChild = (index * 2) + 1;
	rightChild = (index * 2) + 2;
	if (leftChild >= unsorted)
		return;
	else if (rightChild >= unsorted)
		maxChild = leftChild;
	else
	{
		maxChild = leftChild;
		if (array[rightChild] > array[leftChild])
			maxChild = rightChild;
	}

	if (array[index] < array[maxChild])
	{
		swapArr(array, size, index, maxChild);
		siftDown(array, size, unsorted, maxChild);
	}
}

/**
 * swapArr - swaps two elements in an array
 *
 * @array: the array contianing the elements
 * @size: the size of the array
 * @first: the index of the first element
 * @second: the index of the second element
 */

void swapArr(int *array, size_t size, size_t first, size_t second)
{
	int temp;

	temp = array[first];
	array[first] = array[second];
	array[second] = temp;
	print_array(array, size);
}
