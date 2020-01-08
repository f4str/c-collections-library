#include <stdio.h>
#include <stdlib.h>
#include "forwardlist.h"

forwardlist_node* forwardlist_node_new(void* data) {
	forwardlist_node* node = malloc(sizeof(forwardlist_node));
	node->data = data;
	node->next = NULL;
	return node;
}

forwardlist* forwardlist_new() {
	forwardlist* list = malloc(sizeof(forwardlist));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return list;
}

void forwardlist_init(forwardlist* list) {
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

void forwardlist_free(forwardlist* list) {
	if (list->size == 0) {
		free(list);
		return;
	}
	
	forwardlist_node* current = list->head;
	forwardlist_node* temp = current->next;
	while (temp != NULL) {
		free(current);
		current = temp;
		temp = temp->next;
	}
	free(current);
	free(list);
}

int forwardlist_size(const forwardlist* list) {
	return list->size;
}

bool forwardlist_empty(const forwardlist* list) {
	return list->size == 0;
}

void* forwardlist_getfirst(const forwardlist* list) {
	if (list->head == NULL) {
		return NULL;
	}
	return list->head->data;
}

void* forwardlist_getlast(const forwardlist* list) {
	if (list->tail == NULL) {
		return NULL;
	}
	return list->head->data;
}

void* forwardlist_get(const forwardlist* list, int index) {
	if (index == 0) {
		return forwardlist_getfirst(list);
	}
	else if (index == list->size - 1) {
		return forwardlist_getlast(list);
	}
	
	forwardlist_node* current = list->head;
	int i;
	for (i = 0; i < index; ++i) {
		current = current->next;
	}
	return current->data;
}

void* forwardlist_setfirst(forwardlist* list, void* e) {
	void* data = forwardlist_getfirst(list);
	if (list->size == 0) {
		forwardlist_addfirst(list, e);
	}
	else {
		list->head->data = e;
	}
	return data;
}

void* forwardlist_setlast(forwardlist* list, void* e) {
	void* data = forwardlist_getlast(list);
	if (list->size == 0) {
		forwardlist_addlast(list, e);
	}
	else {
		list->tail->data = e;
	}
	return data;
}

void* forwardlist_set(forwardlist* list, int index, void* e) {
	if (index == 0) {
		return forwardlist_setfirst(list, e);
	}
	else if (index == list->size - 1) {
		return forwardlist_setlast(list, e);
	}
	
	forwardlist_node* current = list->head;
	int i;
	for (i = 0; i < index; ++i) {
		current = current->next;
	}
	void* data = current->data;
	current->data = e;
	return data;
}

void forwardlist_addfirst(forwardlist* list, void* e) {
	forwardlist_node* temp = forwardlist_node_new(e);
	if (list->size == 0) {
		list->head = temp;
		list->tail = temp;
	}
	else {
		temp->next = list->head;
		list->head = temp;
	}
	++list->size;
}

void forwardlist_addlast(forwardlist* list, void* e) {
	forwardlist_node* temp = forwardlist_node_new(e);
	if (list->size == 0) {
		list->tail = temp;
		list->head = temp;
	}
	else {
		list->tail->next = temp;
		list->tail = temp;
	}
	++list->size;
}

void forwardlist_add(forwardlist* list, int index, void* e) {
	if (index == 0) {
		forwardlist_addfirst(list, e);
		return;
	}
	else if (index == list->size - 1) {
		forwardlist_addlast(list, e);
		return;
	}
	
	forwardlist_node* previous = list->head;
	forwardlist_node* current = previous->next;
	int i;
	for (i = 0; i < index; ++i) {
		previous = current;
		current = current->next;
	}
	forwardlist_node* temp = forwardlist_node_new(e);
	previous->next = temp;
	temp->next = current;
	++list->size;
}

void* forwardlist_removefirst(forwardlist* list) {
	void* data = forwardlist_getfirst(list);
	forwardlist_node* current;
	if (list->head == list->tail) {
		forwardlist_clear(list);
	}
	else {
		current = list->head->next;
		free(list->head);
		list->head = current;
		--list->size;
	}
	return data;
}

void* forwardlist_removelast(forwardlist* list) {
	void* data = forwardlist_getlast(list);
	forwardlist_node* current;
	if (list->head == list->tail) {
		forwardlist_clear(list);
	}
	else {
		current = list->head;
		while (current->next != list->tail) {
			current = current->next;
		}
		free(list->tail);
		current->next = NULL;
		list->tail = current;
		--list->size;
	}
	return data;
}

void* forwardlist_remove(forwardlist* list, int index) {
	if (index == 0) {
		return forwardlist_removefirst(list);
	}
	else if (index == list->size - 1) {
		return forwardlist_removelast(list);
	}
	
	forwardlist_node* previous = list->head;
	forwardlist_node* current = previous->next;
	int i;
	for (i = 0; i < index; ++i) {
		previous = current;
		current = current->next;
	}
	previous->next = current->next;
	void* data = current->data;
	free(current);
	--list->size;
	return data;
}

bool forwardlist_contains(const forwardlist* list, void* e) {
	forwardlist_node* current = list->head;
	while (current != NULL) {
		if (current->data == e) {
			return true;
		}
		current = current->next;
	}
	return false;
}

int forwardlist_index(const forwardlist* list, void* e) {
	forwardlist_node* current = list->head;
	int i;
	for (i = 0; current != NULL; ++i) {
		if (current->data == e) {
			return i;
		}
	}
	return -1;
}

int forwardlist_erase(forwardlist* list, void* e) {
	int index = forwardlist_index(list, e);
	if (index >= 0) {
		forwardlist_remove(list, index);
		return 1;
	}
	return 0;
}

void forwardlist_clear(forwardlist* list) {
	if (list->size == 0) {
		return;
	}
	
	forwardlist_node* current = list->head;
	forwardlist_node* temp = current->next;
	while (temp != NULL) {
		free(current);
		current = temp;
		temp = temp->next;
	}
	free(current);
	
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}
