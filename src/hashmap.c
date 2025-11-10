#include <stdlib.h>
#include "hashmap.h"

hashmap_t *new_hashmap(size_t elmSize) {
    hashmap_t *map = calloc(1, sizeof(hashmap_t));
    if (!map) return NULL;
    map->yes = "c";
    map->elmSize = elmSize;
    return map;
}

void free_hashmap(hashmap_t *map) {
    free(map);
}
