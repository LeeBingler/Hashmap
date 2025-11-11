#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

struct user {
    char *name;
    int age;
};

int main(void) {
    printf("-- Test start --\n");
    hashmap_t *map = new_hashmap(sizeof(struct user));
    assert(map != NULL);
    assert(count_hashmap(map) == 0);

    assert(set_hashmap(map, "adam", &(struct user){ .name="adam", .age=75}) == 0);
    assert(count_hashmap(map) == 1);

    struct user *user = NULL;

    user = get_hashmap(map, "adam");
    assert(user != NULL);
    assert(user->age == 75);

    user = get_hashmap(map, "adam5");
    assert(user == NULL);

    user = delete_hashmap(map, "adam");
    assert(strcmp(user->name, "adam") == 0);
    free(user);

    user = get_hashmap(map, "adam");
    assert(user == NULL);

    assert(delete_hashmap(map, "do_not_exist") == NULL);

    free_hashmap(map);

    printf("-- Test end --\n");
    return 0;
}
