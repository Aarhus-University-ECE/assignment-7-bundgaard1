#include "stack.h"

#include <assert.h>

void initialize(stack* s) {
    // Make head of the stack equal to NULL
    s->head = NULL;
    return;
}

void push(int x, stack* s) {
    node* prev = s->head;
    s->head = (node*)malloc(sizeof(node));  // Make new node, allocate memory
    s->head->data = x;                      // Set correct values to new node
    s->head->next = prev;
}

int pop(stack* s) {
    // Pre: make sure the function is not empty
    assert(!empty(s));

    node* top = s->head;    // Pointer to the top element of the stack
    s->head = top->next;    // Head to the second to top element of stack
    int value = top->data;  // Get the data of top
    free(top);              // Free the memory
    return value;
}

bool empty(stack* s) {
    // If the head of the stack is NULL, the stack is empty
    if (s->head == NULL) {
        return true;
    }
    return false;
}

bool full(stack* s) {
    // The stack is never full.
    return false;
}
