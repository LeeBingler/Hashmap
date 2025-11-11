#include <stdio.h>
#include "hashmap.h"

struct user {
    char *name;
    int age;
};

int main(void) {
    hashmap_t *map = new_hashmap(sizeof(struct user));
    set_hashmap(map, "adam", &(struct user){ .name="adam", .age=75});
    set_hashmap(map, "adam", &(struct user){ .name="adam", .age=22});
    set_hashmap(map, "adam2", &(struct user){ .name="adam2", .age=45});
    set_hashmap(map, "adam3", &(struct user){ .name="adam3", .age=88});

    struct user *adam = get_hashmap(map, "adam");
    printf("%s age is :%i\n",adam->name, adam->age);
    printf("nb entry %i\n", count_hashmap(map));

    delete_hashmap(map, "adam");
    struct user *adam2 = get_hashmap(map, "adam");
    if (adam2) {
        printf("%s age is :%i\n",adam2->name, adam2->age);
    } else {
        printf("adam2 does not exist\n");
    }


    free_hashmap(map);
    return 0;
}
