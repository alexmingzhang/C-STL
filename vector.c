#include "vector.h"

#include <assert.h>

vector vector_construct() {
    vector v = malloc(sizeof(struct _vector));
    v->size = 0;
    v->capacity = 1;
    v->data = malloc(sizeof(void *));
    return v;
}

void vector_destruct(vector v) {
    free(v->data);
    free(v);
}

vec_t vector_at(vector v, size_t index) {
    assert(index < v->size);
    return v->data[index];
}

vec_t *vector_data(vector v) { return (v->data); }

vector_it vector_begin(vector v) { return (v->data); }

vector_it vector_end(vector v) { return (v->data + v->size); }

bool vector_is_empty(vector v) { return v->size == 0; }

void vector_reserve(vector v, size_t new_capacity) {
    v->data = realloc(v->data, sizeof(void *) * new_capacity);
    v->capacity = new_capacity;
}

void vector_shrink_to_fit(vector v) {
    v->data = realloc(v->data, sizeof(void *) * v->size);
    v->capacity = v->size;
}

void vector_clear(vector v) { v->size = 0; }

void vector_insert(vector v, size_t pos, void *value) {
    if (v->capacity < v->size + 1) {
        vector_reserve(v, v->capacity * 2);
    }

    for (size_t i = v->size - pos + 1; i >= pos; --i) {
        v->data[i] = v->data[i - 1];
    }

    v->data[pos] = value;
    ++v->size;
}

void vector_erase(vector v, size_t index) {
    for (size_t i = index; i < v->size - 1; ++i) {
        v->data[i] = v->data[i + 1];
    }
    --v->size;
}

void vector_erase_range(vector v, size_t first, size_t last) {
    size_t num_erase = last - first;
    for (size_t i = first; i < v->size - num_erase; ++i) {
        v->data[i] = v->data[i + num_erase];
    }
    v->size -= num_erase;
}

void vector_pushback(vector v, void *value) {
    if (v->capacity < v->size + 1) {
        vector_reserve(v, v->capacity * 2);
    }

    v->data[v->size++] = value;
}
