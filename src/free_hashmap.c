#include "hashmap.h"
#include <stdlib.h>

static void free_entry_node(entry_t *node) {
    free(node->data);
    free((void *) node->key);
    free(node);
}

static void free_entry(hashmap_t *map) {
    entry_t *node = NULL;
    entry_t *next = NULL;

    for (int i = 0; i < map->max_size; i++) {
        if (map->entry[i] == NULL) continue;
        node = map->entry[i];

        while(node->next != NULL) {
            next = node->next;
            free_entry_node(node);
            node = next;
        }
        free_entry_node(node);
    }
}

void free_hashmap(hashmap_t *map) {
    if (!map) return;

    free_entry(map);
    free(map->entry);
    free(map);
}