#include "sort.h"

/**
 * check_tree - checks and fixes the max heap property for a subtree rooted at i
 * @array: pointer to the array
 * @size_init: original size of the array
 * @size: current size of the heap
 * @i: index as the root of the subtree to be checked and fixed
 */
void check_tree(int *array, size_t size_init, size_t size, size_t i)
{
    int n, left_child, right_child;
    size_t left_index, right_index;

    /* Calculate indices of left and right children */
    left_index = i * 2 + 1;
    right_index = left_index + 1;
    /* Get values of left and right children if they exist */
    left_child = (left_index < size) ? array[left_index] : 0;
    right_child = (right_index < size) ? array[right_index] : 0;

    /* Compare the parent with its children and swap if necessary */
    if ((left_index < size) && (right_index < size) &&
        ((left_child >= right_child && left_child > array[i]) ||
         ((left_index == size - 1) && left_child > array[i])))
    {
        n = array[i];
        array[i] = left_child;
        array[left_index] = n;
        print_array(array, size_init);
    }
    else if ((left_index < size) && (right_index < size) &&
             (right_child > left_child && right_child > array[i]))
    {
        n = array[i];
        array[i] = right_child;
        array[right_index] = n;
        print_array(array, size_init);
    }

    /* Recursively check and fix the left and right subtrees */
    if (left_index < size - 1)
        check_tree(array, size_init, size, left_index);
    if (right_index < size - 1)
        check_tree(array, size_init, size, right_index);
}

/**
 * heap_sort - sorts an array of integers in ascending order using Heap sort algorithm
 * @array: pointer to the array to be sorted
 * @size: number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
    size_t i, size_init = size;
    int n;

    /* Build a max heap from the input array */
    for (i = 0; i < size / 2; i++)
    {
        check_tree(array, size_init, size, size / 2 - 1 - i);
    }

    /* Extract elements from the heap one by one */
    for (i = 0; i < size_init - 1; i++)
    {
        /* Swap the root of the heap with the last element */
        n = array[0];
        array[0] = array[size - 1 - i];
        array[size - 1 - i] = n;
        /* Print the current state of the array */
        print_array(array, size_init);
        /* Fix the max heap property for the remaining heap */
        check_tree(array, size_init, size - i - 1, 0);
    }
}
