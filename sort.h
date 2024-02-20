#ifndef SORT_H
#define SORT_H
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_helper(int *array, size_t size,
		int *original, size_t totalSize);
void shell_sort(int *array, size_t size);
void insertion_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
int swap(listint_t *firstNode, listint_t *secondNode);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
int *copy(int *array, size_t size);
int *split(int *array, size_t size);
void merge(int *first, int *sec, int *parent, size_t size);
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size);
void siftDown(int *array, size_t size, size_t unsorted, size_t index);
void swapArr(int *array, size_t size, size_t first, size_t second);
void radix_sort(int *array, size_t size);
int significant_digit(size_t place, int num);
void counting_sort_radix(int *array, size_t size, size_t place);
void bitonic_sort(int *array, size_t size);
int *bitonic_split(int *array, size_t size, size_t o_size, int state);
void bitonic_merge(int *first, int *sec,
		int *parent, size_t size, size_t o_size, int state);
void mergeUp(int *first, int *sec, int *parent, size_t size);
void mergeDown(int *first, int *sec, int *parent, size_t size);
void quick_sort_hoare(int *array, size_t size);
void quick_sort_hoare_helper(int *array, size_t start, size_t size);

#endif
