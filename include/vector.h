/**
 * @file vector.h
 * @author Alex M. Zhang
 * @brief Contains the definition of the vector struct as well as
 * prototypes of vector functions
 * @date 2023-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#define CSTL_VECTOR_GROWTH_FACTOR 1.5
#define CSTL_VECTOR_STARTING_CAPACITY 2

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "tvar.h"

typedef tvar vec_val_t;
typedef vec_val_t *vector_it;

/**
 * @brief Resizeable array similar to std::vector
 *
 */
typedef struct vector {
    size_t size;
    size_t capacity;
    vec_val_t *data;
} vector;

vector *vector_construct();
void vector_destruct(vector *);

/**
 * @brief Returns the value at the given index; provides bounds checking
 *
 * @return vec_t
 */
inline vec_val_t vector_at(vector *v, size_t index) {
    assert(index < v->size);
    return v->data[index];
}

/**
 * @brief Returns the value of the first element of the vector
 *
 * @return vec_t
 */
inline vec_val_t vector_front(vector *v) { return v->data[0]; }

/**
 * @brief Returns the value of the last element of the vector
 *
 * @return vec_t
 */
inline vec_val_t vector_back(vector *v) { return v->data[v->size - 1]; }

/**
 * @brief Returns a pointer to the array where the elements are contained
 *
 * @return vector_it
 */
inline vec_val_t *vector_data(vector *v) { return (v->data); }

/**
 * @brief Returns an iterator to the first element of the vector
 *
 * @return vector_it
 */
inline vector_it vector_begin(vector *v) { return (v->data); }

/**
 * @brief Returns an iterator to the last element of the vector
 *
 * @return vector_it
 */
inline vector_it vector_end(vector *v) { return (v->data + v->size); }

/**
 * @brief Returns whether the vector is empty
 *
 * @return true
 * @return false
 */
inline bool vector_empty(vector *v) { return v->size == 0; }

/**
 * @brief Allocates memory for the supplied number of elements
 *
 */
inline void vector_reserve(vector *v, size_t new_capacity) {
    v->data = (vec_val_t *)realloc(v->data, sizeof(vec_val_t) * new_capacity);
    v->capacity = new_capacity;
}

/**
 * @brief Shrinks the size of the array to the number of elements
 *
 */
inline void vector_shrink_to_fit(vector *v) {
    v->data = (vec_val_t *)realloc(v->data, sizeof(vec_val_t) * v->size);
    v->capacity = v->size;
}

/**
 * @brief Sets a vector's number of elements to 0 (but does not actually delete
 * elements)
 *
 * @param v Vector to clear
 */
inline void vector_clear(vector *v) { v->size = 0; }

/**
 * @brief Inserts an element at the specified index
 *
 * @param v Vector to insert into
 * @param index Index to insert into
 * @param value Value to be inserted
 */
inline void vector_insert(vector *v, size_t index, vec_val_t value) {
    if (v->capacity <= v->size) {
        vector_reserve(v, v->capacity * CSTL_VECTOR_GROWTH_FACTOR);
    }

    for (size_t i = v->size; i >= index; --i) {
        v->data[i] = v->data[i - 1];
    }

    v->data[index] = value;
    ++v->size;
}

/**
 * @brief Deletes an element from the vector
 *
 * @param v Vector to delete from
 * @param index Index to delete
 */
inline void vector_erase(vector *v, size_t index) {
    for (size_t i = index; i < v->size - 1; ++i) {
        v->data[i] = v->data[i + 1];
    }

    --v->size;
}

/**
 * @brief Deletes a range of elements from the vector
 *
 * @param v Vector to delete from
 * @param left Left-most index in the range
 * @param right Right-most index in the range
 */
inline void vector_erase_range(vector *v, size_t left, size_t right) {
    size_t num_erase = right - left;
    for (size_t i = left; i < v->size - num_erase; ++i) {
        v->data[i] = v->data[i + num_erase];
    }

    v->size -= num_erase;
}

/**
 * @brief Appends the given element value to the end of the vector
 *
 * @param v Vector to append to
 * @param value Value to be appended
 */
inline void vector_push_back(vector *v, vec_val_t value) {
    if (v->capacity <= v->size) {
        vector_reserve(v, v->capacity * CSTL_VECTOR_GROWTH_FACTOR);
    }

    v->data[v->size] = value;
    ++v->size;
}
