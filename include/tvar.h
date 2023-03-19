/**
 * @file tvar.h
 * @author Alex M. Zhang
 * @brief Contains the definition of the tvar union data type
 * @date 2023-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include <stdbool.h>

/**
 * @brief A crude workaround for template variables
 *
 */
typedef union {
    bool b;
    char c;
    signed char hhi;
    unsigned char hhu;
    signed short hd, hi;
    unsigned short hu;
    signed int d, i;
    unsigned int u;
    signed long ld, li;
    unsigned long lu;
    float f;
    double lf;
    char *s;
    void *p;
} tvar;
