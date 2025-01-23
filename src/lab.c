/**Update this file with the starter code**/
%%writefile lab.c
#include "lab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Initialize a new list
 */
list_t *list_init(void (*destroy_data)(void *), int (*compare_to)(const void *, const void *))
{
    list_t *list = (list_t *)malloc(sizeof(list_t));
    if (!list)
    {
        return NULL;
    }

    list->destroy_data = destroy_data;
    list->compare_to = compare_to;
    list->size = 0;
    list->head = NULL;

    return list;
}

/**
 * @brief Destroy the list and free all associated memory
 */
void list_destroy(list_t **list)
{
    if (!list || !(*list))
    {
        return;
    }

    node_t *current = (*list)->head;
    while (current)
    {
        node_t *next = current->next;
        if ((*list)->destroy_data)
        {
            (*list)->destroy_data(current->data);
        }
        free(current);
        current = next;
    }

    free(*list);
    *list = NULL;
}

/**
 * @brief Add data to the front of the list
 */
list_t *list_add(list_t *list, void *data)
{
    if (!list)
    {
        return NULL;
    }

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (!new_node)
    {
        return NULL;
    }

    new_node->data = data;
    new_node->next = list->head;
    new_node->prev = NULL;

    if (list->head)
    {
        list->head->prev = new_node;
    }

    list->head = new_node;
    list->size++;

    return list;
}

/**
 * @brief Remove data at the specified index
 */
void *list_remove_index(list_t *list, size_t index)
{
    if (!list || index >= list->size)
    {
        return NULL;
    }

    node_t *current = list->head;
    for (size_t i = 0; i < index; i++)
    {
        current = current->next;
    }

    if (current->prev)
    {
        current->prev->next = current->next;
    }
    else
    {
        list->head = current->next;
    }

    if (current->next)
    {
        current->next->prev = current->prev;
    }

    void *data = current->data;
    free(current);
    list->size--;

    return data;
}

/**
 * @brief Search for the index of a data element in the list
 */
int list_indexof(list_t *list, void *data)
{
    if (!list)
    {
        return -1;
    }

    node_t *current = list->head;
    size_t index = 0;

    while (current)
    {
        if (list->compare_to(current->data, data) == 0)
        {
            return index;
        }

        current = current->next;
        index++;
    }

    return -1;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab.h"

// Wrapper function for strcmp
int compare_to(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

// Helper function to destroy data
void destroy_data(void *data) {
    free(data);
}

int main() {
    // Initialize the list with the proper wrapper functions
    list_t *list = list_init(destroy_data, compare_to);

    // Add some data
    char *data1 = strdup("First");
    char *data2 = strdup("Second");
    char *data3 = strdup("Third");
    list_add(list, data1);
    list_add(list, data2);
    list_add(list, data3);

    // Print the list size
    printf("List size: %zu\n", list->size);

    // Find the index of an element
    int index = list_indexof(list, "Second");
    printf("Index of 'Second': %d\n", index);

    // Remove an element
    char *removed = (char *)list_remove_index(list, 1);
    printf("Removed element: %s\n", removed);
    free(removed);

    // Print the list size after removal
    printf("List size after removal: %zu\n", list->size);

    // Destroy the list
    list_destroy(&list);

    return 0;
}


