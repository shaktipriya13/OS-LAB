// In Round Robin scheduling, each process is assigned a fixed time slice (quantum) for execution. When a process's time slice expires, it is placed at the back of the queue, and the CPU scheduler gives the CPU to the next process in the queue.

#include <stdio.h>

struct process {
    int burst;
    int wait;
    int turnaround;
};

int main() {
    struct process p[20]; // Array to hold processes
    int n, i, quantum, totalwait = 0, totalturn = 0;
    
    printf("\nEnter The No Of Process: ");
    scanf("%d", &n);
    
    // Input for burst times
    for (i = 0; i < n; i++) {
        printf("Enter The Burst Time (in ms) For Process #%2d: ", i + 1);
        scanf("%d", &p[i].burst);
        p[i].wait = 0; // Initialize wait time to 0
        p[i].turnaround = 0; // Initialize turnaround time to 0
    }
    
    printf("Enter Time Quantum (in ms): ");
    scanf("%d", &quantum);

    int remaining_burst[20]; // To keep track of remaining burst time
    for (i = 0; i < n; i++) {
        remaining_burst[i] = p[i].burst; // Initialize remaining burst time
    }

    int time = 0; // Current time
    int finished = 0; // To count finished processes

    // Main Round Robin scheduling logic
    while (finished < n) {
        for (i = 0; i < n; i++) {
            if (remaining_burst[i] > 0) { // Process is not finished
                if (remaining_burst[i] > quantum) {
                    // Process executes for the quantum time
                    time += quantum;
                    remaining_burst[i] -= quantum;
                } else {
                    // Process finishes
                    time += remaining_burst[i];
                    p[i].turnaround = time; // Turnaround time
                    p[i].wait = time - p[i].burst; // Waiting time
                    totalwait += p[i].wait; // Accumulate waiting time
                    totalturn += p[i].turnaround; // Accumulate turnaround time
                    remaining_burst[i] = 0; // Mark process as finished
                    finished++; // Increment finished process count
                }
            }
        }
    }

    // Output results
    printf("\nProcess \t Waiting Time \t Turnaround Time");
    printf("\n-------------------------------------------------");
    for (i = 0; i < n; i++) {
        printf("\nProcess #%d \t %d ms \t\t %d ms", i + 1, p[i].wait, p[i].turnaround);
    }

    printf("\n\nAVERAGE\n---------");
    // Ensure division is safe
    if (n > 0) {
        printf("\nWaiting Time : %f ms", totalwait / (float)n);
        printf("\nTurnaround Time : %f ms\n\n", totalturn / (float)n);
    } else {
        printf("\nNo processes to calculate averages.\n\n");
    }
    
    return 0;
}

/*
i/p:

Enter The No Of Process: 3
Enter The Burst Time (in ms) For Process # 1: 10
Enter The Burst Time (in ms) For Process # 2: 30
Enter The Burst Time (in ms) For Process # 3: 20
Enter Time Quantum (in ms): 10


o/p:
Process         Waiting Time    Turnaround Time
-------------------------------------------------
Process #1     30 ms           40 ms
Process #2     10 ms           40 ms
Process #3     20 ms           40 ms

AVERAGE
---------
Waiting Time : 20.000000 ms
Turnaround Time : 40.000000 ms

*/