/*
Kaitlyn Vetica
2365588
vetica@chapman.edu
CPSC-380-02
Assignment 4
*/

#include <stdio.h>
#include <stdlib.h>

#include "schedulers.h"
#include "list.h"
#include "cpu.h"

/*
    Shortest Job First Scheduler
    Executes the job with the shortest burst time first
    Goes down list in decreasing burst order 
    Executes until job list is empty.
*/

struct node* head;

void add(char *name, int priority, int burst){
    struct task* temp = malloc(sizeof(struct task));
    temp->name = name;
    temp->priority = priority;
    temp->burst = burst;

    insert(&head, temp);
}

void schedule(){
    while(head != NULL){
        struct node* tempNode = head;
        struct task* tempTask = head->task;
        struct task* shortestBurst = tempTask;

        while(tempNode->next != NULL){
            tempNode = tempNode->next;
            tempTask = tempNode->task;
            if(tempTask->burst < shortestBurst->burst){
                shortestBurst = tempTask;
            }
        }

        run(shortestBurst, shortestBurst->burst);
        delete(&head, shortestBurst);
    }
}

