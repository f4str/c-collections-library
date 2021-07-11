#pragma once
#include <stdbool.h>

struct forwardlist_node {
	void* data;
	struct forwardlist_node* next;
};

typedef struct forwardlist_node forwardlist_node;

forwardlist_node* forwardlist_node_new(void* data);

struct forwardlist {
	struct forwardlist_node* head;
	struct forwardlist_node* tail;
	int size;
};

typedef struct forwardlist forwardlist;

forwardlist* forwardlist_new(void);
void forwardlist_init(forwardlist* list);
void forwardlist_free(forwardlist* list);
int forwardlist_size(const forwardlist* list);
bool forwardlist_empty(const forwardlist* list);
void* forwardlist_getfirst(const forwardlist* list);
void* forwardlist_getlast(const forwardlist* list);
void* forwardlist_get(const forwardlist* list, int index);
void* forwardlist_setfirst(forwardlist* list, void* e);
void* forwardlist_setlast(forwardlist* list, void* e);
void* forwardlist_set(forwardlist* list, int index, void* e);
void forwardlist_addfirst(forwardlist* list, void* e);
void forwardlist_addlast(forwardlist* list, void* e);
void forwardlist_add(forwardlist* list, int index, void* e);
void* forwardlist_removefirst(forwardlist* list);
void* forwardlist_removelast(forwardlist* list);
void* forwardlist_remove(forwardlist* list, int index);
bool forwardlist_contains(const forwardlist* list, void* e);
int forwardlist_index(const forwardlist* list, void* e);
int forwardlist_erase(forwardlist* list, void* e);
void forwardlist_clear(forwardlist* list);
