#include "sort.h"

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    if (node1 == NULL || node2 == NULL || node1 == node2)
    {
            return;
    }
    /* Adjust the previous and next pointers for node1 and node2 */
    if (node1->prev)
    {
        node1->prev->next = node2;
    }
    else
    {
        *list = node2;
    }

    if (node2->next)
    {
        node2->next->prev = node1;
    }

    node2->prev = node1->prev;
    node1->next = node2->next;
    node2->next = node1;
    node1->prev = node2;
}

void insertion_sort_list(listint_t **list)
{
    listint_t *current, *insert, *next;

    if (list == NULL || *list == NULL)
    {
        return;
    }
    current = (*list)->next;

    while (current)
    {
        insert = current;
        current = current->next;

        while (insert->prev && insert->n < insert->prev->n)
        {
            swap_nodes(list, insert->prev, insert);
            print_list(*list);
        }
    }
}