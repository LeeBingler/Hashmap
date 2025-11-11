#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hashmap.h"

#define DEFAULT_MAX_SIZE_HASHMAP 16

hashmap_t *new_hashmap(size_t elm_size) {
    hashmap_t *map = calloc(1, sizeof(hashmap_t));
    if (!map) return NULL;

    map->entry = calloc(DEFAULT_MAX_SIZE_HASHMAP, sizeof(entry_t));
    if (!map->entry) {
        free(map);
        return NULL;
    }

    map->elm_size = elm_size;
    map->max_size = DEFAULT_MAX_SIZE_HASHMAP;
    map->seed0 = 0;
    map->seed1 = 1;

    return map;
}

int set_hashmap(hashmap_t *map, const void *key, const void *item) {
    if(!map || !key || !item) return -1;

    uint64_t hash = SIP64(key, strlen(key), map->seed0, map->seed1) % (map->max_size - 1);

    printf("%ld\n", hash);


    map->entry[hash].key = key;
    map->entry[hash].data = item;
    map->nb_entry++;

    return 0;
}

void free_hashmap(hashmap_t *map) {
    if (!map) return;
    free(map->entry);
    free(map);
}
