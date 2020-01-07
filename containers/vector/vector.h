#pragma once
#include <stdbool.h>

static const int INITIAL_CAPACITY = 16;

struct vector {
	void** data;
	int size;
	int capacity;
};

typedef struct vector vector;

struct vector* vector_new(void);
void vector_init(vector* v);
void vector_free(vector* v);
int vector_size(const vector* v);
int vector_capacity(const vector* v);
bool vector_empty(const vector* v);
void* vector_get(const vector* v, int index);
void vector_set(vector* v, int index, void* e);
bool vector_contains(const vector* v, void* e);
int vector_index(const vector* v, void* e);
void vector_add(vector* v, void* e);
void vector_insert(vector* v, int index, void* e);
void* vector_remove(vector* v, int index);
bool vector_erase(vector* v, void* e);
void vector_clear(vector* v);
