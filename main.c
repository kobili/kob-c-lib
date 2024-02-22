#include <stdio.h>
#include "array.h"

typedef struct {
    char* key;
    char* value;
} map_entry;

int main() {
    Array* arr = init_array(sizeof(map_entry));

    map_entry e1 = { .key = "test", .value = "deep" };
    map_entry e2 = { .key = "hehe", .value = "eeep" };

    array_insert(arr, &e1);
    array_insert(arr, &e2);

    for (int i = 0; i < arr->size; i++) {
        map_entry *entry = (map_entry*)array_retrieve(arr, i);
        printf("MapEntry(key: %s, value: %s)\n", entry->key, entry->value);
    }

    free_array(arr);

    return 0;
}
