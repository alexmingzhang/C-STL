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
    struct _map_node *child[2];
    color_t color;
    key_t key;
    val_t value;
} *map_node;

map_node map_node_construct(key_t, val_t);

/**
 * @brief Red-black tree, similar to std::map
 *
 */
typedef struct _map {
    map_node root;
} *map;

map map_construct();

map_node map_rotate(map, map_node, dir_t);
void map_insert(map, map_node);
void map_insert_fixup(map, map_node);

void map_print(map);
void map_print_inorder(map_node);
