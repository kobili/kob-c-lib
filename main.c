#include <stdio.h>

#include "string.h"

int main() {
    String* str = new_string("Hello world");

    printf("%s\n", str->value);

    free_string(str);

    return 0;
}
