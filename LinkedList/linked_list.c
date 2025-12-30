#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;

struct Node {
    size_t data;
    Node* next;
};
typedef struct {
    Node *head, *tail;
    size_t size;
} LList;

LList* create_list(){
    LList* list = (LList*) malloc(sizeof(LList));
    if (list != NULL) {
        list -> size = 0;
        list -> head = list -> tail = NULL;
        return list;
    }
    return NULL;
}

bool push_list(LList* list, size_t data){
    if (list != NULL){
        if (list -> size = 0 && list -> head == NULL){
            list -> head -> data = data;
        }
    }
    return false;
}
