#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * copy - copies data from one buffer to another
 *
 * @src: source buffer
 * @dst: destination buffer
 * @size: size of buffers
 */
void copy(int *src, int *dst, int size)
{
    /* Copy elements from source (src) to destination (dst) array */
    for (int i = 0; i < size; i++)
        dst[i] = src[i];
}

/**
 * merge - merges two sets of data in ascending order
 *
 * @array: first set of data
 * @buff: second set of data
 * @minL: lower range of first set of data
 * @maxL: upper range of first set of data
 * @minR: lower range of second set of data
 * @maxR: upper range of second set of data
 */
void merge(int *array, int *buff, int minL, int maxL, int minR, int maxR)
{
    int i = minL, j = minR, k = minL;

    /* Merge two sorted subarrays (buff[minL:maxL] and buff[minR:maxR]) into array */
    while (i <= maxL || j <= maxR)
    {
        if (i <= maxL && j <= maxR)
        {
            /* Compare elements in the subarrays and merge them in ascending order */
            if (buff[i] <= buff[j])
            {
                array[k] = buff[i];
                k++;
                i++;
            }
            else
            {
                array[k] = buff[j];
                k++;
                j++;
            }
        }
        else if (i > maxL && j <= maxR)
        {
            /* Copy remaining elements from the right subarray if left subarray is exhausted */
            array[k] = buff[j];
            k++;
            j++;
        }
        else
        {
            /* Copy remaining elements from the left subarray if right subarray is exhausted */
            array[k] = buff[i];
            k++;
            i++;
        }
    }
}

/**
 * printcheck - prints an array in a given range
 *
 * @array: array of data to be print
 * @r1: start of range
 * @r2: end of range
 */
void printcheck(int *array, int r1, int r2)
{
    /* Print elements of the array within the specified range (r1 to r2) */
    for (int i = r1; i <= r2; i++)
    {
        if (i > r1)
            printf(", ");
        printf("%d", array[i]);
    }
    printf("\n");
}

/**
 * split - recursive function to split data into merge tree
 *
 * @array: array of data to be split
 * @buff: auxiliary array of data for merging
 * @min: min range of data in array
 * @max: max range of data in array
 * @size: size of total data
 */
void split(int *array, int *buff, int min, int max, int size)
{
    int mid, tmax, minL, maxL, minR, maxR;

    /* Base case: If the subarray has 0 or 1 element, it is already sorted */
    if ((max - min) <= 0)
        return;

    /* Calculate the middle index of the subarray */
    mid = (max + min + 1) / 2;
    tmax = max;
    max = mid - 1;

    minL = min;
    maxL = max;

    /* Recursively split and sort the left subarray */
    split(array, buff, min, max, size);

    min = mid;
    max = tmax;

    minR = min;
    maxR = max;

    /* Recursively split and sort the right subarray */
    split(array, buff, min, max, size);

    /* Print the subarrays before merging */
    printf("Merging...\n");
    printf("[left]: ");
    printcheck(array, minL, maxL);
    printf("[right]: ");
    printcheck(array, minR, maxR);

    /* Merge the sorted subarrays back into array */
    merge(array, buff, minL, maxL, minR, maxR);
    /* Copy the merged array back to the auxiliary buffer for the next iteration */
    copy(array, buff, size);

    /* Print the merged subarray after merging */
    printf("[Done]: ");
    printcheck(array, minL, maxR);
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 *
 * @array: array of data to be sorted
 * @size: size of data
 */
void merge_sort(int *array, size_t size)
{
    int *buff;

    /* Base case: If the array has 0 or 1 element, it is already sorted */
    if (size < 2)
        return;

    /* Allocate memory for an auxiliary buffer */
    buff = malloc(sizeof(int) * size);
    if (buff == NULL)
        return; /* Handle memory allocation failure gracefully */

    /* Copy the input array to the auxiliary buffer */
    copy(array, buff, size);

    /* Start the recursive sorting process */
    split(array, buff, 0, size - 1, size);

    /* Free the allocated memory */
    free(buff);
}