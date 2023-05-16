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
#include "schedule_rr.h"
#include "task.h"
#include "list.h"

#include "schedule_fcfs.h"


#define SIZE    100


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

#include <stdio.h>

int menu() {
    int opcao;
    do {
        printf("Selecione uma opção:\n");
        printf("1. Método FCFS\n");
        printf("2. Método Round Robin sem prioridade\n");
        printf("3. Método Round Robin com prioridade\n");
        scanf("%d", &opcao);
    } while (opcao < 1 || opcao > 3);
    return opcao;
}



int main(int argc, char *argv[])
{
    FILE *in;
    char *temp;
    char task[SIZE];

    char *name;
    int priority;
    int burst;

    int opcao =menu();
    in = fopen("rr-schedule.txt","r");
    if (opcao == 3 ){
        in = fopen("rr-schedule_pri.txt","r");
    }

    while (fgets(task,SIZE,in) != NULL) {
        temp = strdup(task);
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,","));
        burst = atoi(strsep(&temp,","));

        // add the task to the scheduler's list of tasks
        if (opcao == 1){
            add(name,priority,burst);
        }else if (opcao == 2){
            add_r(name,priority,burst);
        }else{
            add_rp(name,priority,burst);
        }

        free(temp);

    }

    fclose(in);

    // invoke the scheduler

    if (opcao == 1){
            schedule();
        }else if (opcao == 2){
            schedule_rr();
        }else{
            schedule_rr_p();

        }



    return 0;
}
