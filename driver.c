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
int main(int argc, char *argv[])
{
    FILE *in;
    char *temp;
    char task[SIZE];

    char *name;
    int priority;
    int burst;

    in = fopen(argv[1],"r");
    in = fopen("C:\\Users\\jorge\\Desktop\\iiii\\rr-schedule.txt","r");
    while (fgets(task,SIZE,in) != NULL) {
        temp = strdup(task);
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,","));
        burst = atoi(strsep(&temp,","));
        printf("Name: %s\n", name);
        printf("Priority: %d\n", priority);
        printf("Burst: %d\n", burst);
        // add the task to the scheduler's list of tasks
        add(name,priority);
        free(temp);

    }

    fclose(in);

    // invoke the scheduler
    schedule();
    return 0;
}
