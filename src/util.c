/**
 * @file util.c
 * @author Alex M. Zhang
 * @brief Contains the definitions of utility functions
 * @date 2023-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "util.h"

#include <stdio.h>
#include <string.h>

int compare_longs(long a, long b) {
    if (a < b) {
        return -1;
    }

    if (a == b) {
        return 0;
    }

    return 1;
}

void print_bytes(void *a, size_t size) {
    char *c = (char *)a;
    for (size_t i = 0; i < size; ++i) {
        printf("%02hhx", c[i]);
    }
    printf("\n");
}
