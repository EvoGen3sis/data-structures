#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

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
    if (arr -> size == arr -> capacity){
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
        for (size_t i = 0; i < arr -> size; i ++){
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

bool get_array(DynamicArr* arr, size_t index, int *out){
    if (arr == NULL || out == NULL) return false;
    if (index < arr -> size){
        *out = arr -> data[index]; // References an external pointer
        return true;
    }
    return false;
}

bool pop_array(DynamicArr *arr, int *out){
    if (arr == NULL || out == NULL){
        return false;
    }
    if (arr -> size > 0){
        arr -> size --;
        *out = arr -> data[arr -> size];
        if (arr -> size <= (arr -> capacity / 4) && arr -> capacity > 8){
            int *tmp = realloc(arr -> data, (arr -> capacity / 2) * sizeof(int));
            if (tmp != NULL){
                arr -> data = tmp;
                arr -> capacity /= 2;
            }
        }
        return true;
    }
    return false;
}

bool pop_unique(DynamicArr *arr, size_t index, int *out){
    if (arr == NULL || out == NULL) return false;
    if (index < arr -> size) {
        *out = arr -> data[index];
        for (size_t i = index; i < arr -> size - 1; i ++){
            arr -> data[i] = arr -> data[i + 1];
        }
        arr -> size --;
        return true;
    }
    return false;
}
