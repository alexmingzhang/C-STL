#pragma once

#include <stdbool.h>
#include <stdlib.h>

typedef void* vec_t;
typedef vec_t* vector_it;

typedef struct _vector {
    size_t size;
    size_t capacity;
    vec_t* data;
}* vector;

vector vector_construct();
void vector_destruct(vector);

// Accessors
vec_t vector_at(vector, size_t);
vec_t vector_front(vector);
vec_t vector_back(vector);
vector_it vector_data(vector);

// Iterators
vector_it vector_begin(vector);
vector_it vector_end(vector);

// Capacity
bool vector_is_empty(vector);
void vector_reserve(vector, size_t);
void vector_shrink_to_fit(vector);

// Modifiers
void vector_clear(vector);
void vector_insert(vector, size_t, void*);
void vector_erase(vector, size_t);
void vector_erase_range(vector, size_t, size_t);
void vector_pushback(vector, void*);
