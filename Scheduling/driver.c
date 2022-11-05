/*
Kaitlyn Vetica
2365588
vetica@chapman.edu
CPSC-380-02
Assignment 4
*/

/*
The scheduler will  be  assigned  a  predefined  set  of  tasks  and  will  schedule  the  tasks  based  on  the  selected 
scheduling algorithm. Each task is assigned a priority and CPU burst. The following scheduling 
algorithms will be implemented:
    * First-come, first-served (FCFS), which schedules tasks in the order in which they request 
    the CPU.
    * Shortest-job-first (SJF), which schedules tasks in order of the length of the tasks’ next 
    CPU burst
    * Priority scheduling, which schedules tasks based on priority.
    * Round-robin (RR) scheduling, where each task is run for a time quantum (or for the 
    remainder of its CPU burst). 
Priorities range from 1 to 10, where a higher numeric value indicates a higher relative priority. 
For round-robin scheduling, the length of a time quantum is 10 milliseconds.
*/

/*
A Makefile is used to determine the specific scheduling algorithm that will be 
invoked by driver. For example, to build the FCFS scheduler, we would enter make rr and would 
execute the scheduler (using the schedule of tasks schedule.txt) as follows: ./fcfs schedule.txt 
Refer to the README file in the source code download for further details. Before proceeding, 
be sure to familiarize yourself with the source code provided as well as the Makefile
*/

/*
The file driver.c reads in the schedule of tasks, inserts each task into a linked list, and invokes 
the process scheduler by calling the schedule() function. 
The schedule() function executes each task according to the specified scheduling algorithm. 
Tasks selected for execution on the CPU 
are determined by the pick NextTask() function and are executed by invoking the run() function 
defined in the file.
*/

/*
A Makefile is used to determine the specific scheduling algorithm that will be 
invoked by driver. For example, to build the FCFS scheduler, we would enter make rr and would 
execute the scheduler (using the schedule of tasks schedule.txt) as follows: ./fcfs schedule.txt 
Refer to the README file in the source code download for further details. Before proceeding, 
be sure to familiarize yourself with the source code provided as well as the Makefile
*/

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

#include "task.h"
#include "list.h"
#include "schedulers.h"

#define SIZE    100

int main(int argc, char *argv[])
{
    FILE *in;
    char *temp;
    char task[SIZE];

    char *name;
    int priority;
    int burst;

    in = fopen(argv[1],"r");
    
    while (fgets(task,SIZE,in) != NULL) {
        temp = strdup(task);
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,","));
        burst = atoi(strsep(&temp,","));

        // add the task to the scheduler's list of tasks
        add(name,priority,burst);

        free(temp);
    }

    fclose(in);

    // invoke the scheduler
    schedule();

    return 0;
}
