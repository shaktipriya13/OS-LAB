#include <stdio.h>
//In priority scheduling, processes are executed based on their priority. In this case, lower numbers mean higher priority. This helps ensure that more important or time-sensitive tasks get CPU time earlier.
#define MAX_PROCESSES 20

struct process {
    int burst, wait, no, priority;
} p[MAX_PROCESSES];

int main() {
    int n, i, j;
    int totalWait = 0, totalTurn = 0;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst times and priorities
    for (i = 0; i < n; i++) {
        printf("Enter burst time (ms) for process #%d: ", i + 1);
        scanf("%d", &p[i].burst);
        printf("Enter priority for process #%d: ", i + 1);
        scanf("%d", &p[i].priority);
        p[i].no = i + 1;
    }

    // Sort processes by priority
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p[j].priority > p[j + 1].priority) {
                // Swap burst times
                int tempBurst = p[j].burst;
                p[j].burst = p[j + 1].burst;
                p[j + 1].burst = tempBurst;

                // Swap priorities
                int tempPriority = p[j].priority;
                p[j].priority = p[j + 1].priority;
                p[j + 1].priority = tempPriority;

                // Swap process numbers
                int tempNo = p[j].no;
                p[j].no = p[j + 1].no;
                p[j + 1].no = tempNo;
            }
        }
    }

    // Calculate waiting time and turnaround time
    p[0].wait = 0;
    totalWait = 0;
    totalTurn = p[0].burst;

    for (i = 1; i < n; i++) {
        p[i].wait = p[i - 1].wait + p[i - 1].burst;
        totalWait += p[i].wait;
        totalTurn += p[i].wait + p[i].burst;
    }

    // Print results
    printf("\nProcess\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("Process #%d\t%d\t\t%d\n", p[i].no, p[i].wait, p[i].wait + p[i].burst);
    }

    // Print averages
    printf("\nAverage Waiting Time: %.2f ms\n", (float)totalWait / n);
    printf("Average Turnaround Time: %.2f ms\n", (float)totalTurn / n);

    return 0;
}











/*output:
Enter the number of processes: 3
Enter burst time (ms) for process #1: 30
Enter priority for process #1: 2
Enter burst time (ms) for process #2: 20
Enter priority for process #2: 1
Enter burst time (ms) for process #3: 40
Enter priority for process #3: 3


Process    Waiting Time    Turnaround Time
Process #2    0              20
Process #1    20             50
Process #3    50             90

Average Waiting Time: 23.33 ms
Average Turnaround Time: 53.33 ms
*/