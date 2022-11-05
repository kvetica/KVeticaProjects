/*
Kaitlyn Vetica
2365588
vetica@chapman.edu
CPSC-380-02
Assignment 4
*/

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

// add a task to the list 
void add(char *name, int priority, int burst);

// invoke the scheduler
void schedule();

// preemptive = interrupted
// process name
// how long to run for
// priority if it uses
// burst rate
// priority
// Textbook Section 5.1.2
// assume single processor
