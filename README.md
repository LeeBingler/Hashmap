# Hashmap

[Hash map](https://en.wikipedia.org/wiki/Hash_table) implementation in C.
Inspired by [this repo](https://github.com/tidwall/hashmap.c).

## Example

```c
#include <stdio.h>
#include "hashmap.h"

struct user {
    char *name;
    int age;
};

int main(void) {
    hashmap_t *map = new_hashmap(sizeof(struct user));
    set_hashmap(map, "adam", &(struct user){ .name="adam", .age=75});
    set_hashmap(map, "adam2", &(struct user){ .name="adam2", .age=22});
    set_hashmap(map, "adam3", &(struct user){ .name="adam3", .age=45});
    set_hashmap(map, "adam4", &(struct user){ .name="adam4", .age=88});

    struct user *user = NULL;
    printf("-- Get users --\n");
    user = get_hashmap(map, "adam");
    printf("name=%s age=%i\n", user->name, user->age);

    user = get_hashmap(map, "adam2");
    printf("name=%s age=%i\n", user->name, user->age);

    user = get_hashmap(map, "adam3");
    printf("name=%s age=%i\n", user->name, user->age);

    user = get_hashmap(map, "adam4");
    printf("name=%s age=%i\n", user->name, user->age);

    user = get_hashmap(map, "adam5");
    printf("%s\n", user?"exists":"not exists");

    printf("\n-- Delete user --\n");
    delete_hashmap(map, "adam");
    struct user *adam2 = get_hashmap(map, "adam");
    if (adam2) {
        printf("name=%s age=%i\n",adam2->name, adam2->age);
    } else {
        printf("adam2 does not exist\n");
    }

    free_hashmap(map);
    return 0;
}



// output:
// -- Get users --
// name=adam age=75
// name=adam2 age=75
// name=adam3 age=75
// name=adam4 age=75
// not exists
//
// -- Delete user --
// adam2 does not exist

```

## Functions

### Basic

```sh
new_hashmap      # allocate a new hash map
free_hashmap     # free the hash map
set_hashmap      # insert or replace an existing item and return the previous
get_hashmap      # get an existing item
delete_hashmap   # delete and return an item
```

## Using the `hashmap-c` Library in Your Project

You can use it either by linking statically (`.a`) or dynamically (`.so`) to your own project.

---

### 1. Build the Library
Clone the repository and run:

```bash
make lib
```

### 2. Include the header
In your C file, include the public header:

```c
#include "hashmap.h"
```
Make sure your compiler knows where to find it (-Iinclude).

### 3. Link Against the Library
To compile your program with the hashmap library, use:

```bash
gcc main.c -I./include -L./lib -lhashmap -o main
```

### 4. Static Linking (Optional)
If you prefer a single self-contained executable, link statically instead:
```bash
gcc main.c -I./include ./lib/libhashmap.a -o main
```


## License

This project is released under the MIT License. You are free to use, modify, and distribute it as you wish.