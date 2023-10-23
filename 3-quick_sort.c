#include "sort.h" /* Include the header file "sort.h" which likely contains function prototypes and other necessary declarations. */

/**
 * swap_items - Swaps two items in an array.
 * @array: The array to modify.
 * @l: The index of the left item.
 * @r: The index of the right item.
 */
void swap_items(int *array, size_t l, size_t r)
{
    int tmp;

    if (array != NULL) /* Check if the array is not NULL to avoid potential issues. */
    {
        tmp = array[l]; /* Store the value at index l in a temporary variable. */
        array[l] = array[r]; /* Assign the value at index r to index l. */
        array[r] = tmp; /* Assign the value stored in the temporary variable to index r, effectively swapping the items. */
    }
}

/**
 * quick_sort_range_lomuto - Sorts a sub array using the
 * quick sort algorithm and Lomuto's partition scheme.
 * @array: The array containing the sub-array.
 * @low: The starting position of the sub-array.
 * @high: The ending position of the sub-array.
 * @size: The length of the array.
 */
void quick_sort_range_lomuto(int *array, size_t low, size_t high, size_t size)
{
    size_t k, i;
    int pivot;

    if ((low >= high) || (array == NULL))
        return; /* If the indices are invalid or the array is NULL, return without sorting. */

    pivot = array[high]; /* Choose the pivot element, which is the last element of the sub-array. */
    k = low;

    for (i = low; i < high; i++)
    {
        if (array[i] <= pivot)
        {
            if (k != i)
            {
                swap_items(array, k, i); /* Swap array[k] and array[i] if they are out of place. */
                print_array(array, size); /* Print the current state of the array after the swap. */
            }
            k++;
        }
    }

    if (k != high)
    {
        swap_items(array, k, high); /* Swap array[k] and the pivot element. */
        print_array(array, size); /* Print the current state of the array after the swap. */
    }

    if (k - low > 1)
        quick_sort_range_lomuto(array, low, k - 1, size); /* Recursively sort the sub-array before the pivot. */

    if (high - k > 1)
        quick_sort_range_lomuto(array, k + 1, high, size); /* Recursively sort the sub-array after the pivot. */
}

/**
 * quick_sort - Sorts an array using the quick sort algorithm
 * and Lomuto's partition scheme.
 * @array: The array to sort.
 * @size: The length of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array != NULL)
    {
        quick_sort_range_lomuto(array, 0, size - 1, size); /* Call the helper function to perform quick sort on the entire array. */
    }
}