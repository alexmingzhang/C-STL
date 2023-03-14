/* Based on "Introduction to Algorithms" by CLRS */
// TODO: Comments

#include "map.h"

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

map_node map_node_construct(key_t key, val_t val) {
    map_node n = malloc(sizeof(struct _map_node));
    // n->parent = NULL;
    // n->left = NULL;
    // n->right = NULL;
    // n->color = RED;

    n->key = key;
    n->val = val;

    return n;
}

void map_node_print(map_node n) {
    printf(
        "Key: %ld | Val: %ld | Color: %c | Parent: %ld | Left: %ld | Right: "
        "%ld\n",
        n->key, n->val, n->color == RED ? 'R' : 'B', n->parent->val,
        n->left->val, n->right->val);
}

map map_construct() {
    map m = malloc(sizeof(struct _map));
    m->nil = malloc(sizeof(struct _map_node));
    m->nil->val = LONG_MAX;
    m->nil->parent = m->nil;
    m->nil->left = m->nil;
    m->nil->right = m->nil;
    m->nil->color = BLACK;

    // m->root = malloc(sizeof(struct _map_node));
    // m->root->parent = m->nil;
    // m->root->left = m->nil;
    // m->root->right = m->nil;
    // m->root->color = BLACK;

    m->root = m->nil;

    return m;
}

map_node map_find(map T, key_t key) {
    return map_node_find(T->root, key, T->nil);
}

map_node map_node_find(map_node n, key_t key, map_node nil) {
    if (n == nil) {
        return NULL;
    }

    if (key == n->key) {
        return n;
    }

    if (key > n->key) {
        return map_node_find(n->right, key, nil);
    }

    if (key < n->key) {
        return map_node_find(n->left, key, nil);
    }
}

void map_left_rotate(map T, map_node x) {
    assert(x != T->nil);

    map_node y = x->right;
    x->right = y->left;

    if (y->left != T->nil) {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == T->nil) {
        T->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

void map_right_rotate(map T, map_node y) {
    assert(y != T->nil);

    map_node x = y->left;
    y->left = x->right;

    if (x->right != T->nil) {
        x->right->parent = y;
    }

    x->parent = y->parent;

    if (y->parent == T->nil) {
        T->root = x;
    } else if (y == y->parent->right) {
        y->parent->right = x;
    } else {
        y->parent->left = x;
    }

    x->right = y;
    y->parent = x;
}

void map_insert(map T, map_node z) {
    map_node x = T->root;

    map_node y = T->nil;

    while (x != T->nil) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;
    if (y == T->nil) {
        T->root = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }

    z->left = T->nil;
    z->right = T->nil;
    z->color = RED;

    /* Insert fixup */
    while (z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            map_node y = z->parent->parent->right;

            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    map_left_rotate(T, z);
                }

                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                map_right_rotate(T, z->parent->parent);
            }
        } else {
            map_node y = z->parent->parent->left;

            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    map_right_rotate(T, z);
                }

                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                map_left_rotate(T, z->parent->parent);
            }
        }
    }

    T->root->color = BLACK;
}

void map_print(map T) { map_print_inorder(T->root, T->nil); }

void map_print_inorder(map_node n, map_node nil) {
    if (n == nil) {
        return;
    }

    map_print_inorder(n->left, nil);
    map_node_print(n);
    map_print_inorder(n->right, nil);
}

void map_verify(map T) {
    // Ensure the root is black
    assert(T->root->color == BLACK);

    int prev_num_black_encountered = -1;
    map_node_recursive_verify(T->root, T->nil, 0, &prev_num_black_encountered);
}

void map_node_recursive_verify(map_node n, map_node nil,
                               int num_black_encountered,
                               int *prev_num_black_encountered) {
    if (n == nil) {
        // Ensure every leaf (nil) is black
        assert(n->color == BLACK);

        // Ensure that every path from a node to its descendant leaves goes
        // through the same number of black nodes
        assert(*prev_num_black_encountered == -1 ||
               num_black_encountered == *prev_num_black_encountered);

        *prev_num_black_encountered = num_black_encountered;

        return;
    }

    // Ensure every node is either red of black
    assert(n->color == RED || n->color == BLACK);

    // Ensure a red node does not have any red children
    if (n->color == RED) {
        assert(n->left->color == BLACK && n->right->color == BLACK);
    }

    if (n->color == BLACK) {
        ++num_black_encountered;
    }

    map_node_recursive_verify(n->left, nil, num_black_encountered,
                              prev_num_black_encountered);

    map_node_recursive_verify(n->right, nil, num_black_encountered,
                              prev_num_black_encountered);
}
