#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"


Array* init_array(int element_size) {
    Array* arr = malloc(sizeof(Array));
    arr-> capacity = 5;
    arr->container = malloc(element_size * arr->capacity);
    arr->size = 0;
    arr->element_size = element_size;

    return arr;
}

void free_array(Array* arr) {
    free(arr->container);
    free(arr);
}

void array_insert(Array *arr, void *p) {
    if ((double)arr->size / (double)arr->capacity > 0.75) {
        int prev_capacity = arr->capacity;
        void* old_container = arr->container;

        // Initialize new container
        int new_capacity = arr->capacity * 1.5;
        void* new_container = malloc(arr->element_size * new_capacity);

        // Copy over existing array elements
        memcpy(new_container, old_container, arr->size * arr->element_size);

        // Deallocate the old container
        free(old_container);

        // Update the array
        arr->capacity = new_capacity;
        arr->container = new_container;
    }

    // insert new element by copying it from memory
    memcpy(arr->container + arr->size * arr->element_size, p, arr->element_size);
    arr->size = arr->size + 1;
}

void array_remove(Array *arr, int index) {
    if (index >= arr->size) {
        printf("IndexOutOfBounds - index: %d; range: [0, %d]\n", index, arr->size-1);
        return;
    }

    // Shift elements one place to the left
    void* dest_address = arr->container + index * arr->element_size;
    void* src_address = arr->container + (index+1) * arr->element_size;
    int bytes_to_copy = (arr->size - index - 1) * arr->element_size;
    memmove(dest_address, src_address, bytes_to_copy);

    arr->size = arr->size - 1;
}

void* array_retrieve(Array *arr, int index) {
    if (index >= arr->size) {
        printf("IndexOutOfBounds - index: %d; range: [0, %d]\n", index, arr->size-1);
    }

    // return the address of the element
    return arr->container + index * arr->element_size;
}
