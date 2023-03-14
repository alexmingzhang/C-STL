#pragma once

#include <stdbool.h>
#include <stdlib.h>

typedef void* vec_t;
typedef vec_t* vector_it;

/**
 * @brief Resizeable array similar to std::vector
 *
 */
typedef struct _vector {
    size_t size;
    size_t capacity;
    vec_t* data;
}* vector;

vector vector_construct();
void vector_destruct(vector);

/**
 * @brief Returns the value at the given index; provides bounds checking
 *
 * @return vec_t
 */
vec_t vector_at(vector, size_t);

/**
 * @brief Returns the value of the first element of the vector
 *
 * @return vec_t
 */
vec_t vector_front(vector);

/**
 * @brief Returns the value of the last element of the vector
 *
 * @return vec_t
 */
vec_t vector_back(vector);

/**
 * @brief Returns a pointer to the array where the elements are contained
 *
 * @return vector_it
 */
vec_t* vector_data(vector);

/**
 * @brief Returns an iterator to the first element of the vector
 *
 * @return vector_it
 */
vector_it vector_begin(vector);

/**
 * @brief Returns an iterator to the last element of the vector
 *
 * @return vector_it
 */
vector_it vector_end(vector);

/**
 * @brief Returns whether the vector is empty
 *
 * @return true
 * @return false
 */
bool vector_is_empty(vector);

/**
 * @brief Allocates memory for the supplied number of elements
 *
 */
void vector_reserve(vector, size_t);

/**
 * @brief Shrinks the size of the array to the number of elements
 *
 */
void vector_shrink_to_fit(vector);

// Modifiers
void vector_clear(vector);
void vector_insert(vector, size_t, void*);
void vector_erase(vector, size_t);
void vector_erase_range(vector, size_t, size_t);
void vector_pushback(vector, void*);
