#ifndef K_STRING_H
#define K_STRING_H

#include <stdlib.h>

typedef struct {
    size_t length;
    char* value;
} String;

String* new_string(char s[]);
void free_string(String* s);
char char_at(String* s, int index);

#endif
