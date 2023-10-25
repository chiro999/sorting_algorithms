#include "sort.h"

/**
 * swap - swaps two elements in the array
 * @array: array
 * @item1: index of the first element
 * @item2: index of the second element
 */
void swap(int *array, ssize_t item1, ssize_t item2) {
    int tmp;

    /* Swap the elements at indices item1 and item2 */
    tmp = array[item1];
    array[item1] = array[item2];
    array[item2] = tmp;
}

/**
 * hoare_partition - implements the Hoare partition scheme for Quicksort
 * @array: array
 * @first: index of the first element in the partition
 * @last: index of the last element in the partition
 * @size: size of the array
 * Return: position of the last element in the partition after sorting
 */
int hoare_partition(int *array, int first, int last, int size) {
    int current = first - 1, finder = last + 1;
    int pivot = array[last];

    while (1) {
        /* Find element on the left side greater than or equal to pivot */
        do {
            current++;
        } while (array[current] < pivot);

        /* Find element on the right side smaller than or equal to pivot */
        do {
            finder--;
        } while (array[finder] > pivot);

        /* If indices have crossed, return position of the last element */
        if (current >= finder)
            return current;

        /* Swap the elements and print the array after swapping */
        swap(array, current, finder);
        print_array(array, size);
    }
}

/**
 * qs - implements Quicksort algorithm recursively
 * @array: array
 * @first: index of the first element in the partition
 * @last: index of the last element in the partition
 * @size: size of the array
 */
void qs(int *array, ssize_t first, ssize_t last, int size) {
    ssize_t position = 0;

    /* If there are more than one element in the partition */
    if (first < last) {
        /* Get the partition position and sort both halves */
        position = hoare_partition(array, first, last, size);
        qs(array, first, position - 1, size);
        qs(array, position, last, size);
    }
}
