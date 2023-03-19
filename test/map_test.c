#include "map.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    map *m = map_construct();

    for (int i = 0; i < 10; ++i) {
        map_insert(m, map_node_construct((tvar)i, (tvar)i));
    }

    for (int i = 0; i < 10; ++i) {
        map_node *n = map_find(m, (tvar)i);
        printf("%d ", n->val.d);
    }

    map_destruct(m);
    return 0;
}
