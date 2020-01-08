#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue_node* queue_node_new(void* data) {
	queue_node* node = malloc(sizeof(queue_node));
	node->data = data;
	node->next = NULL;
	return node;
}

queue* queue_new(void) {
	queue* q = malloc(sizeof(queue));
	q->front = NULL;
	q->back = NULL;
	q->size = 0;
	return q;
}

void queue_init(queue* q) {
	q->front = NULL;
	q->back = NULL;
	q->size = 0;
}

void queue_free(queue* q) {
	if (q->size == 0) {
		free(q);
		return;
	}
	
	queue_node* current = q->front;
	queue_node* temp = current->next;
	while (temp != NULL) {
		free(current);
		current = temp;
		temp = temp->next;
	}
	free(current);
	free(q);
}

int queue_size(queue* q) {
	return q->size;
}

bool queue_empty(queue* q) {
	return q->size == 0;
}

void queue_enqueue(queue* q, void* e) {
	queue_node* temp = queue_node_new(e);
	if (q->size == 0) {
		q->back = temp;
		q->front = temp;
	}
	else {
		q->back->next = temp;
		q->back = temp;
	}
	++q->size;
}

void* queue_peek(queue* q) {
	if (q->front == NULL) {
		return NULL;
	}
	return q->front->data;
}

void* queue_dequeue(queue* q) {
	void* data = queue_peek(q);
	queue_node* current;
	if (q->front == q->back) {
		queue_clear(q);
	}
	else {
		current = q->front->next;
		free(q->front);
		q->front = current;
		--q->size;
	}
	return data;
}

bool queue_contains(queue* q, void* e) {
	queue_node* current = q->front;
	while (current != NULL) {
		if (current->data == e) {
			return 1;
		}
		current = current->next;
	}
	return 0;
}

void queue_clear(queue* q) {
	if (q->size == 0) {
		return;
	}
	
	queue_node* current = q->front;
	queue_node* temp = current->next;
	while (temp != NULL) {
		free(current);
		current = temp;
		temp = temp->next;
	}
	free(current);
	
	q->front = NULL;
	q->back = NULL;
	q->size = 0;
}
