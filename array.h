#ifndef ARRAY_H
#define ARRAY_H

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *container;   // container for the array elements
    int capacity;       // how many elements the array can hold
    int size;           // how many elements are in the array
} Array;

/*
    Initialize an array with an initial capacity of 5;
*/
Array* init_array();

/*
    Free array resources
*/
void free_array(Array* arr);

/*
    Insert the element into the array
*/
void array_insert(Array *arr, Point p);

/*
    Remove the element at the given index.
*/
void array_remove(Array *arr, int index);

/*
    Retrieve an element from the array at the given index.

    If the index lies outside of the array, returns `NULL`.
    Otherwise returns a pointer to the element at the index.
*/
Point* array_retrieve(Array *arr, int index);

void array_print(Array *arr);

#endif
