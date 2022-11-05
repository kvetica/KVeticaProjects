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

struct node* head;
int counter = 0;

void add(char *name, int priority, int burst){
    struct task* temp = malloc(sizeof(struct task));
    temp->name = name;
    temp->priority = priority;
    temp->burst = burst;
    
    counter++;
    insert(&head, temp);
}

void schedule(){
    // loop until list is empty
    // sort list into priority scheduling order 
    while (counter != 0){
        struct node* tempNode = head;
        struct task* tempTask = head->task;
        struct task* highestPriority = tempTask;

        // find the highest priority in list
        while(tempNode-> next != NULL){
            tempNode = tempNode->next;
            tempTask = tempNode->task;
            if(tempTask->priority > highestPriority->priority){
                highestPriority = tempTask;
                counter--;
            }
        }
        delete(&head, tempTask);
        insert(&head, highestPriority);
    }

    // round robin scheduling 
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