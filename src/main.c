#include <stdio.h>
#include "hashmap.h"

struct user {
    char *name;
    int age;
};

int main(void) {
    hashmap_t *map = new_hashmap(sizeof(struct user));
    set_hashmap(map, "adam", &(struct user){ .name="adam", .age=75});
    set_hashmap(map, "adam2", &(struct user){ .name="adam2", .age=88});
    struct user *adam = get_hashmap(map, "adam2");
    printf("%s age is :%i\n",adam->name, adam->age);
    free_hashmap(map);
    return 0;
}
