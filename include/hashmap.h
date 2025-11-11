#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdint.h>
#include <stddef.h>

typedef struct entry {
    const void *key;
    void *data;
    struct entry *next;
} entry_t;

typedef struct hashmap {
    int nb_entry;
    int max_size;
    entry_t **entry;
    size_t elm_size;
    int seed0;
    int seed1;
} hashmap_t;



hashmap_t *new_hashmap(size_t elmSize);
int set_hashmap(hashmap_t *map, const void *key, const void *item);
void *get_hashmap(hashmap_t *map, const void *key);
int count_hashmap(hashmap_t *map);
void free_hashmap(hashmap_t *map);



uint64_t SIP64(const uint8_t *in, const size_t inlen, uint64_t seed0, uint64_t seed1);
#endif
