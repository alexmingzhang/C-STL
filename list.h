#pragma once

#include <stdbool.h>
#include <stdlib.h>

typedef void *list_t;

typedef struct _list_node {
    list_t value;
    struct _list_node *next;
    struct _list_node *prev;
} *list_node;

typedef list_node list_it;

typedef struct _list {
    list_node head;
    list_node tail;
} *list;

list list_construct();
void list_destruct(list);

list_it list_begin(list);
list_it list_end(list);
void list_it_add(list_it *, size_t);
list_it list_rbegin(list);
list_it list_rend(list);
void list_it_sub(list_it *, size_t);

void list_push_front(list, list_t);
void list_push_back(list, list_t);
