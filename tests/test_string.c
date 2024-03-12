#include <stdio.h>
#include <string.h>

#include "../string.h"

int test_string_assignment(char s[]) {
    String* str = new_string(s);

    if (strlen(str->value) != str->length) {
        printf("String has the wrong length: expected %lu, got %zu", strlen(str->value), str->length);
        return -1;
    }

    for (int i = 0; i < str->length; i++) {
        if (char_at(str, i) != s[i]) {
            printf("Wrong character at index %d: Expected %c, got %c", i, s[i], char_at(str, i));
            return -1;
        }
    }

    free_string(str);

    return 0;
}

int main() {
    int test_result = test_string_assignment("Hello world!");
    return 0;
}