#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

linkedlist_node* linkedlist_node_new(void* data) {
	linkedlist_node* node = malloc(sizeof(linkedlist_node));
	node->data = data;
	node->next = NULL;
	node->previous = NULL;
	return node;
}

linkedlist* linkedlist_new() {
	linkedlist* list = malloc(sizeof(linkedlist));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return list;
}

void linkedlist_init(linkedlist* list) {
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

void linkedlist_free(linkedlist* list) {
	if (list->size == 0) {
		free(list);
		return;
	}
	
	linkedlist_node* current = list->head;
	linkedlist_node* temp = current->next;
	while (temp != NULL) {
		free(current);
		current = temp;
		temp = temp->next;
	}
	free(current);
	free(list);
}

int linkedlist_size(const linkedlist* list) {
	return list->size;
}

bool linkedlist_empty(const linkedlist* list) {
	return list->size == 0;
}

void* linkedlist_getfirst(const linkedlist* list) {
	if (list->head == NULL) {
		return NULL;
	}
	return list->head->data;
}

void* linkedlist_getlast(const linkedlist* list) {
	if (list->tail == NULL) {
		return NULL;
	}
	return list->head->data;
}

void* linkedlist_get(const linkedlist* list, int index) {
	if (index == 0) {
		return linkedlist_getfirst(list);
	}
	else if (index == list->size - 1) {
		return linkedlist_getlast(list);
	}
	
	linkedlist_node* current = list->head;
	int i;
	for (i = 0; i < index; ++i) {
		current = current->next;
	}
	return current->data;
}

void* linkedlist_setfirst(linkedlist* list, void* e) {
	void* data = linkedlist_getfirst(list);
	if (list->size == 0) {
		linkedlist_addfirst(list, e);
	}
	else {
		list->head->data = e;
	}
	return data;
}

void* linkedlist_setlast(linkedlist* list, void* e) {
	void* data = linkedlist_getlast(list);
	if (list->size == 0) {
		linkedlist_addlast(list, e);
	}
	else {
		list->tail->data = e;
	}
	return data;
}

void* linkedlist_set(linkedlist* list, int index, void* e) {
	if (index == 0) {
		return linkedlist_setfirst(list, e);
	}
	else if (index == list->size - 1) {
		return linkedlist_setlast(list, e);
	}
	
	linkedlist_node* current = list->head;
	int i;
	for (i = 0; i < index; ++i) {
		current = current->next;
	}
	void* data = current->data;
	current->data = e;
	return data;
}

void linkedlist_addfirst(linkedlist* list, void* e) {
	linkedlist_node* temp = linkedlist_node_new(e);
	if (list->size == 0) {
		list->head = temp;
		list->tail = temp;
	}
	else {
		temp->next = list->head;
		temp->previous = NULL;
		list->head = temp;
	}
	++list->size;
}

void linkedlist_addlast(linkedlist* list, void* e) {
	linkedlist_node* temp = linkedlist_node_new(e);
	if (list->size == 0) {
		list->tail = temp;
		list->head = temp;
	}
	else {
		list->tail->next = temp;
		temp->previous = list->tail;
		list->tail = temp;
	}
	++list->size;
}

void linkedlist_add(linkedlist* list, int index, void* e) {
	if (index == 0) {
		linkedlist_addfirst(list, e);
		return;
	}
	else if (index == list->size - 1) {
		linkedlist_addlast(list, e);
		return;
	}
	
	linkedlist_node* current = list->head;
	int i;
	for (i = 0; i <= index; ++i) {
		current = current->next;
	}
	linkedlist_node* temp = linkedlist_node_new(e);
	current->previous->next = temp;
	temp->previous = current->previous;
	temp->next = current;
	++list->size;
}

void* linkedlist_removefirst(linkedlist* list) {
	void* data = linkedlist_getfirst(list);
	linkedlist_node* current;
	if (list->head == list->tail) {
		linkedlist_clear(list);
	}
	else {
		current = list->head->next;
		free(list->head);
		list->head = current;
		list->head->previous = NULL;
		--list->size;
	}
	return data;
}

void* linkedlist_removelast(linkedlist* list) {
	void* data = linkedlist_getlast(list);
	linkedlist_node* current;
	if (list->head == list->tail) {
		linkedlist_clear(list);
	}
	else {
		current = list->tail->previous;
		free(list->tail);
		list->tail = current;
		list->tail->next = NULL;
		--list->size;
	}
	return data;
}

void* linkedlist_remove(linkedlist* list, int index) {
	if (index == 0) {
		return linkedlist_removefirst(list);
	}
	else if (index == list->size - 1) {
		return linkedlist_removelast(list);
	}
	
	linkedlist_node* current = list->head;
	int i;
	for (i = 0; i < index; ++i) {
		current = current->next;
	}
	current->previous->next = current->next;
	void* data = current->data;
	free(current);
	--list->size;
	return data;
}

bool linkedlist_contains(const linkedlist* list, void* e) {
	linkedlist_node* current = list->head;
	while (current != NULL) {
		if (current->data == e) {
			return true;
		}
		current = current->next;
	}
	return false;
}

int linkedlist_index(const linkedlist* list, void* e) {
	linkedlist_node* current = list->head;
	int i;
	for (i = 0; current != NULL; ++i) {
		if (current->data == e) {
			return i;
		}
	}
	return -1;
}

int linkedlist_erase(linkedlist* list, void* e) {
	int index = linkedlist_index(list, e);
	if (index >= 0) {
		linkedlist_remove(list, index);
		return 1;
	}
	return 0;
}

void linkedlist_clear(linkedlist* list) {
	if (list->size == 0) {
		return;
	}
	
	linkedlist_node* current = list->head;
	linkedlist_node* temp = current->next;
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
