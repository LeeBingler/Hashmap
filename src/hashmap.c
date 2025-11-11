#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "hashmap.h"

#define DEFAULT_MAX_SIZE_HASHMAP 16

static uint64_t get_hash(hashmap_t *map, const void *key) {
    return SIP64(key, strlen(key), map->seed0, map->seed1) % (map->max_size - 1);
}

hashmap_t *new_hashmap(size_t elm_size) {
    hashmap_t *map = calloc(1, sizeof(hashmap_t));
    if (!map) return NULL;

    map->entry = calloc(DEFAULT_MAX_SIZE_HASHMAP, sizeof(entry_t *));
    if (!map->entry) {
        free(map);
        return NULL;
    }

    map->elm_size = elm_size;
    map->max_size = DEFAULT_MAX_SIZE_HASHMAP;

    srand(time(NULL));
    map->seed0 = rand();
    map->seed1 = rand();

    return map;
}

int set_hashmap(hashmap_t *map, const void *key, const void *item) {
    if(!map || !key || !item) return -1;

    uint64_t hash = get_hash(map, key);

    void *copy = calloc(1, map->elm_size);
    if(!copy) return -1;
    memcpy(copy, item, map->elm_size);

    entry_t *node = map->entry[hash];
    entry_t *new_node = calloc(1, sizeof(entry_t));

    new_node->key = strdup(key);
    new_node->data = copy;
    new_node->next = NULL;

    if (node) {
        while (node->next != NULL) node = node->next;
        node->next = new_node;
    } else {
        map->entry[hash] = new_node;
    }

    map->nb_entry++;

    return 0;
}

int count_hashmap(hashmap_t *map) {
    return map->nb_entry;
}

void *get_hashmap(hashmap_t *map, const void *key) {
    if (!map || !key) return NULL;

    uint64_t hash = get_hash(map, key);
    entry_t *node = map->entry[hash];

    while (node) {
        if (strcmp(node->key, key) == 0)
            return node->data;

        node = node->next;
    }

    return NULL;
}


void *delete_hashmap(hashmap_t *map, const void *key) {
    if (!map || !key) return NULL;

    uint64_t hash = get_hash(map, key);
    entry_t **head = &map->entry[hash];
    entry_t *temp = *head;
    entry_t *prev = NULL;
    void *data = NULL;

    if (temp && strcmp(temp->key, key) == 0) {
        *head = temp->next;
        data = temp->data;
        free((void *)temp->key);
        free(temp);
        return data;
    }

    while (temp && strcmp(temp->key, key) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) return NULL;

    prev->next = temp->next;

    data = temp->data;
    free((void *)temp->key);
    free(temp);

    map->nb_entry--;
    return data;
}