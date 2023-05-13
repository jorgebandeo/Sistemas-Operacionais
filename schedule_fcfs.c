#include <stdlib.h>
#include "schedule_fcfs.h"

#include "CPU.h"
#include "list.h"
#include "task.h"
int cont = 0;
struct node *task_list = NULL; // variável global para armazenar a lista de tarefas

// função para adicionar uma tarefa à lista de tarefas
void add(char *name, int burst)
{
    cont += 1;
    Task *new_task = malloc(sizeof(Task)); // aloca espaço na memória para uma nova Task
    new_task->name = name; // atribui o valor "exemplo" ao atributo name do novo elemento
    new_task->tid = cont ; // atribui o valor 1 ao atributo tid do novo elemento
    new_task->priority = 2; // atribui o valor 2 ao atributo priority do novo elemento
    new_task->burst = burst; // atribui o valor 10 ao atributo burst do novo elemento

    insert_task(&task_list,new_task );
}

// função para executar o escalonamento das tarefas
void schedule()
{
    while(task_list != NULL){
        struct node *anterior = task_list; // variável global para armazenar a lista de tarefas
        while(anterior->next != NULL){
            anterior = anterior->next;
        }

        run( anterior->task,  anterior->task->burst);
        delete_task(&task_list, anterior->task);
    }

}
