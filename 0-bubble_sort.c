#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts an array of integers in ascending order
 * 
 * @array: array of integers
 * @size: size of the array
 * 
 * Return void
*/

void bubble_sort(int *array, size_t size)
{
    size_t i;
    int tmp, is_sorted;

    if (!array || size == 0)
        return;

    is_sorted = 0;
    while (!is_sorted)
    {
        is_sorted = 1;
        /* loop to swap and sort integers*/
        for (i = 0; i < size - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                is_sorted = 0;
                tmp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = tmp;
                print_array(array, size);
            }
        }
    }
}