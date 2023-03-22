/**
 * @file map.h
 * @author Alex M. Zhang
 * @brief Contains the definitions of map and map_node structs as well as
 * prototypes of map functions
 * @version 0.1
 * @date 2023-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include <stdbool.h>
#include <stdlib.h>

#include "tvar.h"

#define RED false
#define BLACK true
typedef bool map_color_t;

typedef tvar map_key_t;
typedef tvar map_val_t;

typedef struct map_node {
    struct map_node *parent;
    struct map_node *left;
    struct map_node *right;
    map_key_t key;
    map_val_t val;
    map_color_t color;
} map_node;

inline map_node *map_node_construct(map_key_t key, map_val_t val) {
    map_node *n = (map_node *)malloc(sizeof(map_node));
    n->key = key;
    n->val = val;

    return n;
}

void map_node_print(map_node *);

/**
 * @brief Red-black tree, similar to std::map
 *
 */
typedef struct map {
    map_node *nil;
    map_node *root;
} map;

map *map_construct();
void map_destruct(map *);
void map_destruct_subtree(map_node *, const map_node *);

map_node *map_node_find(map_node *, map_key_t, map_node *);

inline map_node *map_find(map *T, map_key_t key) {
    return map_node_find(T->root, key, T->nil);
}

void map_left_rotate(map *, map_node *);
void map_right_rotate(map *, map_node *);
void map_insert(map *, map_node *);
void map_insert_fixup(map *, map_node *);

void map_print_inorder(map_node *, map_node *);
inline void map_print(map *T) { map_print_inorder(T->root, T->nil); }

void map_verify(map *);
void map_node_recursive_verify(map_node *, map_node *, int, int *);
