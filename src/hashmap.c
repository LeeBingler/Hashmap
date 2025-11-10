#include <stdlib.h>
#include "hashmap.h"

#define DEFAULT_MAX_SIZE_HASHMAP 16

hashmap_t *new_hashmap(size_t elm_size) {
    hashmap_t *map = calloc(1, sizeof(hashmap_t));
    if (!map) return NULL;
    entry_t *entry = calloc(1, sizeof(entry_t));
    if (!entry) return NULL;
    map->elm_size = elm_size;
    map->max_size = DEFAULT_MAX_SIZE_HASHMAP;

    return map;
}

const void *set_hashmap(hashmap_t *map, const void *key, const void *item) {
    return;
}

void free_hashmap(hashmap_t *map) {
    if (!map) return;
    free(map);
}
