#ifndef K_STRING_H
#define K_STRING_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    size_t length;
    char* value;
} String;

String* new_string(char s[]);
void free_string(String* s);
char char_at(String* s, int index);
void write_string_to_file(String* input, FILE** fptr);
String* read_string_from_file(FILE** fptr);

#endif
