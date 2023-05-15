#ifndef SCHEDULE_RR_P_H_INCLUDED
#define SCHEDULE_RR_P_H_INCLUDED
#include "list.h"
#include "task.h"

void add_rp(char *name, int priority, int burst);
void swap(struct node *a, struct node *b);
void sort_by_priority();
void schedule_rr_p(struct node **head);

#endif // SCHEDULE_RR_P_H_INCLUDED
