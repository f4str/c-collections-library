#pragma once;
#include <stdbool.h>

struct deque_node {
	void* data;
	struct deque_node* next;
	struct deque_node* previous;
};

typedef struct deque_node deque_node;

deque_node* deque_node_new(void* data);

struct deque {
	struct deque_node* front;
	struct deque_node* back;
	int size;
};

typedef struct deque deque;

deque* deque_new(void);
void deque_init(deque* d);
void deque_free(deque* d);
int deque_size(const deque* d);
bool deque_empty(const deque* d);
void* deque_getfirst(const deque* d);
void* deque_getlast(const deque* d);
void* deque_setfirst(deque* d, void* e);
void* deque_setlast(deque* d, void* e);
void deque_addfirst(deque* d, void* e);
void deque_addlast(deque* d, void* e);
void* deque_removefirst(deque* d);
void* deque_removelast(deque* d);
bool deque_contains(const deque* d, void* e);
void deque_clear(deque* d);
