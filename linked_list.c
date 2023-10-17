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

void list_push_front(list_t *list, list_data_t item_data)
{
    list_node_t *new = create_node(item_data);
    insert_node(new, list->sentinel);
    list->size++;
}

void insert_node( list_node_t *x, list_node_t *y)
{
    x->prev = y;
    x->next = y->next;
    y->next->prev = x;
    y->next = x;
}

list_node_t *create_node(list_data_t item_data)
{
    list_node_t *new = (list_node_t*)malloc(sizeof(list_node_t));
    new->data = item_data;
    new->next = new->prev = NULL;
    return new;
}

list_data_t list_front(const list_t *list)
{
    return list->sentinel->next->data;
}
