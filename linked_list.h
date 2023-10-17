#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>
#include <stdbool.h> 
#include <stdlib.h>

typedef int list_data_t;
typedef struct list_node list_node_t;
typedef struct list list_t;

struct list_node {
   list_data_t data;
   struct list_node *prev;
   struct list_node *next;
};

struct list {
   struct list_node *sentinel;
   size_t size;
};

// initialize the list
void list_init(list_t *list);

// destroys an entire list
void list_destroy(list_t *list);

// checks if list is empty
bool list_is_empty(const list_t *list);

// counts the items on a list
size_t list_size(const list_t *list);

// inserts item at front of a list
void list_push_front(list_t *list, list_data_t item_data);

// returns the item from the front of a list
list_data_t list_front(const list_t *list);

// removes item from front of a list
void list_pop_front(list_t *list);

// inserts item at back of a list
void list_push_back(list_t *list, list_data_t item_data);

// returns the item from the back of a list
list_data_t list_back(const list_t *list);

// removes item from back of a list
void list_pop_back(list_t *list);

// deletes a node that holds the matching data
void list_delete(list_t *list, list_data_t data);

// reverses the order of the elements in the list
void list_reverse(list_t *list);

// sorts the elements in the list
void list_sort(list_t *list);

//removes a node from the list
void remove_node(list_node_t *node);

//creates a new node
list_node_t *create_node(list_data_t item_data);

//inserts node x after node y
void insert_node( list_node_t *x, list_node_t *y);

//search for a specific node in the list
list_node_t *find_node(const list_t *list, list_data_t data);

//aux function to reverse the list
void reverse_recursive(list_node_t *current, list_t *list) ;

#endif
