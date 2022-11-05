/*
Kaitlyn Vetica
2365588
vetica@chapman.edu
CPSC-380-02
Assignment 4
*/

/*
    First Come First Serve Scheduler
    First job added to the list is executed first, then
    goes down the line in order of when the job was 
    added to the list. Executes until list of jobs 
    is empty.
*/

#include <stdlib.h>
#include <stdio.h>

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
    // excutes first element in list 
    // lopos through the list until list is empty
    while(head != NULL){
        struct node* tempNode = head;
        struct task* tempTask = tempNode->task;

        run(tempTask, tempTask->burst);
        // deletes this task and moves down list
        delete(&head, tempTask);
    }
}