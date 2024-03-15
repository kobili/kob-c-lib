#include <stdio.h>
#include "../array.h"

typedef struct {
    int x;
    int y;
} Point;

int test_insert_point() {
    // Setup
    Array* arr = init_array(sizeof(Point));

    // Action
    for (int i = 0; i < 100; i++) {
        Point p = { .x = i, .y = i };
        array_insert(arr, &p);
    }

    // Assert
    if (arr->size != 100) {
        printf("test_insert_point: Incorrect size: expected %d, got %d\n", 100, arr->size);
        return -1;
    }

    for (int i = 0; i < arr->size; i++) {
        Point *p = (Point*)array_retrieve(arr, i);
        if (p->x != i || p->y != i) {
            printf(
                "test_insert_point: Got a sequence error when iterating through the array: Expecting Point(%d, %d), got Point(%d, %d)\n",
                i, i, p->x, p->y
            );
            return -1;
        }
    }

    // Cleanup
    free_array(arr);

    return 0;
}

int test_remove_point() {
    // Setup
    Array* arr = init_array(sizeof(Point));

    for (int i = 0; i < 100; i++) {
        Point p = { .x = i, .y = i };
        array_insert(arr, &p);
    }

    // Action
    array_remove(arr, 25);

    // Assert
    Point* p = array_retrieve(arr, 25);
    if (p->x != 26 || p->y != 26) {
        printf("test_remove_point: Expected Point(%d, %d), got Point(%d, %d)\n", 26, 26, p->x, p->y);
        return -1;
    }

    for (int i = 0; i < 25; i++) { // Iterate and make sure the other elements are all in place
        Point* pt = array_retrieve(arr, i);
        if (pt->x != i || pt->y != i) {
            printf("test_remove_point: Expected Point(%d, %d), got Point(%d, %d)\n", i, i, p->x, p->y);
            return -1;
        }
    }
    for (int i = 25; i < arr->size; i++) {
        Point* pt = array_retrieve(arr, i);
        if (pt->x != i+1 || pt->y != i+1) {
            printf("test_remove_point: Expected Point(%d, %d), got Point(%d, %d)\n", i+1, i+1, p->x, p->y);
            return -1;
        }
    }

    // Cleanup
    free_array(arr);
    return 0;
}

int test_insert_integers() {
    // Setup
    Array* arr = init_array(sizeof(int));

    // Action
    for (int i = 0; i < 100; i++) {
        array_insert(arr, &i);
    }

    // Assert
    if (arr->size != 100) {
        printf("Incorrect size: expected %d, got %d\n", 100, arr->size);
        return -1;
    }

    for (int i = 0; i < 100; i++) {
        int* value = array_retrieve(arr, i);
        if (*value != i) {
            printf("Wrong value: expected %d, actual %d\n", i, *value);
            return -1;
        }
    }

    free_array(arr);

    return 0;
}

int main() {
    int result = 0;

    result = test_insert_point();
    result = test_remove_point();
    result = test_insert_integers();
    
    if (result == 0) {
        printf("test_array: All tests passed\n");
    } else {
        printf("test_array: Tests failed\n");
    }

    return result;
}
