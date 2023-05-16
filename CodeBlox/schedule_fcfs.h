#ifndef SCHEDULE_FCFS_H
#define SCHEDULE_FCFS_H

#include "list.h"
#include "task.h"


void add(char *name,int priority, int burst);//adicionar uma tarefa à lista de tarefas
void schedule();//executar o escalonamento das tarefas

#endif /* SCHEDULE_FCFS_H */
