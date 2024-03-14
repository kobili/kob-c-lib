#include <stdio.h>
#include <string.h>

#include "../string.h"

int test_string_assignment() {
    char s[] = "Hello World!";

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

int test_string_file_io() {
    String* expected_value = new_string("Hello, Deep!");

    FILE* fptr = fopen("test_strings", "wb");
    write_string_to_file(expected_value, &fptr);
    fclose(fptr);

    fptr = fopen("test_strings", "rb");
    String* read_value = read_string_from_file(&fptr);
    fclose(fptr);

    if (expected_value->length != read_value->length) {
        printf("Unequal string lengths: Expected %lu, got %lu\n", expected_value->length, read_value->length);
        return -1;
    }

    if (strcmp(expected_value->value, read_value->value) != 0) {
        printf("Unequal strings: Expected %s, got %s", expected_value->value, read_value->value);
        return -1;
    }

    return 0;
}

int main() {
    int test_result = 0;
    test_result = test_string_assignment();
    test_result = test_string_file_io();
    return test_result;
}