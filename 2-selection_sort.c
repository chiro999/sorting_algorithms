#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: The array of integers
 * @size: The size of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
    size_t i, sort_idx, min_idx;
    int tmp;

    for (sort_idx = 0; sort_idx < size - 1; sort_idx++)
    {
        min_idx = sort_idx;

        /* Find the index of the minimum element in the unsorted region */
        for (i = sort_idx + 1; i < size; i++)
        {
            if (array[i] < array[min_idx])
                min_idx = i;
        }

        /* Swap the found minimum element with the first element of the unsorted region */
        if (min_idx != sort_idx)
        {
            tmp = array[sort_idx];
            array[sort_idx] = array[min_idx];
            array[min_idx] = tmp;

            /* Print the current state of the array after the swap */
            print_array(array, size);
        }
    }
}