#include <stdio.h>
#include <stdlib.h>
#include "schedule_fcfs.h"

void add(char *name, int burst) {
    Task *task = (Task*) malloc(sizeof(Task));
    task->name = name;
    task->burst = burst;

    Node *node = (Node*) malloc(sizeof(Node));
    node->task = task;
    node->next = NULL;

    if (tail == NULL) {
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

void schedule() {
    if (head == NULL) {
        printf("No tasks to run.\n");
        return;
    }

    printf("Running task %s for %d units of time.\n", head->task->name, head->task->burst);

    Node *temp = head;
    head = head->next;
    free(temp->task);
    free(temp);
}