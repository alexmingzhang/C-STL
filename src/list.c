/**
 * @file list.c
 * @author Alex M. Zhang
 * @brief Contains the definitions of list functions
 * @date 2023-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "list.h"

#include <stdio.h>

list *list_construct() {
    list *l = (list *)malloc(sizeof(list));
    l->head = (list_node *)malloc(sizeof(list_node));
    l->tail = (list_node *)malloc(sizeof(list_node));

    l->head->next = l->tail;
    l->head->prev = NULL;

    l->tail->next = NULL;
    l->tail->prev = l->head;

    return l;
}

void list_destruct(list *l) {
    list_it it = list_end(l);
    do {
        list_node *to_free = it;
        it = it->prev;
        free(to_free);
    } while (it != NULL);

    free(l);
}

list_it list_begin(list *l) { return l->head->next; }

list_it list_end(list *l) { return l->tail; }

list_it list_rbegin(list *l) { return l->tail->prev; }

list_it list_rend(list *l) { return l->head; }

void list_it_add(list_it *it, size_t pos) {
    for (size_t i = 0; i < pos; ++i) {
        *it = (*it)->next;
    }
}

void list_it_sub(list_it *it, size_t pos) {
    for (size_t i = 0; i < pos; ++i) {
        *it = (*it)->prev;
    }
}

void list_insert(list_it *it, list_val_t val) {
    list_node *n = (list_node *)malloc(sizeof(list_node));
    n->val = val;

    (*it)->prev->next = n;
    n->prev = (*it)->prev;
    (*it)->prev = n;
    n->next = *it;
}

void list_push_back(list *l, list_val_t val) {
    l->tail->val = val;
    l->tail->next = (list_node *)malloc(sizeof(list_node));
    l->tail->next->prev = l->tail;
    l->tail->next->next = NULL;
    l->tail = l->tail->next;
}
