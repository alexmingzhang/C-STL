#pragma once

#include <stdbool.h>
#include <stdlib.h>

#include "tvar.h"

typedef tvar list_val_t;

typedef struct _list_node {
    list_val_t val;
    struct _list_node *next;
    struct _list_node *prev;
} list_node;

typedef list_node *list_it;

/**
 * @brief Doubly linked, similar to std::list
 *
 */
typedef struct _list {
    list_node *head;
    list_node *tail;
} list;

list *list_construct();
void list_destruct(list *);

/**
 * @brief Returns an iterator to the first element of the list
 *
 * @return list_it
 */
list_it list_begin(list *);

/**
 * @brief Returns an iterator to one past the last element of the list
 *
 * @return list_it
 */
list_it list_end(list *);

/**
 * @brief Returns an iterator to one previous of the first element of the list
 *
 * @return list_it
 */
list_it list_rbegin(list *);

/**
 * @brief Returns an iterator to the last element of the list
 *
 * @return list_it
 */
list_it list_rend(list *);

/**
 * @brief Increments a list iterator by going to the next element(s)
 *
 */
void list_it_add(list_it *, size_t);

/**
 * @brief Decrements a list iterator by going to the previous element(s)
 *
 */
void list_it_sub(list_it *, size_t);

/**
 * @brief Insert something right behind the provided list iterator
 *
 */
void list_insert(list_it *, list_val_t);

/**
 * @brief Add something to the front of the list
 *
 */
void list_push_front(list *, list_val_t);

/**
 * @brief Add something to the end of the list
 *
 */
void list_push_back(list *, list_val_t);
