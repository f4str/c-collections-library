#pragma once

int linear_search(void* base, size_t length, size_t size, void* x, int (*compar)(const void*, const void*));
int binary_search(void* base, size_t length, size_t size, void* x, int (*compar)(const void*, const void*));
int jump_search(void* base, size_t length, size_t size, void* x, int (*compar)(const void*, const void*));
int exponential_search(void* base, size_t length, size_t size, void* x, int (*compar)(const void*, const void*));
int interpolation_search(void* base, size_t length, size_t size, void* x, int (*compar)(const void*, const void*));
int randomized_search(void* base, size_t length, size_t size, void* x, int (*compar)(const void*, const void*));
