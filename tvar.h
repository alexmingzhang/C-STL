#pragma once

#include <stdbool.h>

/**
 * @brief A crude workaround for template variables
 *
 */
typedef union _tvar {
    bool b;
    char c;
    signed char hhi;
    unsigned char hhu;
    signed short hi, hd;
    unsigned short hu;
    signed int i, d;
    unsigned int u;
    signed long li, ld;
    unsigned long lu;
    float f;
    double lf;

    char *s;
    void *p;
} tvar;
