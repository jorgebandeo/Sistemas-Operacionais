#include <stdlib.h>
#include "CPU.h"
#include "list.h"
#include "task.h"

int tid_counter_p = 0;
struct node *TASK_LIST_p = NULL;

void add_rp(char *name, int priority, int burst) {
    Task *new_task = malloc(sizeof(Task));
    new_task->name = name;
    new_task->tid = ++tid_counter_p;
    new_task->priority = priority;
    new_task->burst = burst;
    insert_task(&TASK_LIST_p, new_task);
}
void swap(struct node *a, struct node *b) {
    Task *temp = a->task;
    a->task = b->task;
    b->task = temp;
}


void sort_by_priority() {
    int swapped;
    struct node *ptr1;
    struct node *lptr = NULL;

    if (TASK_LIST_p == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = TASK_LIST_p;

        while (ptr1->next != lptr) {
            if (ptr1->task->priority > ptr1->next->task->priority) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void schedule_rr_p() {
    struct node *temp;
    while (TASK_LIST_p != NULL) {
        temp = TASK_LIST_p;
        while (temp != NULL) {
            if (temp->task->burst > QUANTUM) {
                run(temp->task, QUANTUM);
                temp->task->burst -= QUANTUM;
            } else {
                run(temp->task, temp->task->burst);
                delete_task(&TASK_LIST_p, temp->task);
            }
            temp = temp->next;
        }
        // Adicionando a funcionalidade de prioridade
        sort_by_priority();
    }
}
