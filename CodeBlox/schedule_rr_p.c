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
    sort_by_priority(&TASK_LIST_p);///organiza o vetor de tesk do maior para o menor
    while(TASK_LIST_p != NULL){

        struct node *prioritarios = NULL;
        Task *tranferen = TASK_LIST_p->task;
        delete_task(&TASK_LIST_p,TASK_LIST_p->task );///remove o ultimo da lista
        insert_task(&prioritarios,tranferen);///incluir o ultimo que é o de maior prioridade

        while(prioritarios->task->priority == TASK_LIST_p->task->priority){///Ve se o novo proximo tem a mesma prioridade
            Task *tranfer = TASK_LIST_p->task;
            delete_task(&TASK_LIST_p,TASK_LIST_p->task );///remove o ultimo da lista
            insert_task(&prioritarios,tranfer );///incluir o ultimo que é o de maior prioridade
        }

        while(prioritarios!=NULL){/// comesa o RR
            struct node *inicio = prioritarios;//pega o final da fila

            while(inicio->next !=NULL){//movimenta ate o inicio
                inicio = inicio->next;
            }

            int slince_cont = 0;
            Task *tranfer = inicio->task;//pega a primaira tes da fila

            ///pega o menor slince possivel
            if (tranfer->burst > QUANTUM){
                slince_cont = QUANTUM;
            }else{
                slince_cont = tranfer->burst;
            }

            run(tranfer, slince_cont);///execunta tarefa
            tranfer->burst -= QUANTUM;

            if (tranfer->burst <= 0){///se meu tempo foi atingido deleta
                delete_task(&prioritarios,tranfer);
            }else{///se não retona para o fim da fila
                delete_task(&prioritarios,tranfer);
                insert_task(&prioritarios,tranfer);

            }

        }

    }

}

