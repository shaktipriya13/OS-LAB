// SHORTEST JOB FIRST(SJF)
// Program:
#include<stdio.h>

struct process {
    int burst, wait, no;
} p[20];

int main() {
    int n, i, j;
    int totalwait = 0, totalturn = 0;

    // Input number of processes
    printf("\nEnter The No Of Process : ");
    scanf("%d", &n);

    // Input burst times for each process
    for(i = 0; i < n; i++) {
        printf("Enter The Burst Time (in ms) For Process #%2d : ", i + 1);
        scanf("%d", &p[i].burst);
        p[i].no = i + 1;
    }

    // Sort processes by burst time using bubble sort
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(p[j].burst > p[j + 1].burst) {
                // Swap burst times
                int tempBurst = p[j].burst;
                p[j].burst = p[j + 1].burst;
                p[j + 1].burst = tempBurst;

                // Swap process numbers
                int tempNo = p[j].no;
                p[j].no = p[j + 1].no;
                p[j + 1].no = tempNo;
            }
        }
    }

    // Calculate waiting time and turnaround time
    for(i = 0; i < n; i++) {
        if (i == 0) {
            p[i].wait = 0;  // The first process has no waiting time
        } else {
            p[i].wait = p[i - 1].wait + p[i - 1].burst;
        }
        totalwait += p[i].wait;
        totalturn += p[i].wait + p[i].burst;
    }

    // Print results
    printf("\nProcess \t Waiting Time \t TurnAround Time ");
    for(i = 0; i < n; i++) {
        printf("\nProcess # %-12d%-15d%-15d", p[i].no, p[i].wait, p[i].wait + p[i].burst);
    }

    // Print averages
    printf("\n\nAverage\n---------");
    printf("\nWaiting Time : %f ms", totalwait / (float)n);
    printf("\nTurnAround Time : %f ms\n\n", totalturn / (float)n);

    return 0;
}


/*explanation:
1. The processes are sorted in ascending order of their burst times using a bubble sort algorithm. This ensures that the shortest burst time is processed first.

1. Sorting

Before sorting:

    Process 1: Burst Time = 20 ms
    Process 2: Burst Time = 30 ms
    Process 3: Burst Time = 10 ms

After sorting (by burst time):

    Process 3: Burst Time = 10 ms
    Process 1: Burst Time = 20 ms
    Process 2: Burst Time = 30 ms

2. Waiting Time (WT) and Turnaround Time (TAT) Calculation

    Process 3 (Shortest burst time first):
        Waiting Time = 0 ms (starts immediately)
        Turnaround Time = Waiting Time + Burst Time = 0 ms + 10 ms = 10 ms

    Process 1 (Next shortest burst time):
        Waiting Time = Waiting Time of Process 3 + Burst Time of Process 3 = 0 ms + 10 ms = 10 ms
        Turnaround Time = Waiting Time + Burst Time = 10 ms + 20 ms = 30 ms

    Process 2 (Longest burst time):
        Waiting Time = Waiting Time of Process 1 + Burst Time of Process 1 = 10 ms + 20 ms = 30 ms
        Turnaround Time = Waiting Time + Burst Time = 30 ms + 30 ms = 60 ms

3. Output Calculation

    Process 3:
        Waiting Time = 0 ms
        Turnaround Time = 10 ms

    Process 1:
        Waiting Time = 10 ms
        Turnaround Time = 30 ms

    Process 2:
        Waiting Time = 30 ms
        Turnaround Time = 60 ms

Average Calculation

    Average Waiting Time:
    Average Waiting Time=Total Waiting TimeNumber of Processes=0+10+303=13.33 ms
    Average Waiting Time=Number of ProcessesTotal Waiting Time​=30+10+30​=13.33 ms

    Average Turnaround Time:
    Average Turnaround Time=Total Turnaround TimeNumber of Processes=10+30+603=33.33 ms
    Average Turnaround Time=Number of ProcessesTotal Turnaround Time​=310+30+60​=33.33 ms*/












/*Output:
Enter The No Of Process :3
Enter The Burst Time (in ms) For Process # 1 :20
Enter The Burst Time (in ms) For Process # 2 :30
Enter The Burst Time (in ms) For Process # 3 :10

Process          Waiting Time TurnAround Time 
Process # 3           0              10             
Process # 1           10             30             
Process # 2           30             60             

Average
---------
Waiting Time : 13.333333 ms
TurnAround Time : 33.333332 ms*/