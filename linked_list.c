#include "linked_list.h"

void list_init(list_t *list)
{
    list->sentinel = (list_node_t*)malloc(sizeof(list_node_t));
    list->size = 0;
    list->sentinel->next = list->sentinel->prev = list->sentinel;
}

void list_destroy(list_t *list)
{
    while(!list_is_empty(list)){
        list_pop_front(list);
    }
    free(list->sentinel);
}

bool list_is_empty(const list_t *list)
{
    return list->size == 0;
}

void list_pop_front(list_t *list)
{
    if(!list_is_empty(list)){
        list_node_t *node = list->sentinel->next;
        remove_node(node);
        list->size--;
    }
}

void remove_node(list_node_t *node)
 {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
}

size_t list_size(const list_t *list)
{
    return list->size;
}
