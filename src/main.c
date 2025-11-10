#include <stdio.h>
#include "hashmap.h"

struct user {
    char *name;
    int age;
};

int main(void) {
    hashmap_t *map = new_hashmap(sizeof(struct user));
    putchar(map->max_size + 32);
    putchar('\n');
    free_hashmap(map);
    return 0;
}
