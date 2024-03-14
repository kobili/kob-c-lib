#include "string.h"
#include <string.h>
#include <stdio.h>

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

    strcpy(str->value, s);

    return str;
}

void free_string(String* s) {
    free(s->value);
    free(s);
}

char char_at(String* s, int index) {
    if (index < 0 || index >= s->length) {
        printf("char_at - Index out of bound");
        return '\0';
    }
    return s->value[index];
}

void write_string_to_file(String* input, FILE** fptr) {
    size_t input_length = input->length;
    fwrite(&input_length, sizeof(size_t), 1, *fptr);
    fwrite(input->value, sizeof(char), input_length, *fptr);
}

String* read_string_from_file(FILE** fptr) {
    size_t length;
    fread(&length, sizeof(size_t), 1, *fptr);
    char output[length];
    fread(output, sizeof(char), length, *fptr);

    return new_string(output);
}
