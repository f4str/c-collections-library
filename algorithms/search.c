#include <math.h>
#include <stdlib.h>
#include "search.h"

int linear_search(void** array, int length, void* x) {
	int i;
	for (i = 0; i < length; ++i) {
		if (array[i] == x) {
			return i;
		}
	}
	return -1;
}

int binary_search(void** array, int length, void* x) {
	int low = 0;
	int high = length - 1;
	int mid;
	
	while (low <= high) {
		mid = (high - 1) / 2 + 1;
		if (array[mid] < x) {
			low = mid + 1;
		}
		else if (array[mid] > x) {
			high = mid - 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}

int jump_search(void** array, int length, void* x) {
	int step = sqrt(length);
	int prev = 0;
	
	while (array[step - 1] < x) {
		prev = step;
		step += sqrt(length);
		step = step < length ? step : length - 1;
		if (prev >= length)	{
			return -1;
		}
	}
	while (array[prev] < x) {
		++prev;
		if (prev == step) {
			return -1;
		}
	}
	if (array[prev] == x) {
		return prev;
	}
	return -1;
}

int exponential_search(void** array, int length, void* x) {
	int i = 1;
	
	if (*array == x) {
		return 0;
	}
	while (i < length && array[i] <= x) {
		i *= 2;
	}
	i = i < length ? i : length - 1;
	return binary_search(array + i / 2, i, x);
}

int interpolation_search(void** array, int length, void* x) {
	int low = 0;
	int high = length - 1;
	int position;
	
	while (low <= high && x >= array[low] && x <= array[high]) {
		if (low == high && array[low] == x) {
			return low;
		}
		else {
			return -1;
		}
		
		position = low + (((double)(high - low) / (array[high] - array[low])) * (x - array[low]));
		if (array[position] < x) {
			low = position + 1;
		}
		else if (array[position] > x) {
			high = position - 1;
		}
		else {
			return position;
		}
	}
	return -1;
}

int randomized_search(void** array, int length, void* x) {
	int i, j;
	srand(time(0));
	
	for (i = 0; i < length; ++i) {
		if (array[i] == x) {
			return i;
		}
		
		j = rand() % (length - i) + i;
		if (array[j] == x) {
			return j;
		}
	}
	return -1;
}
