/*
Kaitlyn Vetica
2365588
vetica@chapman.edu
CPSC-380-02
Assignment 4
*/

/*
    Round Robin Scheduler
    ???????????
    ????????
    ??????????
    ?????????
*/

#include <stdio.h>
#include <stdlib.h>

#include "schedulers.h"
#include "list.h"
#include "cpu.h"

struct node* head = NULL;
struct node* tail = NULL;

void add(char *name, int priority, int burst){
    struct task* temp = malloc(sizeof(struct task));
    temp->name = name;
    temp->priority = priority;
    temp->burst = burst;

    append(&tail, &head, temp);
}

void schedule(){
    while(head != NULL){
        struct task* tempTask = head->task;

        if(tempTask->burst > 10){
            run(tempTask, 10);
            tempTask->burst -= 10;
            delete(&head, tempTask);
            add(tempTask->name, tempTask->priority, tempTask->burst);
        }
        else if(tempTask->burst <= 10){
            run(tempTask, tempTask->burst);
            delete(&head, tempTask);
        }
    }
}