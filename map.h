/* Based on "Introduction to Algorithms" by CLRS */

#pragma once

#include <stdbool.h>

#define LEFT 0
#define RIGHT 1
#define RED false
#define BLACK true

typedef int dir_t;
typedef bool color_t;

typedef int key_t;
typedef int val_t;

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
    bool first_insert;
} *map;

map map_construct();

void map_rotate_left(map, map_node);
void map_rotate_right(map, map_node);
void map_insert(map, map_node);
void map_insert_fixup(map, map_node);

void map_print(map);
void map_print_inorder(map_node, map_node);
