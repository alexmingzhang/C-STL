#include "list.h"

list list_construct() {
    list l = malloc(sizeof(struct _list));
    l->head = malloc(sizeof(struct _list_node));
    l->tail = malloc(sizeof(struct _list_node));

    l->head->next = l->tail;
    l->head->prev = NULL;

    l->tail->next = NULL;
    l->tail->prev = l->head;

    return l;
}

void list_destruct(list l) {
    list_node it = list_end(l);
    do {
        list_node to_free = it;
        it = it->prev;
        free(to_free);
    } while (it != NULL);

    free(l);
}

list_it list_begin(list l) { return l->head->next; }

list_it list_end(list l) { return l->tail; }

void list_it_add(list_it *it, size_t pos) {
    for (size_t i = 0; i < pos; ++i) {
        *it = (*it)->next;
    }
}

list_it list_rbegin(list l) { return l->head; }

list_it list_rend(list l) { return l->tail->next; }

void list_it_sub(list_it *it, size_t pos) {
    for (size_t i = 0; i < pos; ++i) {
        *it = (*it)->prev;
    }
}

void list_push_back(list l, list_t val) {
    l->tail->value = val;
    l->tail->next = malloc(sizeof(struct _list_node));
    l->tail->next->prev = l->tail;
    l->tail->next->next = NULL;
    l->tail = l->tail->next;
}