#include "sort.h"
#include <stdio.h>

/**
 * _swap - swaps two values in an array.
 * @array: the array in which values are swapped.
 * @i: First index
 * @j: Second index
 * Return: Nothing
 */
void _swap(int *array, int i, int j)
{
    int tmp;

    /* If the elements at indices i and j are different, swap them. */
    tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

/**
 * shell_sort - sorts the array using Shell Sort algorithm
 * @array: The array to be sorted.
 * @size: Size of the array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
    size_t h = 0, i, j;

    /* If the array has less than 2 elements, it's already sorted. */
    if (size < 2)
        return;

    /* Calculate the initial gap value h using the 3x+1 sequence. */
    while (h <= size / 3)
        h = h * 3 + 1;

    /* Start with the largest gap and reduce it until it's 1. */
    while (h >= 1)
    {
        /* Perform insertion sort on subarrays with a gap of h. */
        for (i = h; i < size; i++)
        {
            for (j = i; j >= h && array[j] < array[j - h]; j -= h)
            {
                /* Swap elements if they are out of order. */
                _swap(array, j, j - h);
            }
        }
        /* Reduce the gap. */
        h /= 3;
        /* Print the array after each iteration (not shown in this code snippet). */
        /* print_array(array, size); */
    }
}