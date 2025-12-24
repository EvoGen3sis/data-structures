#ifndef DYNAMIC_ARRAY_H // Checks if the dynamic array has already been defined, conditional header guard
#define DYNAMIC_ARRAY_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} DynamicArr;

DynamicArr* create_array(size_t initial_capacity);

int push_array(DynamicArr *arr, int item);

void print_array(const DynamicArr *arr);

void destroy_array(DynamicArr *arr);

bool get_array(const DynamicArr* arr, size_t index, int *out);

int* pop_array(DynamicArr *arr, bool rtn);

int pop_unique(DynamicArr *arr, size_t index);

#endif
