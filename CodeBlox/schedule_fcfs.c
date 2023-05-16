#include <stdlib.h>
#include "schedule_fcfs.h"

#include "CPU.h"
#include "list.h"
#include "task.h"
int cont = 0;

struct node *task_list = NULL; // variável global para armazenar a lista de tarefas

// função para adicionar uma tarefa à lista de tarefas
void add(char *name,int priority ,int burst)
{
    cont += 1;
    Task *new_task = malloc(sizeof(Task));
    new_task->name = name;
    new_task->tid = cont ;
    new_task->priority = priority;
    new_task->burst = burst;
    insert_task(&task_list,new_task );
}
void schedule()
{
    while(task_list != NULL)
    {
        /// Encontra o primeiro elemento
        struct node *anterior = task_list;
        while(anterior->next != NULL)
        {
            anterior = anterior->next;
        }

        printf("---------------[%s]---------------------\n", anterior->task->name);

        /// Repete até o tempo limite ou até a tarefa ser concluída
        int cont_slice = 0;
        while( cont_slice < 30&& anterior->task->burst > 0)
        {
            if(anterior->task->burst<QUANTUM){
                cont_slice += anterior->task->burst;
            }else{
                cont_slice += QUANTUM;
            }
            /// Executa a tarefa
            run(anterior->task, cont_slice);

            /// Diminui a quantidade de tempo que a tarefa precisa
            anterior->task->burst -= QUANTUM ;

            /// Incrementa o contador do slice

        }

        /// Caso a tarefa ainda não tenha sido concluída, move para o final da fila
        if(anterior->task->burst > 0)
        {
            Task *salva = anterior->task;
            delete_task(&task_list, anterior->task);
            insert_task(&task_list, salva);
        }
        else
        {
            /// Se a tarefa foi concluída, remove da fila
            delete_task(&task_list, anterior->task);
        }
    }
}
