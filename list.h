/**
 * list data structure containing the tasks in the system
 */
#ifndef LIST_H
#define LIST_H
#include "task.h"

struct node {
    Task *task;
    struct node *next;
};
struct node *hader;
// insert and delete operations.
void insert_task(struct node **head, Task *task);
void delete_task(struct node **head, Task *task);
void traverse_task(struct node *head);
#endif
