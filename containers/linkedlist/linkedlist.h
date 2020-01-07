#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>

struct linkedlist_node {
	void* data;
	struct linkedlist_node* next;
	struct linkedlist_node* previous;
};

typedef struct linkedlist_node linkedlist_node;

linkedlist_node* linkedlist_node_new(void* data);

struct linkedlist {
	struct linkedlist_node* head;
	struct linkedlist_node* tail;
	int size;
};

typedef struct linkedlist linkedlist;

linkedlist* linkedlist_new(void);
void linkedlist_init(linkedlist* list);
void linkedlist_free(linkedlist* list);
int linkedlist_size(const linkedlist* list);
bool linkedlist_empty(const linkedlist* list);
void* linkedlist_getfirst(const linkedlist* list);
void* linkedlist_getlast(const linkedlist* list);
void* linkedlist_get(const linkedlist* list, int index);
void* linkedlist_setfirst(linkedlist* list, void* e);
void* linkedlist_setlast(linkedlist* list, void* e);
void* linkedlist_set(linkedlist* list, int index, void* e);
void linkedlist_addfirst(linkedlist* list, void* e);
void linkedlist_addlast(linkedlist* list, void* e);
void linkedlist_add(linkedlist* list, int index, void* e);
void* linkedlist_removefirst(linkedlist* list);
void* linkedlist_removelast(linkedlist* list);
void* linkedlist_remove(linkedlist* list, int index);
bool linkedlist_contains(const linkedlist* list, void* e);
int linkedlist_index(const linkedlist* list, void* e);
int linkedlist_erase(linkedlist* list, void* e);
void linkedlist_clear(linkedlist* list);

#endif
