/*
Kaitlyn Vetica
2365588
vetica@chapman.edu
CPSC-380-02
Assignment 4
*/

/*
    Priority Scheduler
    Executes the highest priority job first and 
    continues down the line of priority until list of 
    jobs is complete.
*/

#include <stdio.h>
#include <stdlib.h>

#include "schedulers.h"
#include "list.h"
#include "cpu.h"

struct node* head;

void add(char *name, int priority, int burst){
    struct task* temp = malloc(sizeof(struct task));
    temp->name = name;
    temp->priority = priority;
    temp->burst = burst;
    
    insert(&head, temp);
}

void schedule(){
    // execute highest priority first, continue down list
    // loop until list is empty
    while (head != NULL){
        struct node* tempNode = head;
        struct task* tempTask = head->task;
        struct task* highestPriority = tempTask;

        // find the highest priority in list
        while(tempNode-> next != NULL){
            tempNode = tempNode->next;
            tempTask = tempNode->task;
            if(tempTask->priority > highestPriority->priority){
                highestPriority = tempTask;
            }
        }

        run(highestPriority, highestPriority->burst);
        delete(&head, highestPriority);
    }
}