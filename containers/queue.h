#pragma once
#include <stdbool.h>

struct queue_node {
	void* data;
	struct queue_node* next;
};
typedef struct queue_node queue_node;

queue_node* queue_node_new(void* data);

struct queue {
	struct queue_node* front;
	struct queue_node* back;
	int size;
};

typedef struct queue queue;

queue* queue_new(void);
void queue_init(queue* q);
void queue_free(queue* q);
int queue_size(queue* q);
bool queue_empty(queue* q);
void queue_enqueue(queue* q, void* e);
void* queue_peek(queue* q);
void* queue_dequeue(queue* q);
bool queue_contains(queue* q, void* e);
void queue_clear(queue* q);
