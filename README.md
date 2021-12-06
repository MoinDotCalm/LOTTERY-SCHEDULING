# LOTTERY-SCHEDULING
: In lottery scheduling, processes are scheduled in a random manner. Lottery scheduling can be preemptive or non-preemptive. It also solves the problem of starvation. Giving each process at least one lottery ticket guarantees that it has non-zero probability of being selected at each scheduling operation. In this scheduling every process has some tickets and scheduler picks a random ticket and process having that ticket is the winner and it is executed for a time slice(quantum) and then another ticket is picked by the scheduler. These tickets represent the share of processes. A process having a higher number of tickets give it more chance to get chosen for execution.


#Algorithm:
Step 1: Check for compensation
Step 2: Count the total number of tickets in the system
Step 3: Draw a lucky ticket randomly
Step 4: Search for the winning process, CPU is granted to the process with winning ticket.
Step 5: Set next to the winning process and return.
Step 6: After the completion of process distribute the tickets to other process and repeat the same until completion of all process.
