#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

vector* vector_new() {
	vector* v = malloc(sizeof(vector));
	v->size = 0;
	v->capacity = INITIAL_CAPACITY;
	v->data = malloc(INITIAL_CAPACITY * sizeof(void*));
	return v;
}

void vector_init(vector* v) {
	v->size = 0;
	v->capacity = INITIAL_CAPACITY;
	v->data = malloc(INITIAL_CAPACITY * sizeof(void*));
}

void vector_free(vector* v) {
	free(v->data);
	free(v);
}

int vector_size(const vector* v) {
	return v->size;
}

int vector_capacity(const vector* v) {
	return v->capacity;
}

bool vector_empty(const vector* v) {
	return v->size == 0;
}

void* vector_get(const vector* v, int index) {
	return v->data[index];
}

void vector_set(vector* v, int index, void* e) {
	v->data[index] = e;
}

bool vector_contains(const vector* v, void* e) {
	int i;
	for (i = 0; i < v->size; ++i) {
		if (v->data[i] == e) {
			return true;
		}
	}
	return false;
}

int vector_index(const vector* v, void* e) {
	int i;
	for (i = 0; i < v->size; ++i) {
		if (v->data[i] == e) {
			return i;
		}
	}
	return -1;
}

void vector_add(vector* v, void* e) {
	if (v->size == v->capacity) {
		v->data = realloc(v->data, v->capacity * 2);
		v->capacity *= 2;
	}
	
	v->data[v->size] = e;
	++v->size;
}

void vector_insert(vector* v, int index, void* e) {
	if (v->size == v->capacity) {
		v->data = realloc(v->data, v->capacity * 2);
		v->capacity *= 2;
	}
	
	++v->size;
	
	int i;
	for (i = v->size; i >= index; --i) {
		v->data[i] = v->data[i - 1];
	}
	v->data[index] = e;
}

void* vector_remove(vector* v, int index) {
	void* temp = v->data[index];
	--v->size;
	
	int i;
	for (i = index; i < v->size; ++i) {
		v->data[i] = v->data[i + 1];
	}
	return temp;
}

bool vector_erase(vector* v, void* e) {
	int i = vector_index(v, e);
	if (i >= 0) {
		vector_remove(v, i);
		return true;
	}
	return false;
}

void vector_clear(vector* v) {
	free(v->data);
	v->size = 0;
	v->capacity = INITIAL_CAPACITY;
	v->data = malloc(INITIAL_CAPACITY * sizeof(void*));
}
