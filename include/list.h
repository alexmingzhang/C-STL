/**
 * @file list.h
 * @author Alex M. Zhang
 * @brief Contains the definitions of the list and list_node structs as well as
 * prototypes of list functions
 * @date 2023-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include <stdbool.h>
#include <stdlib.h>

#include "tvar.h"

typedef tvar list_val_t;

typedef struct list_node {
    list_val_t val;
    struct list_node *next;
    struct list_node *prev;
} list_node;

typedef list_node *list_it;

/**
 * @brief Doubly-linked list, similar to std::list
 *
 */
typedef struct list {
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
inline void list_push_back(list *l, list_val_t val) {
    l->tail->val = val;
    l->tail->next = (list_node *)malloc(sizeof(list_node));
    l->tail->next->prev = l->tail;
    l->tail->next->next = NULL;
    l->tail = l->tail->next;
}
