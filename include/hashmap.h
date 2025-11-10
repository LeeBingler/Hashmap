#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdint.h>

typedef struct entry {
    uint64_t hash;
    uint64_t data;
} entry_t;

typedef struct hashmap {
    char *yes;
    entry_t *entry;
    size_t elmSize;
} hashmap_t;



hashmap_t *new_hashmap(size_t elmSize);
void free_hashmap(hashmap_t *map);

#endif
