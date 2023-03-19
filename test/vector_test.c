#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    vector *v = vector_construct();

    for (int i = 0; i < 10; ++i) {
        vector_push_back(v, (tvar)i);
    }

    for (int i = 0; i < 10; ++i) {
        printf("%d ", v->data[i].d);
    }

    vector_destruct(v);
    return 0;
}
