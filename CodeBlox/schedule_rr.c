#include <stdlib.h>
#include "CPU.h"
#include "list.h"
#include "task.h"

int tid_counter = 0;
struct node *task_list = NULL;

void add(char *name, int priority, int burst) {
    Task *new_task = malloc(sizeof(Task));
    new_task->name = name;
    new_task->tid = ++tid_counter;
    new_task->priority = priority;
    new_task->burst = burst;
    insert_task(&task_list, new_task);
}

void schedule_rr() {
    struct node *temp;
    while (task_list != NULL) {
        temp = task_list;
        while (temp != NULL) {
            if (temp->task->burst > QUANTUM) {
                run(temp->task, QUANTUM);
                temp->task->burst -= QUANTUM;
            } else {
                run(temp->task, temp->task->burst);
                delete_task(&task_list, temp->task);
            }
            temp = temp->next;
        }
    }
}
