#pragma once
#include <stdbool.h>

static const int INITIAL_CAPACITY = 16;

struct priorityqueue {
	void** data;
	int size;
	int capacity;
	int (*comparator)(const void*, const void*);
};

typedef struct priorityqueue priorityqueue;

priorityqueue* priorityqueue_new(int (*compar)(const void*, const void*));
void priorityqueue_init(priorityqueue* p, int (*compar)(const void*, const void*));
void priorityqueue_free(priorityqueue* p);
int priorityqueue_size(const priorityqueue* p);
int priorityqueue_capacity(const priorityqueue* p);
bool priorityqueue_empty(const priorityqueue* p);
bool priorityqueue_contains(const priorityqueue* p, void* e);
void priorityqueue_heapify(priorityqueue* p, int index);
void priorityqueue_insert(priorityqueue* p, void* e);
void* priorityqueue_delete(priorityqueue* p, int index);
void* priorityqueue_find_min(const priorityqueue* p);
void* priorityqueue_extract_min(priorityqueue* p);
void priorityqueue_decrease_key(priorityqueue* p, int index, void* e);
void priorityqueue_increase_key(priorityqueue* p, int index, void* e);
void priorityqueue_change_key(priorityqueue* p, int index, void* e);
void priorityqueue_clear(priorityqueue* p);
