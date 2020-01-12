#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sort.h"

static int comparator(const void* x, const void* y) {
	return (int)x - (int)y;
}

static void* element(void* addr, size_t size) {
	char* a = (char*)addr + size;
	void* buffer = 0;
	char* elem = (char*)&buffer + size;
	size_t i;
	
	for (i = size - 1; i >= 0; --i, --a, --elem) {
		*elem = *a;
	}
	return buffer;
}

static void swap(void* x, void* y, size_t size) {
	char* a = (char*)x;
	char* b = (char*)y;
	char temp;
	size_t i;
	
	for (i = 0; i < size; ++i, ++a, ++b) {
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

void selection_sort(void* base, int length, int size, int (*compar)(const void*, const void*)) {
	
}
