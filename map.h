/* Based on "Introduction to Algorithms" by CLRS */

#pragma once

#include <stdbool.h>

#define RED false
#define BLACK true
typedef bool color_t;

typedef long key_t;
typedef long val_t;

typedef struct _map_node {
    struct _map_node *parent;
    struct _map_node *left;
    struct _map_node *right;
    key_t key;
    val_t val;
    color_t color;
} *map_node;

map_node map_node_construct(key_t, val_t);
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

map_node map_find(map, key_t);
map_node map_node_find(map_node, key_t, map_node);

void map_left_rotate(map, map_node);
void map_right_rotate(map, map_node);
void map_insert(map, map_node);

void map_print(map);
void map_print_inorder(map_node, map_node);

void map_verify(map);
void map_node_recursive_verify(map_node, map_node, int, int *);
