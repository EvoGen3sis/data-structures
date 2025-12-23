#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data; // Points to where our array is stored in memory
    size_t size; // How many elements are currently being stored (integer)
    size_t capacity; // How many elements can be stored before we need to reallocate memory (positive integer)
} DynamicArr;

DynamicArr* create_array(size_t initial_capacity){
    DynamicArr *arr = (DynamicArr*) malloc(sizeof(DynamicArr));
    if (arr == NULL){
        return NULL; // If no memory allocated for arr return null 
    }
    arr -> data = (int*) malloc(initial_capacity * sizeof(int));
    if (arr -> data == NULL){
        free(arr);
        return NULL;
    }
    arr -> size = 0;
    arr -> capacity = initial_capacity;
    return arr;
}

void push_array(DynamicArr *arr, int item){
    if (arr == NULL){
        return;
    }
    if (arr -> size == arr -> capacity){
        size_t new_capacity = arr -> capacity * 2;
        int *tmp = realloc(arr -> data, new_capacity * sizeof(int));
        if (tmp == NULL){
            return;
        }
        arr -> data = tmp;
        arr -> capacity = new_capacity;
    }
    arr -> data[arr -> size] = item;
    arr -> size ++;
}

int main (void){
    return 0;
}
