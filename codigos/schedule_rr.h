#ifndef SCHEDULE_RR_H_INCLUDED
#define SCHEDULE_RR_H_INCLUDED

#include "list.h"
#include "task.h"


void add_r(char *name,int priority, int burst);

void schedule_rr();

#endif // SCHEDULE_RR_H_INCLUDED
