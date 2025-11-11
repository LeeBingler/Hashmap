#include <stdio.h>
#include "hashmap.h"

struct user {
    char *name;
    int age;
};

int main(void) {
    hashmap_t *map = new_hashmap(sizeof(struct user));
    set_hashmap(map, "adam", &(struct user){ .name="adam", .age=75});
    free_hashmap(map);
    return 0;
}
