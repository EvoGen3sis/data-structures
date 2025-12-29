#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int data;
    Node* next;
};
typedef struct {
    Node* head;
    Node* tail;
    size_t capacity;
    size_t size;
} LList;

LList* create_list(size_t initial_capacity){
    LList* list = (LList*) malloc(sizeof(LList));
    if (list == NULL || initial_capacity < 1) {
        free(list);
        return NULL;
    }
    return list;
}
