/*****************************************************************************
* CMP_SC 2050
* Lab 5
* By Drew Stockton
* October 3rd 2025
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "lab7.h"

/* Node structure for the linked list */
typedef struct _Node {
    void *data;
    struct _Node *next;
} Node;

/* Stack structure with top pointer and size counter */
struct _Stack {
    Node *top;
    int size;
};

/*
 * initStack
 * Allocates and initializes an empty stack.
 * Returns a pointer to the new stack, or NULL on failure.
 */
Stack * initStack()
{
    Stack *s = malloc(sizeof(Stack));
    if (s == NULL)
    {
        return NULL;
    }
    s->top = NULL;
    s->size = 0;
    return s;
}

/*
 * getSize
 * Returns the number of elements currently on the stack.
 */
int getSize(Stack * s)
{
    if (s == NULL)
    {
        return 0;
    }
    return s->size;
}

/*
 * peekStack
 * Returns the data at the top of the stack without removing it.
 * Returns NULL if the stack is empty or NULL.
 */
void * peekStack(Stack * s)
{
    if (s == NULL || s->top == NULL)
    {
        return NULL;
    }
    return s->top->data;
}

/*
 * pushStack
 * Pushes a data item onto the top of the stack.
 * Returns 0 on success, 1 on failure.
 */
int pushStack(Stack * s, void *data)
{
    if (s == NULL)
    {
        return 1;
    }
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return 1;
    }
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
    return 0;
}

/*
 * popStack
 * Removes and returns the data item from the top of the stack.
 * Returns NULL if the stack is empty.
 */
void * popStack(Stack * s)
{
    if (s == NULL || s->top == NULL)
    {
        return NULL;
    }
    Node *temp = s->top;
    void *data = temp->data;
    s->top = temp->next;
    s->size--;
    free(temp);
    return data;
}

/*
 * stackContains
 * Searches the stack for the given data pointer.
 * Returns 1 if found, 0 otherwise.
 */
int stackContains(Stack * s, void *data)
{
    if (s == NULL)
    {
        return 0;
    }
    Node *current = s->top;
    while (current != NULL)
    {
        if (current->data == data)
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

/*
 * freeStack
 * Frees all memory allocated to the stack (nodes and struct).
 * Does not free the user data stored in the stack.
 */
void freeStack(Stack * s)
{
    if (s == NULL)
    {
        return;
    }
    Node *current = s->top;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(s);
}
