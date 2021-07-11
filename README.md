# C Collections Library

Library of generic data structures for C based on the C++ STL containers library. Each container is standalone and has no other dependencies on any other container.

## User Guide

All implementations follow a similar style and structure in terms of creation, deletion, and operation. All containers store data as a `void*` type which is capable of storing any primitive or pointer type. When adding or setting values in the container, any type can technically be used (similar to Python collections), but it recommended to stay consistent to one data type. When getting values from the container, the `void*` will be returned which can be casted or stored in any form desired.

### Creation

All containers can be created by using the corresponding `new` function. This dynamically creates and initializes the container on the heap and returns the pointer. Some containers take specific parameters (such as priority queues requiring comparators).

```c
vector* letters = vector_new();  // returns pointer
stack* cards = stack_new();

priorityqueue* points = priorityqueue_new(compar);  // takes comparator
```

If the container is created on stack, it can be initialized using the corresponding `init` function by passing the pointer.

```c
vector numbers;
vector_init(&numbers);  // accepts pointer
```

### Deletion

All containers have a corresponding `free` function used to free all elements and the container itself.

```c
vector_free(letters);  // frees all elements and struct itself
stack_free(cards);
priorityqueue_free(points);

vector_free(&numbers);  // accepts pointer
```

Instead of completely deleting the container, it can be cleared to delete all elements while preserving the struct using the corresponding `clear` function.

```c
vector_clear(letters);  // only frees elements
```

### Adding and Removing Elements

Each container has its own way to add and remove elements which is purely data structure dependent. Common conventions are followed from the C++ STL library (such as `add`, `insert`, `remove`, `erase` for vectors or `push`, `pop` for stacks). Refer to the the container's implementation for the specific functions available.

```c
vector_add(letters, 'w');  // appends 'w' to end
vector_insert(letters, 0, 'g');  // inserts 'g' to beginning
char elem = vector_delete(letters, 2);  // removes and returns element at index 2
bool success = vector_erase(letters, 'g');  // removes first instance of 'g'

char* card = "ace";
stack_push(cards, card);
char* top = stack_pop(cards);

int point[] = {1, 2};
priorityqueue_insert(points, point);
int* min = priorityqueue_extract_min(points)
```

### Getting and Setting Elements

Similar to adding and removing elements, each container has its own way of getting elements which is purely data structure dependent. Common conventions are followed from the C++ STL library (such as `get` for vectors and linked lists or `peek` for stacks and queues). Refer to the container's implementation for the specific functions available.

```c
char elem = vector_get(letters, 2);  // gets the element at index 2
vector_set(letters, 1, 'b');  // sets element at index 1

char* top = stack_peek(cards);  // peeks top of stack
/* no setters for stacks */

int* min = priorityqueue_find_min(points);  // gets top element of binary heap
priorityqueue_change_key(points, 3, min);  // changes value at index 3
/* decrease_key and increase_key also exist */
```

### Checking for Existence

All containers have corresponding `contains` function to check if a specific element exists. Note that the time to check for existence varies per data structure.

```c
bool a_exists = vector_contains(letters, 'a');  // returns bool
```

Some containers have a corresponding `index` function to get the index at which an element exists (such as vectors and linked lists). If the element does not exist, -1 is returned.

```c
int index = vector_index(letters, 'a');  // return int
```

### Properties

All containers have a corresponding `size` function to check the total number of elements are stored.

```c
int count = vector_size(letters);  // returns int
```

Alternatively, a container can be checked if it is empty using the corresponding `empty` function.

```c
bool is_empty = vector_empty(letters);  // return bool
```

Some array-based containers (such as vectors and priority queues) have a corresponding `capacity` function to get the current capacity. When the containers fills up, this capacity is doubled.

```c
int current_capacity = vector_capacity(letters);  // returns int
```

## Containers Available

Various generic data structures have been implemented. The header files are found in the `include/` folder while the full implementation of all functions are found in the `src/` folder. All implementations are completely standalone so there are no other dependencies and the class can be used immediately out of the box.

### Linear Collections

* Vector (`vector.h`)
* Singly Linked list (`forwardlist.h`)
* Doubly Linked List (`linkedlist.h`)
* Stack (`stack.h`)
* Queue (`queue.h`)
* Deque (`deque.h`)
* Priority Queue (`priorityqueue.h`)

### Associative Collections

* Hash Set (`hashset.h`) [in-progress]
* Hash Map (`hashmap.h`) [in-progress]
* Ordered Set (`orderedset.h`) [in-progress]
* Ordered Map (`orderedmap.h`) [in-progress]
