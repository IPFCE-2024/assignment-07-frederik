/*
 * Exercise 2: Stack Implementation using Linked List
 * Assignment 7 - IPFCE 2025
 * 
 * Implement all the stack functions declared in include/stack.h
 * The stack should be implemented using a linked list structure.
 * 
 * Functions to implement:
 * - initialize: Create an empty stack
 * - push: Insert an item at the top of the stack
 * - pop: Remove and return the top item
 * - full: Check if stack is full (always false for linked list)
 * - empty: Check if stack is empty
 * - print: Print all items in the stack
 */

#include "./include/stack.h"

/* Create an empty stack */
void initialize(stack *s)
{
    s->head = NULL;
}

/* Insert item x at the top of stack s */
void push(int x, stack *s)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: memory allocation failed in push()\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = x;
    new_node->next = s->head; // new node points to old head
    s->head = new_node;       // new node becomes new head
}

/* Return (and remove) the top item of stack s */
int pop(stack *s)
{
    if (empty(s))
    {
        fprintf(stderr, "Error: attempted to pop from empty stack\n");
        exit(EXIT_FAILURE);
    }

    node *temp = s->head;
    int value = temp->data;
    s->head = temp->next;
    free(temp);
    return value;
}

/* A linked-list-based stack is never full */
bool full(stack *s)
{
    return false;
}

/* Check whether the stack is empty */
bool empty(stack *s)
{
    return (s->head == NULL);
}

/* Print all items in the stack from top to bottom */
void print(stack *s)
{
    node *current = s->head;
    printf("Stack contents (top → bottom): ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
