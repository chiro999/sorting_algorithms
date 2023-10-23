#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - sorts a DLL of integers in
 * ascending order using the insertion sort
 * algorithm
 *
 * @list: doubly linked list
 * Return: no return
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *ptr, *tmp;

    if (!list)
        return; /* If the list is empty or NULL, there's nothing to sort, so return. */

    ptr = *list; /* Initialize a pointer to the head of the list. */

    while (ptr)
    {
        while (ptr->next && (ptr->n > ptr->next->n))
        {
            /* If the current node's value is greater than the next node's value, swap them. */
            tmp = ptr->next;
            ptr->next = tmp->next;
            tmp->prev = ptr->prev;

            if (ptr->prev)
                ptr->prev->next = tmp;

            if (tmp->next)
                tmp->next->prev = ptr;

            ptr->prev = tmp;
            tmp->next = ptr;

            if (tmp->prev)
                ptr = tmp->prev; /* Move the pointer back if there is a previous node. */
            else
                *list = tmp; /* Update the head of the list if the first element was swapped. */

            print_list(*list); /* Print the current state of the linked list. */
        }
        ptr = ptr->next; /* Move the pointer to the next node in the list. */
    }
}