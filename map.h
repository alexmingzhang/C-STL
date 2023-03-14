/* Based on "Introduction to Algorithms" by CLRS */

#pragma once

#include <stdbool.h>

#include "tvar.h"

#define RED false
#define BLACK true
typedef bool map_color_t;

typedef tvar map_key_t;
typedef tvar map_val_t;

typedef struct _map_node {
    struct _map_node *parent;
    struct _map_node *left;
    struct _map_node *right;
    map_key_t key;
    map_val_t val;
    map_color_t color;
} *map_node;

map_node map_node_construct(map_key_t, map_val_t);
void map_node_print(map_node);

/**
 * @brief Red-black tree, similar to std::map
 *
 */
typedef struct _map {
    map_node nil;
    map_node root;
} *map;

map map_construct();

map_node map_find(map, map_key_t);
map_node map_node_find(map_node, map_key_t, map_node);

void map_left_rotate(map, map_node);
void map_right_rotate(map, map_node);
void map_insert(map, map_node);
void map_insert_fixup(map, map_node);

void map_print(map);
void map_print_inorder(map_node, map_node);

void map_verify(map);
void map_node_recursive_verify(map_node, map_node, int, int *);
