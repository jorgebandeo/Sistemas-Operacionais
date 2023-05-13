#ifndef FCFS_H_INCLUDED
#define FCFS_H_INCLUDED

static Node *head = NULL;
static Node *tail = NULL;

typedef struct task {
    char *name;
    int burst;
} Task;

typedef struct node {
    Task *task;
    struct node *next;
} Node;

void add(char *name, int burst);
void schedule();

#endif // FCFS_H_INCLUDED