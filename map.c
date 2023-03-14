#include "map.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

map_node map_node_construct(key_t key, val_t val) {
    map_node n = malloc(sizeof(struct _map_node));
    n->parent = NULL;
    n->child[LEFT] = NULL;
    n->child[RIGHT] = NULL;
    n->color = BLACK;

    n->key = key;
    n->value = val;

    return n;
}

map map_construct() {
    map m = malloc(sizeof(struct _map));
    m->root = NULL;
    return m;
}

map_node map_rotate(map tree, map_node root, dir_t dir) {
    printf("map_rotate\n");
    dir_t opp_dir = 1 - dir;
    map_node G = root->parent;
    map_node S = root->child[opp_dir];

    assert(S != NULL);
    map_node C = S->child[dir];

    root->child[opp_dir] = C;

    if (C != NULL) {
        C->parent = root;
    }

    S->child[dir] = root;
    root->parent = S;
    S->parent = G;

    if (G != NULL) {
        G->child[root == G->child[RIGHT] ? RIGHT : LEFT] = S;
    } else {
        tree->root = S;
    }

    return S;
}

void map_insert(map T, map_node z) {
    map_node x = T->root;
    map_node y = NULL;

    while (x != NULL) {
        y = x;
        if (z->key < x->key) {
            x = x->child[LEFT];
        } else {
            x = x->child[RIGHT];
        }
    }

    z->parent = y;
    if (y == NULL) {
        T->root = z;
    } else if (z->key < y->key) {
        y->child[LEFT] = z;
    } else {
        y->child[RIGHT] = z;
    }

    z->child[LEFT] = NULL;
    z->child[RIGHT] = NULL;
    z->color = RED;

    map_insert_fixup(T, z);
}

void map_insert_fixup(map T, map_node z) {
    while (z != NULL && z->parent != NULL && z->parent->parent != NULL &&
           z->parent->color == RED) {
        if (z->parent == z->parent->parent->child[LEFT]) {
            map_node y = z->parent->parent->child[RIGHT];

            if (y == NULL) {
                return;
            }

            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->child[RIGHT]) {
                    z = z->parent;
                    map_rotate(T, z, LEFT);
                }

                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                map_rotate(T, z->parent->parent, RIGHT);
            }
        } else {
            map_node y = z->parent->parent->child[LEFT];

            if (y == NULL) {
                return;
            }

            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->child[LEFT]) {
                    z = z->parent;
                    map_rotate(T, z, RIGHT);
                }

                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                map_rotate(T, z->parent->parent, LEFT);
            }
        }
    }
}

void map_print(map m) { map_print_inorder(m->root); }

void map_print_inorder(map_node n) {
    if (n == NULL) {
        return;
    }

    map_print_inorder(n->child[LEFT]);

    printf("%d ", n->value);

    if (n->child[LEFT] == NULL && n->child[RIGHT] == NULL) {
        printf("(leaf! color=%s)", n->color == RED ? "RED" : "BLACK");
    }

    map_print_inorder(n->child[RIGHT]);
}
