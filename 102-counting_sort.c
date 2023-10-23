#include "sort.h"
/**
 * counting_sort - sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * @array: pointer to array
 * @size: size of the array
 **/
void counting_sort(int *array, size_t size)
{
    int max_value, j, *count_array, *tmp_array;
    size_t i;

    /* Check if the input array is valid or requires sorting */
    if (!array || size < 2)
        return;

    /* Find the maximum value in the input array */
    max_value = array[0];
    for (i = 0; i < size; i++)
    {
        if (array[i] > max_value)
            max_value = array[i];
    }

    /* Allocate memory for the count_array based on the maximum value */
    count_array = calloc((max_value + 1), sizeof(int));

    /* Count the occurrences of each element in the input array */
    for (i = 0; i < size; i++)
    {
        count_array[array[i]]++;
    }

    /* Calculate cumulative counts to determine the position of each element */
    for (j = 1; j <= max_value; j++)
    {
        count_array[j] += count_array[j - 1];
    }
    print_array(count_array, max_value + 1);

    /* Allocate memory for the temporary array to store sorted elements */
    tmp_array = malloc(sizeof(int) * size);

    /* Build the sorted array using count_array and tmp_array */
    for (i = 0; i < size; i++)
    {
        count_array[array[i]]--;
        tmp_array[count_array[array[i]]] = array[i];
    }

    /* Copy the sorted elements back to the original array */
    for (i = 0; i < size; i++)
    {
        array[i] = tmp_array[i];
    }

    /* Free dynamically allocated memory to prevent memory leaks */
    free(tmp_array);
    free(count_array);
}