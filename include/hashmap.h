#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdint.h>

typedef struct entry {
    uint64_t hash;
    const void *data;
} entry_t;

typedef struct hashmap {
    int nb_entry;
    int max_size;
    entry_t *entry;
    size_t elm_size;
} hashmap_t;



hashmap_t *new_hashmap(size_t elmSize);
const void *set_hashmap(hashmap_t *map, const void *key, const void *item);
void free_hashmap(hashmap_t *map);

#endif
