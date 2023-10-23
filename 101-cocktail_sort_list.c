#include "sort.h" /* Include the header file "sort.h" which likely contains function prototypes and other necessary declarations. */

/**
 * _swap - Swaps two nodes of a doubly linked list.
 *
 * @node: Pointer to the node to be swapped.
 * @list: Double linked list head.
 *
 * Return: No Return.
 */
void _swap(listint_t **node, listint_t **list)
{
    listint_t *tmp = *node, *tmp2, *tmp3;

    if (!(*node)->prev)
        *list = (*node)->next;

    tmp = tmp3 = *node;
    tmp2 = tmp->next;

    tmp->next = tmp2->next;
    tmp3 = tmp->prev;
    tmp->prev = tmp2;
    tmp2->next = tmp;
    tmp2->prev = tmp3;

    if (tmp2->prev)
        tmp2->prev->next = tmp2;

    if (tmp->next)
        tmp->next->prev = tmp;

    *node = tmp2;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using the
 * Cocktail shaker sort algorithm in ascending order.
 *
 * @list: Pointer to the head of the list to be sorted (Double Linked List).
 *
 * Return: No Return.
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *head, *aux;
    int current_index = 0;
    int l_index = -1; /* Leftmost index of the sublist. */
    int r_index = -1; /* Rightmost index of the sublist. */

    if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
        return; /* If the list is empty or has only one element, no sorting is needed. */

    head = *list;
    while (r_index >= l_index)
    {
        l_index++;
        while (head->next && current_index != r_index)
        {
            if (head->n > head->next->n)
            {
                aux = head;
                _swap(&aux, list);
                print_list(*list); /* Print the current state of the list after swapping. */
                head = aux;
            }

            current_index++;
            head = head->next;
        }

        if (l_index == 0)
            r_index = current_index;
        r_index--;
        while (head->prev && current_index >= l_index)
        {
            if (head->n < head->prev->n)
            {
                aux = head->prev;
                _swap(&aux, list);
                print_list(*list); /* Print the current state of the list after swapping. */
                head = aux->next;
            }
            current_index--;
            head = head->prev;
        }
    }
}