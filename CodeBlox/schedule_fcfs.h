#ifndef SCHEDULE_FCFS_H
#define SCHEDULE_FCFS_H

#include "list.h"
#include "task.h"

// função para adicionar uma tarefa à lista de tarefas
void add(char *name, int burst);

// função para executar o escalonamento das tarefas
void schedule();

#endif /* SCHEDULE_FCFS_H */
