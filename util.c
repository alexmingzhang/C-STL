#include "util.h"

int compare_longs(long a, long b) {
    if (a < b) {
        return -1;
    }

    if (a == b) {
        return 0;
    }

    return 1;
}
