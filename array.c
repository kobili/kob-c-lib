#include <stdio.h>
#include <stdlib.h>
#include "array.h"


/*
    Initialize an array with an initial capacity of 5;
*/
Array* init_array() {
    Array* arr = malloc(sizeof(Array));
    arr-> capacity = 5;
    arr->container = malloc(sizeof(Point) * arr->capacity);
    arr->size = 0;

    printf("init_array: Allocated array with capacity = %d and initial size = %d\n", arr->capacity, arr->size);

    return arr;
}

/*
    Free array resources
*/
void free_array(Array* arr) {
    free(arr->container);
    free(arr);

    printf("free_array: Freed array\n");
}

/*
    Insert the element into the array
*/
void array_insert(Array *arr, Point p) {
    if ((double)arr->size / (double)arr->capacity > 0.5) {
        int prev_capacity = arr->capacity;
        Point* old_container = arr->container;

        // Initialize new container
        int new_capacity = arr->capacity * 2;
        Point* new_container = malloc(sizeof(Point) * new_capacity);

        // Copy over existing array elements
        for (int i = 0; i < arr->size; i++) {
            new_container[i] = old_container[i];
        }

        // Deallocate the old container
        free(old_container);

        // Update the array
        arr->capacity = new_capacity;
        arr->container = new_container;

        printf("array_insert - Resized array capacity from %d to %d\n", prev_capacity, arr->capacity);
    }

    arr->container[arr->size] = p;
    arr->size = arr->size + 1;
}

/*
    Remove the element at the given index.
*/
void array_remove(Array *arr, int index) {
    if (index >= arr->size) {
        printf("IndexOutOfBounds - index: %d; range: [0, %d]\n", index, arr->size-1);
        return;
    }

    // Shift elements one place to the left
    // This'll end up overwriting the element at index
    for (int i = index; i < arr->size; i++) {
        arr->container[i] = arr->container[i+1];
    }

    arr->size = arr->size - 1;
}

/*
    Retrieve an element from the array at the given index.

    If the index lies outside of the array, returns `NULL`.
    Otherwise returns a pointer to the element at the index.
*/
Point* array_retrieve(Array *arr, int index) {
    if (index >= arr->size) {
        printf("IndexOutOfBounds - index: %d; range: [0, %d]\n", index, arr->size-1);
        return NULL;
    }
    return &arr->container[index];
}

void array_print(Array *arr) {
    for (int i = 0; i < arr->size; i++) {
        Point *p = array_retrieve(arr, i);
        if (p != NULL) {
            printf("Point(%d, %d)\n", p->x, p->y);
        }
    }
}
