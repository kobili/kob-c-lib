#include "array.h"

int main() {
    Array* arr = init_array();

    for (int i = 0; i < 10; i++) {
        Point p = { .x = i, .y = i };
        array_insert(arr, p);
    }
    array_print(arr);

    free_array(arr);
    
    return 0;
}
