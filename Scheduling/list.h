/*
Kaitlyn Vetica
2365588
vetica@chapman.edu
CPSC-380-02
Assignment 4
*/

/**
 * list data structure containing the tasks in the system
 */

#include "task.h"

struct node {
    Task *task;
    struct node *next;
};

// insert and delete operations.
void insert(struct node **head, Task *newTask);
void append(struct node **tail, struct node **head, Task *newTask);
void delete(struct node **head, Task *task);
void traverse(struct node *head);
