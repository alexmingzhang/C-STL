/**
 * @file vector.c
 * @author Alex M. Zhang
 * @brief Contains the definitions of vector functions
 * @version 0.1
 * @date 2023-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "vector.h"

#include <stdio.h>
#include <string.h>

vector *vector_construct() {
    vector *v = (vector *)malloc(sizeof(vector));
    v->size = 0;
    v->capacity = CSTL_VECTOR_STARTING_CAPACITY;
    v->data =
        (vec_val_t *)malloc(sizeof(vec_val_t) * CSTL_VECTOR_STARTING_CAPACITY);
    return v;
}

void vector_destruct(vector *v) {
    free(v->data);
    free(v);
}
