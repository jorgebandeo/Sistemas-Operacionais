#include <stdlib.h>
#include "CPU.h"
#include "list.h"
#include "task.h"

int tid_counter = 0;
struct node *TASK_LIST = NULL;
// Fun��o para adicionar uma nova tarefa � lista de tarefas
void add_r(char *name, int priority, int burst) {
    Task *new_task = malloc(sizeof(Task));
    new_task->name = name;
    new_task->tid = ++tid_counter;
    new_task->priority = priority;
    new_task->burst = burst;
    insert_task(&TASK_LIST, new_task);
}
// Fun��o para o escalonamento Round-Robin (RR)
void schedule_rr() {
    struct node *temp;
    while (TASK_LIST != NULL) {
        temp = TASK_LIST;
        while (temp != NULL) {
            if (temp->task->burst > QUANTUM) {
                // Executa a tarefa pelo tempo do quantum
                run(temp->task, QUANTUM);
                temp->task->burst -= QUANTUM;
            } else {
                // Se a tarefa for conclu�da, remove da lista de tarefas
                run(temp->task, temp->task->burst);
                struct node *next_task = temp->next;
                delete_task(&TASK_LIST, temp->task);
                temp = next_task;
                continue; // Continue diretamente para evitar o avan�o de temp
            }
            temp = temp->next;
        }
    }
}
