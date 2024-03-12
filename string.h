#ifndef STRING_H
#define STRING_H

#include <stdlib.h>

typedef struct {
    size_t length;
    char* value;
} String;

String* new_string(char s[]);
void free_string(String* s);

#endif
