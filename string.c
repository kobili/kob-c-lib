#include "string.h"

String* new_string(char s[]) {
    String* str = malloc(sizeof(String));

    int i = 0;
    while (1) {
        char current_char = s[i];
        i++;
        if (current_char == '\0') {
            break;
        }
    }

    str->length = i - 1;
    str->value = malloc(sizeof(char) * i);

    return str;
}

void free_string(String* s) {
    free(s->value);
    free(s);
}
