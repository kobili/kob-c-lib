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

    for (int i = 0; i < 4; i++) {
        printf("%d\n", s[i] == '\0');
        printf("%c\n", s[i]);
    }

    // printf("%d\n", sizeof(*s));

    return 0;
}
