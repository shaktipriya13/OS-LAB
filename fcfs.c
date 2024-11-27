// FCFS
#include<stdio.h>

struct process {
    int burst, wait;
} p[20] = {0, 0};

int main() {
    int n, i;
    int totalwait = 0, totalturn = 0;

    printf("\nEnter The No Of Process :");
    scanf("%d", &n);

    // Input burst times for each process
    for(i = 0; i < n; i++) {
        printf("Enter The Burst Time (in ms) For Process #%d :", i + 1);
        scanf("%d", &p[i].burst);
    }

    printf("\nProcess \t Waiting Time \t TurnAround Time ");
    printf("\n\t (in ms) \t (in ms)");

    // Calculate and display waiting time and turnaround time for each process
    for(i = 0; i < n; i++) {
        // The %12d means the output should be at least 12 characters wide, left-aligned
        // The %15d means the output should be at least 15 characters wide, left-aligned
        printf("\nProcess # %-12d%-15d%-15d", i + 1, p[i].wait, p[i].wait + p[i].burst);

        // Update waiting time for the next process, ensure we are within bounds
        if (i < n - 1) {
            p[i + 1].wait = p[i].wait + p[i].burst;
        }

        // Accumulate total waiting time and turnaround time
        totalwait += p[i].wait;
        totalturn += p[i].wait + p[i].burst;
    }

    // Print average waiting time and turnaround time
    printf("\n\nAVERAGE\n--------- ");
    printf("\nWaiting Time : %f ms", totalwait / (float)n);
    printf("\nTurnAround Time : %f ms\n\n", totalturn / (float)n);

    return 0;
}























































/*note:

Burst Time: The time required by a process for its execution on the CPU.

Waiting Time (WT) : The total time a process spends waiting in the ready queue before it gets CPU time for execution.
Waiting Time=Turnaround Time−Burst Time

Turnaround Time (TAT): The total time taken by a process from getting to the ready queue to its completion. It includes the waiting time and the burst time.
Turnaround Time=Completion Time−Arrival Time = wt+bt
*/





/*Output:
Enter The No Of Process :3
Enter The Burst Time (in ms) For Process # 1 :10
Enter The Burst Time (in ms) For Process # 2 :30
Enter The Burst Time (in ms) For Process # 3 :20

Process         Waiting Time    TurnAround Time 
                (in ms)         (in ms)
Process # 1     0              10             
Process # 2     10             40             
Process # 3     40             60             

*/

/*Detailed Calculation

    Process 1:
        Burst Time = 10 ms
        Completion Time = 10 ms (starts at 0 ms and finishes at 10 ms)
        Waiting Time = 0 ms (starts execution immediately)
        Turnaround Time = Completion Time = 10 ms

    Process 2:
        Burst Time = 20 ms
        Completion Time = 10 ms (previous completion) + 20 ms (burst) = 30 ms
        Waiting Time = 10 ms (waiting while Process 1 was executing)
        Turnaround Time = Completion Time = 30 ms

    Process 3:
        Burst Time = 30 ms
        Completion Time = 30 ms (previous completion) + 30 ms (burst) = 60 ms
        Waiting Time = 30 ms (waiting while Process 1 and Process 2 were executing)
        Turnaround Time = Completion Time = 60 ms

    Process 4:
        Burst Time = 22 ms
        Completion Time = 60 ms (previous completion) + 22 ms (burst) = 82 ms
        Waiting Time = 60 ms (waiting while Process 1, 2, and 3 were executing)
        Turnaround Time = Completion Time = 82 ms

    Process 5:
        Burst Time = 0 ms
        Completion Time = 82 ms (previous completion) + 0 ms (burst) = 82 ms
        Waiting Time = 82 ms (waiting while Process 1, 2, 3, and 4 were executing)
        Turnaround Time = Completion Time = 82 ms

Averages Calculation

    Average Waiting Time:
    Average Waiting Time=Total Waiting TimeNumber of Processes=0+10+30+60+825=36.4 ms
    Average Waiting Time=Number of ProcessesTotal Waiting Time​=50+10+30+60+82​=36.4 ms

    Average Turnaround Time:
    Average Turnaround Time=Total Turnaround TimeNumber of Processes=10+30+60+82+825=52.8 ms
    Average Turnaround Time=Number of ProcessesTotal Turnaround Time​=510+30+60+82+82​=52.8 ms*/