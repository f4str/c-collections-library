# C Collections Library

Library of generic data structures for C based on the C++ STL containers library. All data structure collections are standalone and can be used out of the box.

## User Guide

All implementations follow a similar style and structure in terms of creation, deletion, and operation.

### Creation

All containers are created by using the corresponding `new` function. This dynamically creates and initializes the container on the heap:

```c
vector* numbers = vector_new()
```

If the container is created on stack, it can be initialized using the corresponding `init` function:

```c
vector numbers;
vector_init(&numbers);
```
