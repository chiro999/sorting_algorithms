#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps two elements of an array based on the given order
 * @arr: array
 * @item1: first element index
 * @item2: second element index
 * @order: 1 for ascending order, 0 for descending order
 */
void swap(int arr[], int item1, int item2, int order) {
    int temp;

    /* If in the correct order, swap the elements */
    if (order == (arr[item1] > arr[item2])) {
        temp = arr[item1];
        arr[item1] = arr[item2];
        arr[item2] = temp;
    }
}

/**
 * merge - recursively merges bitonic sequences in both ascending and descending order
 * @arr: array
 * @low: starting index of the sequence
 * @nelemnt: number of elements in the sequence
 * @order: 1 for ascending order, 0 for descending order
 */
void merge(int arr[], int low, int nelemnt, int order) {
    int mid, i;

    /* If there are more than one element in the sequence */
    if (nelemnt > 1) {
        mid = nelemnt / 2;
        /* Swap elements if necessary */
        for (i = low; i < low + mid; i++)
            swap(arr, i, i + mid, order);

        /* Recursively merge the two halves */
        merge(arr, low, mid, order);
        merge(arr, low + mid, mid, order);
    }
}

/**
 * bitonicsort - recursively performs bitonic sorting
 * @arr: array
 * @low: starting index of the subsequence
 * @nelemnt: number of elements in the subsequence
 * @order: 1 for ascending order, 0 for descending order
 * @size: total number of elements in the array
 */
void bitonicsort(int arr[], int low, int nelemnt, int order, int size) {
    int mid;

    /* If there are more than one element in the subsequence */
    if (nelemnt > 1) {
        /* Print the current merging step */
        if (order >= 1) {
            printf("Merging [%i/%i] (UP):\n", nelemnt, size);
            print_array(&arr[low], nelemnt);
        } else {
            printf("Merging [%i/%i] (DOWN):\n", nelemnt, size);
            print_array(&arr[low], nelemnt);
        }

        mid = nelemnt / 2;
        /* Recursively sort and merge both halves */
        bitonicsort(arr, low, mid, 1, size);
        bitonicsort(arr, low + mid, mid, 0, size);
        merge(arr, low, nelemnt, order);

        /* Print the result after merging */
        if (order <= 0) {
            printf("Result [%i/%i] (DOWN):\n", nelemnt, size);
            print_array(&arr[low], nelemnt);
        }
        if (order >= 1) {
            printf("Result [%i/%i] (UP):\n", nelemnt, size);
            print_array(&arr[low], nelemnt);
        }
    }
}

/**
 * bitonic_sort - prepares the terrain for the bitonic sort algorithm
 * @array: array to be sorted
 * @size: number of elements in the array
 */
void bitonic_sort(int *array, size_t size) {
    int order = 1; /* 1 for ascending order, 0 for descending order */

    /* Check for valid input */
    if (!array || size < 2)
        return;

    /* Start the bitonic sort algorithm */
    bitonicsort(array, 0, size, order, size);
}
