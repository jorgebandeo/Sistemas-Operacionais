#ifndef SCHEDULE_FCFS_H
#define SCHEDULE_FCFS_H

#include "list.h"
#include "task.h"

// fun��o para adicionar uma tarefa � lista de tarefas
void add(char *name, int burst);

// fun��o para executar o escalonamento das tarefas
void schedule();

#endif /* SCHEDULE_FCFS_H */
