#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#include "hashing.h"

typedef struct {
    char* key;
    char* value;
} map_entry;

int main() {
    char* s = "abc";

    uint32_t hash = fnv_hash_32(s, strlen(s));
    printf("%u\n", hash);

    return 0;
}
