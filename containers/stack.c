#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack_node* stack_node_new(void* data) {
	stack_node* node = malloc(sizeof(stack_node));
	node->data = data;
	node->next = NULL;
	return node;
}

stack* stack_new(void) {
	stack* s = malloc(sizeof(stack));
	s->top = NULL;
	s->size = 0;
	return s;
}

void stack_init(stack* s) {
	s->top = NULL;
	s->size = 0;
}

void stack_free(stack* s) {
	if (s->size == 0) {
		free(s);
		return;
	}
	
	stack_node* current = s->top;
	stack_node* temp = current->next;
	while (temp != NULL) {
		free(current);
		current = temp;
		temp = temp->next;
	}
	free(current);
	free(s);
}

int stack_size(stack* s) {
	return s->size;
}

bool stack_empty(stack* s) {
	return s->size == 0;
}

void stack_push(stack* s, void* e) {
	stack_node* temp = stack_node_new(e);
	if (s->size == 0) {
		s->top = temp;
	}
	else {
		temp->next = s->top;
		s->top = temp;
	}
	++s->size;
}

void* stack_peek(stack* s) {
	if (s->top == NULL) {
		return NULL;
	}
	return s->top->data;
}

void* stack_pop(stack* s) {
	if (s->size == 0) {
		return NULL;
	}
	stack_node* node = s->top;
	void* data = node->data;
	s->top = node->next;
	free(node);
	return data;
}

bool stack_contains(stack* s, void* e) {
	stack_node* current = s->top;
	while (current != NULL) {
		if (current->data == e) {
			return 1;
		}
		current = current->next;
	}
	return 0;
}

void stack_clear(stack* s) {
	if (s->size == 0) {
		return;
	}
	
	stack_node* current = s->top;
	stack_node* temp = current->next;
	while (temp != NULL) {
		free(current);
		current = temp;
		temp = temp->next;
	}
	free(current);
	
	s->top = NULL;
	s->size = 0;
}
