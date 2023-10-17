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

void list_push_back(list_t *list, list_data_t item_data)
{
    list_node_t *new = create_node(item_data);
    insert_node(new, list->sentinel->prev);
    list->size++;
}

list_data_t list_back(const list_t *list)
{
    return list->sentinel->prev->data;
}

void list_pop_back(list_t *list)
{
    if(!list_is_empty(list)){
        list_node_t *node = list->sentinel->prev;
        remove_node(node);
        list->size--;
    }
}

void list_delete(list_t *list, list_data_t data)
{
    list_node_t *node_to_delete = find_node(list, data);
    if (node_to_delete != NULL) {
        remove_node(node_to_delete);
        list->size--;
    }
}

list_node_t *find_node(const list_t *list, list_data_t data)
{
    list_node_t *current = list->sentinel->next;
    while (current != list->sentinel) {
        if (current->data == data) {
            return current; 
        }
        current = current->next;
    }
    return NULL; 
}

/*iterativa
void list_reverse(list_t *list)
{
    if (list_is_empty(list) || list->size == 1) {
        return; 
    }

    list_node_t *current = list->sentinel->next;
    list_node_t *prev = NULL;
    list_node_t *next;

    while (current != list->sentinel) {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }

    list->sentinel->next = prev;
    list->sentinel->prev = prev;
}*/

//recursiva
void reverse_range(list_t *list, list_node_t *left, list_node_t *right)
{
    if (left == right || left->prev == right) {
        return; 
    }

    list_data_t temp = left->data;
    left->data = right->data;
    right->data = temp;

    reverse_range(list, left->next, right->prev);
}

void list_reverse(list_t *list) {
    if (list->size <= 1) {
        return; 
    }
    reverse_range(list, list->sentinel->next, list->sentinel->prev);
}

