#include <stdio.h>
#include <stdlib.h>
#include "priorityqueue.h"

static int comparator(const void* x, const void* y) {
	return (int)x - (int)y;
}

priorityqueue* priorityqueue_new(int (*compar)(const void*, const void*)) {
	priorityqueue* p = malloc(sizeof(priorityqueue));
	p->size = 0;
	p->capacity = INITIAL_CAPACITY;
	p->data = malloc(INITIAL_CAPACITY * sizeof(void*));
	p->comparator = compar == NULL ? comparator : compar;
	return p;
}

void priorityqueue_init(priorityqueue* p, int (*compar)(const void*, const void*)) {
	p->size = 0;
	p->capacity = INITIAL_CAPACITY;
	p->data = malloc(INITIAL_CAPACITY * sizeof(void*));
	p->comparator = compar == NULL ? comparator : compar;
}

void priorityqueue_free(priorityqueue* p) {
	free(p->data);
	free(p);
}

int priorityqueue_size(const priorityqueue* p) {
	return p->size;
}

bool priorityqueue_empty(const priorityqueue* p) {
	return p->size == 0;
}

bool priorityqueue_contains(const priorityqueue* p, void* e) {
	int i;
	for (i = 0; i < p->size; ++i) {
		if (p->data[i] == e) {
			return true;
		}
	}
	return false;
}

void priorityqueue_heapify(priorityqueue* p, int index) {
	int smallest = index;
	int l = 2 * index + 1;
	int r = 2 * index + 2;
	void* temp;
	
	if (l < p->size && p->comparator(p->data[l], p->data[smallest]) < 0) {
		smallest = l;
	}
	if (r < p->size && p->comparator(p->data[r], p->data[smallest]) < 0) {
		smallest = r;
	}
	if (smallest != index) {
		temp = p->data[index];
		p->data[index] = p->data[smallest];
		p->data[smallest] = temp;
		priorityqueue_heapify(p, smallest);
	}
}

void priorityqueue_insert(priorityqueue* p, void* e) {
	if (p->size == p->capacity) {
		p->data = realloc(p->data, p->capacity * 2);
		p->capacity *= 2;
	}
	
	int i = p->data[p->size];
	int parent = (i - 1) / 2;
	void* temp;
	
	while (i > 0 && p->comparator(p->data[parent], p->data[i]) > 0) {
		temp = p->data[i];
		p->data[i] = p->data[parent];
		p->data[parent] = temp;
		i = parent;
		parent = (i - 1) / 2;
	}
	++p->size;
}

void* priorityqueue_delete(priorityqueue* p, int index) {
	void* value = p->data[index];
	--p->size;
	
	p->data[index] = p->data[p->size];
	priorityqueue_heapify(p, index);
	return value;
}

void* priorityqueue_find_min(const priorityqueue* p) {
	return p->data[0];
}

void* priorityqueue_extract_min(priorityqueue* p) {
	void* root = p->data[0];
	--p->size;
	
	if (p->size == 1) {
		return p->data[0];
	}
	else {
		p->data[0] = p->data[p->size];
		priorityqueue_heapify(p, 0);
	}
	
	return root;
}

void priorityqueue_decrease_key(priorityqueue* p, int index, void* e) {
	void* value = p->data[index];
	void* temp;
	int parent = (index - 1) / 2;
	
	p->data[index] = e;
	while (index > 0 && p->comparator(p->data[parent], p->data[index]) > 0) {
		temp = p->data[index];
		p->data[index] = p->data[parent];
		p->data[parent] = temp;
		index = parent;
		parent = (index - 1) / 2;
	}
}

void priorityqueue_increase_key(priorityqueue* p, int index, void* e) {
	void* value = p->data[index];
	p->data[index] = e;
	priorityqueue_heapify(p, index);
	return value;
}

void priorityqueue_clear(priorityqueue* p) {
	free(p->data);
	p->size = 0;
	p->capacity = INITIAL_CAPACITY;
	p->data = malloc(INITIAL_CAPACITY * sizeof(void*));
}
