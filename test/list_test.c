#include "list.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    list *l = list_construct();

    for (int i = 0; i < 10; ++i) {
        list_push_back(l, (tvar)i);
    }

    for (list_it it = list_begin(l); it != list_end(l); list_it_add(&it, 1)) {
        printf("%d ", it->val.d);
    }

    list_destruct(l);
    return 0;
}
