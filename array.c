#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

int push_array(DynamicArr *arr, int item){
    if (arr == NULL){
        return -1;
    }
    if (arr -> size >= arr -> capacity){
        size_t new_capacity = (arr -> capacity == 0) ? 1: arr -> capacity * 2;
        int *tmp = realloc(arr -> data, new_capacity * sizeof(int));
        if (tmp == NULL){
            return -1;
        }
        arr -> data = tmp;
        arr -> capacity = new_capacity;
    }
    arr -> data[arr -> size] = item;
    arr -> size ++;
    return 0;
}

void print_array(DynamicArr *arr){
    if (arr -> size > 0){
        printf("[");
        for (int i = 0; i < arr -> size; i ++){
            printf("%d", arr -> data[i]);
            if (i < arr -> size - 1) printf(", ");
        }
        printf("]\n");
        printf("(size: %zu, capacity: %zu)\n", arr -> size, arr -> capacity);
    }
}

void destroy_array(DynamicArr *arr){
    if (arr != NULL){
        free(arr -> data);
        free(arr);
    }   
}

int* get_array(DynamicArr* arr, size_t index){
    if (arr != NULL){
        if (0 <= index < arr -> size){
            // printf("%d", arr -> data[index]);
            return &arr -> data[index];
        }
    }
}

int* pop_array(DynamicArr *arr, bool rtn){
    if (arr != NULL && arr -> size > 0){
        arr -> size --;
        if (rtn == true) return &arr -> data[arr -> size];
            return NULL;
    }
    return NULL;
}

int pop_unique(DynamicArr *arr, size_t index){
    if (arr != NULL && index <= arr -> size - 1) {
        int pop = arr -> data[index];
        for (int i = index; i < arr -> size - 1; i ++){
            arr -> data[i] = arr -> data[i + 1];
        }
        arr -> size --;
        return pop;
    }
    return -1;
}

int main (void){
    DynamicArr *arr = create_array(64);

    print_array(arr);
    push_array(arr, 2);
    print_array(arr);
    push_array(arr, 10);
    print_array(arr);
    pop_array(arr, true);
    print_array(arr);

    return 0;
}
