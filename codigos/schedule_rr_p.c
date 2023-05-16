#include <stdlib.h>
#include "CPU.h"
#include "list.h"
#include "task.h"

int tid_counter_p = 0;
struct node *TASK_LIST_p = NULL;

// Adiciona uma nova tarefa na lista de tarefas com prioridade
void add_rp(char *name, int priority, int burst) {
    Task *new_task = malloc(sizeof(Task));
    new_task->name = name;
    new_task->tid = ++tid_counter_p;
    new_task->priority = priority;
    new_task->burst = burst;
    insert_task(&TASK_LIST_p, new_task);
}

// Troca a posição de duas tarefas na lista
void swap(struct node *a, struct node *b) {
    struct Task *temp = a->task;
    a->task = b->task;
    b->task = temp;
}

// Ordena a lista de tarefas por prioridade
void sort_by_priority(struct node **head) {
    int swapped;
    struct node *ptr1;
    struct node *lptr = NULL;

    if (*head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = *head;

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

// Executa o escalonamento Round-Robin com prioridade
void schedule_rr_p() {
    struct node *temp;
    while (TASK_LIST_p != NULL) {
        temp = TASK_LIST_p;
        while (temp != NULL) {
            sort_by_priority(&temp);
            if (temp->task->burst > QUANTUM) {
                run(temp->task, QUANTUM);
                temp->task->burst -= QUANTUM;
            } else {
                run(temp->task, temp->task->burst);
                delete_task(&TASK_LIST_p, temp->task);
            }
            temp = temp->next;
        }
    }
}

