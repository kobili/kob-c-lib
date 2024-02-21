#include <stdio.h>
#include "array.h"

int test_sequential(Array *arr) {
    Point test_point = { .x = -1, .y = -1 };

    for (int i = 0; i < arr->size; i++) {
        Point p = array_retrieve(arr, i);
        if (p.x != test_point.x + 1 || p.y != test_point.y + 1) {
            printf("Got a sequence error when iterating through the array: Point(%d, %d) does not follow Point(%d, %d)\n", p.x, p.y, test_point.x, test_point.y);
            return -1;
        }
        test_point = p;
    }
    return 0;
}

int main() {
    Array* arr = init_array();

    for (int i = 0; i < 100; i++) {
        Point p = { .x = i, .y = i };
        array_insert(arr, p);
        printf("Point(%d, %d)\n", p.x, p.y);
    }

    int result = 0;
    result = test_sequential(arr);

    free_array(arr);
    
    return result;
}
