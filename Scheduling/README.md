# CPU Scheduling

CPU Scheduling incorporating the priority, FCFS, SJF and round robin scheduling methods to process through a list of jobs according to their algorithms.

The Scheduling Algorithms:
* Priority scheduling schedules jobs based on their associated priority number. The higher the priority, the sooner they'll execute. 
* First come first server (FCFS) schedules jobs based on the order in which they are added to the job queue. 
* Shortest job first (SJF) schedules jobs based on their burst time (how long they need to execute for). The shorter the burst time, the sooner the jobs are scheduled.
* Round robin schedules jobs in the order in which they came into the queue, but the processes only execute for a given quantum time. Each process is executed for the same quantum time until all processes have executed to completion.


## Identifying Information

* Name: Kaitlyn Vetica
* Email: kaitlynvgolf@gmail.com
* Course: CPSC 380 - Operating Systems
* Date: Fall 2022
* Assignment: CPU Scheduling

## Source Files

* CPU.c
* driver.c
* list.c 
* schedule_fcfs.c
* schedule_priority.c
* schedule_priority_rr.c
* schedule_rr.c
* schedule_sjf.c 

## References

* Worked with Olivia Chilvers
* https://www.geeksforgeeks.org/program-for-fcfs-cpu-scheduling-set-1/
* https://www.geeksforgeeks.org/program-for-shortest-job-first-or-sjf-cpu-scheduling-set-1-non-preemptive/
* https://www.geeksforgeeks.org/program-round-robin-scheduling-set-1/


## Known Errors

* None

## Execution Instructions

* For compiling: Use makefile. 
* <code> make rr </code>
* <code> make fcfs </code>
* <code> make sjf </code>
* <code> make priority </code>

* For execution:
* <code> ./rr schedule.txt </code>
* <code> ./fcfs schedule.txt </code>
* <code> ./sjf schedule.txt </code>
* <code> ./priority schedule.txt </code>

## Sample Output

* Example output for <code> ./priority schedule.txt </code>
Running task = [T1] [4] [20] for 20 units.
Running task = [T2] [3] [25] for 25 units.
Running task = [T3] [3] [225] for 25 units.
Running task = [T4] [5] [15] for 15 units.
Running task = [T5] [5] [20] for 20 units.
Running task = [T6] [1] [10] for 10 units.
Running task = [T7] [3] [30] for 30 units.
Running task = [T8] [10] [25] for 25 units.