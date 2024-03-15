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

    if (strcmp(s, str->value) != 0) {
        printf("Strings are not equal: Expected %s, got %s\n", s, str->value);
        return -1;
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

    int i = 0;
    while (read_value->value[i] != '\0' && i <= strlen(read_value->value) + 2) {
        i++;
    }

    if (i != read_value->length) {
        printf("No null terminator in copied string\n");
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
