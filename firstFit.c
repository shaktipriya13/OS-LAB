#include <stdio.h>

struct process {
    char name[20];
    int size;
};

struct block {
    int id, size, flag;
};

int main() {
    struct block b[10] = {0};  // Array to store memory blocks
    struct process p[10] = {0};  // Array to store processes
    int nb, np, i, j;

    // Input total number of memory blocks
    printf("Enter the No of Blocks: ");
    scanf("%d", &nb);

    // Input block sizes
    for(i = 0; i < nb; i++) {
        b[i].id = i + 1; // Assign block ID
        printf("Enter the Size of Block %d: ", i + 1);
        scanf("%d", &b[i].size);
    }

    // Input total number of processes
    printf("Enter the No of Processes: ");
    scanf("%d", &np);

    // Input process names and sizes
    for(i = 0; i < np; i++) {
        printf("Enter The Name of Process %d: ", i + 1);
        scanf("%s", p[i].name);
        printf("Enter The Size of Process %d: ", i + 1);
        scanf("%d", &p[i].size);
    }

    // First Fit Memory Allocation Algorithm
    for(i = 0; i < np; i++) {
        for(j = 0; j < nb; j++) {
            if(b[j].flag == 0 && b[j].size >= p[i].size) {  // If block is free and fits the process
                b[j].flag = 1;  // Mark block as allocated
                printf("\nProcess %s allocated to Block %d\n", p[i].name, b[j].id);
                break;
            }
        }
        if(j == nb) {
            printf("\nProcess %s Waiting for Memory\n", p[i].name);  // If no block fits
        }
    }

    // Display memory blocks after allocation
    printf("\nBlock ID    Block Size    Status\n");
    for(i = 0; i < nb; i++) {
        printf("%-10d%-12d%s\n", b[i].id, b[i].size, b[i].flag ? "Allocated" : "Empty");
    }
    /*%-10d:

%d: This is a format specifier that means the value to be printed is an integer (b[i].id in this case).
-: This left-aligns the value within the specified width.
10: This specifies the width of the output. It ensures the printed integer takes up 10 character spaces. If the number is shorter, it will add spaces to the right to make it exactly 10 characters wide.
For e*/

    return 0;
}
/*Explanation:
Structures:

struct process: Represents a process, with a name (array to store the process name) and size (size of the process).
struct block: Represents a memory block, with:
id: Unique identifier for each block.
size: Size of the block.
flag: Indicates if the block is allocated (1) or free (0).
Input Section:

First, it asks for the number of memory blocks and their sizes.
Then, it takes the number of processes and their sizes, as well as their names.
First Fit Allocation Logic:

For each process, it checks the list of memory blocks to find the first block that is:
Free (indicated by flag == 0)
Large enough to accommodate the process (b[j].size >= p[i].size).
Once a suitable block is found, the process is allocated to that block, and the block's flag is set to 1 (indicating it is now occupied).
If no suitable block is found for a process, the process remains in the "waiting" state, and a message is displayed saying the process is waiting for memory.
Output Section:

After all processes have been considered for allocation, the code prints the current state of the memory blocks, showing whether each block is "Allocated" or "Empty."
Example Input/Output:
Input:

mathematica
Copy code
Enter the No of Blocks: 3
Enter the Size of Block 1: 30
Enter the Size of Block 2: 20
Enter the Size of Block 3: 10
Enter the No of Processes: 3
Enter The Name of Process 1: P1
Enter The Size of Process 1: 30
Enter The Name of Process 2: P2
Enter The Size of Process 2: 10
Enter The Name of Process 3: P3
Enter The Size of Process 3: 20
Output:

mathematica
Copy code
Process P1 allocated to Block 1
Process P2 allocated to Block 3
Process P3 allocated to Block 2

Block ID    Block Size    Status
1           30            Allocated
2           20            Allocated
3           10            Allocated
Key Points:
First Fit memory allocation finds the first block that can accommodate a process.
If a block is found, it's marked as allocated, and the process is assigned to it.
If no suitable block is found, the process will wait.*/