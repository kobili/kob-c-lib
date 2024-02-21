#ifndef ARRAY_H
#define ARRAY_H

typedef struct {
    void *container;   // container for the array elements
    int capacity;       // how many elements the array can hold
    int size;           // how many elements are in the array
    int element_size;  // the size of each individual element (in bytes)
} Array;

/*
    Initialize an array with an initial capacity of 5;
*/
Array* init_array(int element_size);

/*
    Free array resources
*/
void free_array(Array* arr);

/*
    Insert the element into the array
*/
void array_insert(Array *arr, void *p);

/*
    Remove the element at the given index.
*/
void array_remove(Array *arr, int index);

/*
    Retrieve an element from the array at the given index.

    If the index lies outside of the array, returns `NULL`.
    Otherwise returns a pointer to the element at the index.
*/
void* array_retrieve(Array *arr, int index);

#endif
