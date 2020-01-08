#pragma once
#include <stdbool.h>

struct stack_node {
	void* data;
	struct stack_node* next;
};

typedef struct stack_node stack_node;

stack_node* stack_node_new(void* data);

struct stack {
	struct stack_node* top;
	int size;
};

typedef struct stack stack;

stack* stack_new(void);
void stack_init(stack* s);
void stack_free(stack* s);
int stack_size(stack* s);
bool stack_empty(stack* s);
void stack_push(stack* s, void* e);
void* stack_peek(stack* s);
void* stack_pop(stack* s);
bool stack_contains(stack* s, void* e);
void stack_clear(stack* s);
