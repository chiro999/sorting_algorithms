#include "sort.h"

/**
 * swap - swaps two elements in the array
 * @array: array
 * @item1: index of the first element
 * @item2: index of the second element
 */
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}

/**
 * hoare_partition - Hoare partition sorting scheme implementation
 * @array: array
 * @first: first array element
 * @last: last array element
 * @size: size of the array
 * Return: position of the last element sorted
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int pivot = array[last];
	int current = first - 1, finder = last + 1;

	while (current < finder)
	{
		do {
			current++;
		} while (array[current] < pivot);

		do {
			finder--;
		} while (array[finder] > pivot);

		if (current < finder)
		{
			swap(array, current, finder);
			print_array(array, size);
		}
	}

	return current;
}

/**
 * qs - Quicksort algorithm implementation
 * @array: array
 * @first: first array element
 * @last: last array element
 * @size: array size
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = hoare_partition(array, first, last, size);
		qs(array, first, position, size);
		qs(array, position + 1, last, size);
	}
}

/**
 * quick_sort_hoare - Prepares the terrain for Quicksort algorithm (Hoare scheme)
 * @array: array to be sorted
 * @size: number of elements in the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
