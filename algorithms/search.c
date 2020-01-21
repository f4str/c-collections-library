#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search.h"

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

int linear_search(void* base, size_t length, size_t size, void* x, int (*compar)(const void*, const void*)) {
	char* elem = (char*)base;
	size_t i;
	
	if (compar == NULL) {
		compar = comparator;
	}
	
	for (i = 0; i < length; ++i, elem += size) {
		if (compar(element(elem, size), x) == 0) {
			return i;
		}
	}
	return -1;
}

int binary_search(void* base, size_t length, size_t size, void* x, int (*compar)(const void*, const void*)) {
	int low = 0;
	int high = length - 1;
	int mid;
	char* addr = (char*)base;
	void* elem;
	
	if (compar == NULL) {
		compar = comparator;
	}
	
	while (low <= high) {
		mid = (high - 1) / 2 + 1;
		elem = element(addr + size * mid, size);
		if (compar(elem, x) < 0) {
			low = mid + 1;
		}
		else if (compar(elem, x) > 0) {
			high = mid - 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}

int jump_search(void* base, size_t length, size_t size, void* x, int (*compar)(const void*, const void*)) {
	int step = sqrt(length);
	int prev = 0;
	char* addr = (char*)base;
	void* elem;
	
	if (compar == NULL) {
		compar = comparator;
	}
	
	elem = element(addr + size * (step - 1), size);
	while (compar(elem, x) < 0) {
		prev = step;
		step += sqrt(length);
		if (prev >= length)	{
			return -1;
		}
		elem = element(addr + size * (step - 1), size);
	}
	
	elem = element(addr + size * prev, size);
	while (compar(elem, x) < 0) {
		++prev;
		if (prev == step) {
			return -1;
		}
		elem = element(addr + size * prev, size);
	}
	
	elem = element(addr + size * prev, size);
	if (compar(elem, x) == 0) {
		return prev;
	}
	return -1;
}

int exponential_search(void* base, size_t length, size_t size, void* x, int (*compar)(const void*, const void*)) {
	size_t i = 1;
	char* addr = (char*)base;
	void* elem;
	
	if (compar == NULL) {
		compar = comparator;
	}
	
	elem = element(addr, size);
	if (compar(elem, x) == 0) {
		return 0;
	}
	
	elem = element(addr + size * i, size);
	while (i < length && compar(elem, x) <= 0) {
		i *= 2;
		elem = element(addr + size * i, size);
	}
	
	i = i < length ? i : length - 1;
	return binary_search(addr + size * (i / 2), i, size, x, compar);
}

int interpolation_search(void* base, size_t length, size_t size, void* x, int (*compar)(const void*, const void*)) {
	int low = 0;
	int high = length - 1;
	int mid;
	char* addr = (char*)base;
	void* elem_low;
	void* elem_high;
	void* elem_mid;
	
	if (compar == NULL) {
		compar = comparator;
	}
	
	elem_low = element(addr + size * low, size);
	elem_high = element(addr + size * high, size);
	while (compar(elem_low, elem_high) != 0 && compar(elem_low, x) <= 0 && compar(elem_high, x) <= 0) {
		mid = low + ((x - elem_low) * (high - low) / (elem_high - elem_low));
		elem_mid = element(addr + size * mid, size);
		if (compar(elem_mid, x) < 0) {
			low = mid + 1;
		}
		else if (compar(elem_mid, x) > 0) {
			high = mid - 1;
		}
		else {
			return mid;
		}
		elem_low = element(addr + size * low, size);
		elem_high = element(addr + size * high, size);
	}
	
	if (compar(elem_low, x) == 0) {
		return low;
	}
	return -1;
}

int randomized_search(void* base, size_t length, size_t size, void* x, int (*compar)(const void*, const void*)) {
	char* elem = (char*)base;
	char* addr = (char*)base;
	char* rand_elem;
	size_t i, j;
	srand(time(0));
	
	if (compar == NULL) {
		compar = comparator;
	}
	
	for (i = 0; i < length; ++i, elem += size) {
		if (compar(element(elem, size), x) == 0) {
			return i;
		}
		j = rand() % (length - i) + i;
		rand_elem = element(addr + size * j, size);
		if (compar(rand_elem, x) == 0) {
			return j;
		}
	}
	return -1;
}
