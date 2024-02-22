#include <stdio.h>
#include "array.h"

void array_print(Array *arr) {
    for (int i = 0; i < arr->size; i++) {
        int *p = (int*)array_retrieve(arr, i);
        printf("%d\n", *p);
    }
}

int test_sequential(Array *arr) {
    int prev = -1;

    for (int i = 0; i < arr->size; i++) {
        int *p = (int*)array_retrieve(arr, i);
        if (*p != prev + 1) {
            printf("Got a sequence error when iterating through the array: %d does not follow %d\n", *p, prev);
            return -1;
        }
        prev = *p;
    }
    return 0;
}

int main() {
    Array* arr = init_array(sizeof(int));

    printf("TEST INSERT\n");
    for (int i = 0; i < 100; i++) {
        int p = i;
        array_insert(arr, &p);
        printf("Inserted %d\n", p);
    }

    printf("TEST SEQUENTIAL\n");
    int result = 0;
    result = test_sequential(arr);

    printf("TEST REMOVE\n");
    array_remove(arr, 25);
    array_print(arr);

    free_array(arr);
    
    return result;
}
