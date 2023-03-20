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

#include <assert.h>

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

vec_val_t vector_at(vector *v, size_t index) {
    assert(index < v->size);
    return v->data[index];
}

vec_val_t *vector_data(vector *v) { return (v->data); }

vector_it vector_begin(vector *v) { return (v->data); }

vector_it vector_end(vector *v) { return (v->data + v->size); }

bool vector_is_empty(vector *v) { return v->size == 0; }

void vector_reserve(vector *v, size_t new_capacity) {
    v->data = (vec_val_t *)realloc(v->data, sizeof(vec_val_t) * new_capacity);
    v->capacity = new_capacity;
}

void vector_shrink_to_fit(vector *v) {
    v->data = (vec_val_t *)realloc(v->data, sizeof(vec_val_t) * v->size);
    v->capacity = v->size;
}

void vector_clear(vector *v) { v->size = 0; }

void vector_insert(vector *v, size_t pos, vec_val_t value) {
    if (v->capacity < v->size + 1) {
        vector_reserve(v, v->capacity * 2);
    }

    for (size_t i = v->size - pos + 1; i >= pos; --i) {
        v->data[i] = v->data[i - 1];
    }

    v->data[pos] = value;
    ++v->size;
}

void vector_erase(vector *v, size_t index) {
    for (size_t i = index; i < v->size - 1; ++i) {
        v->data[i] = v->data[i + 1];
    }

    --v->size;
}

void vector_erase_range(vector *v, size_t first, size_t last) {
    size_t num_erase = last - first;
    for (size_t i = first; i < v->size - num_erase; ++i) {
        v->data[i] = v->data[i + num_erase];
    }

    v->size -= num_erase;
}

void vector_push_back(vector *v, vec_val_t value) {
    if (v->capacity < v->size + 1) {
        vector_reserve(v, v->capacity * CSTL_VECTOR_GROWTH_FACTOR);
    }

    v->data[v->size] = value;
    ++v->size;
}
