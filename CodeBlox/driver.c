/**
 * Driver.c
 *
 * Schedule is in the format
 *
 *  [name] [priority] [CPU burst]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "task.h"
#include "list.h"
//#include "schedule_fcfs.h"
//#include "schedule_rr.h"

#define SIZE    100


///////////////////////
#include "CPU.h"
int tid_counter = 0;
struct node *TASK_LIST = NULL;
void add1(char *name, int priority, int burst) {
    Task *new_task = malloc(sizeof(Task));
    new_task->name = name;
    new_task->tid = ++tid_counter;
    new_task->priority = priority;
    new_task->burst = burst;
    insert_task(&TASK_LIST, new_task);
}
void schedule_r() {
    struct node *temp;
    while (TASK_LIST != NULL) {
        temp = TASK_LIST;
        while (temp != NULL) {
            if (temp->task->burst > QUANTUM) {
                run(temp->task, QUANTUM);
                temp->task->burst -= QUANTUM;
            } else {
                run(temp->task, temp->task->burst);
                delete_task(&TASK_LIST, temp->task);
            }
            temp = temp->next;
        }
    }
}
//////////////////////

char *strsep(char **stringp, const char *delim) {
    char *rv = *stringp;
    if (rv) {
        *stringp += strcspn(*stringp, delim);
        if (**stringp)
            *(*stringp)++ = '\0';
        else
            *stringp = 0; }
    return rv;
}
int main(int argc, char *argv[])
{
    FILE *in;
    char *temp;
    char task[SIZE];

    char *name;
    int priority;
    int burst;

    in = fopen(argv[1],"r");
    in = fopen("rr-schedule.txt","r");
    while (fgets(task,SIZE,in) != NULL) {
        temp = strdup(task);
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,","));
        burst = atoi(strsep(&temp,","));

        // add the task to the scheduler's list of tasks
        add1(name,priority,burst);
        free(temp);

    }

    fclose(in);

    // invoke the scheduler
    //schedule();
    schedule_r();

    return 0;
}
