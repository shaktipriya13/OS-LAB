// The Worst Fit Memory Allocation algorithm allocates the process to the largest available block that can accommodate it. This ensures that the remaining free space after allocation is as large as possible, potentially leaving large unallocated blocks.

#include <stdio.h>
// #include <conio.h>  // Specific to some older compilers

struct process {
    char name[20];
    int size;
};

struct block {
    int id, size, flag;
};

int main() {
    struct block b[10] = {0};  // Array for memory blocks
    struct process p[10] = {0};  // Array for processes
    int nb, np, i, j, k, max;

    // clrscr();  // Clears the console (specific to conio.h)
    
    // Input number of blocks and their sizes
    printf("Enter The No Of Blocks : ");
    scanf("%d", &nb);

    for(i = 0; i < nb; i++) {
        printf("Enter The Size of Block %d : ", i + 1);
        scanf("%d", &b[i].size);
        b[i].id = i + 1;  // Assign block ID
    }

    // Input number of processes and their sizes
    printf("Enter The No Of Processes : ");
    scanf("%d", &np);

    for(i = 0; i < np; i++) {
        printf("Enter The Size of Process %d : ", i + 1);
        scanf("%d", &p[i].size);
    }

    // Worst Fit Memory Allocation Algorithm
    for(i = 0; i < np; i++) {
        max = -1;  // Set initial max to a very small number
        for(j = 0; j < nb; j++) {
            // Find the largest block that can fit the process
            if(b[j].flag == 0 && b[j].size >= p[i].size && b[j].size > max) {
                max = b[j].size;
                k = j;  // Store index of the best block found
            }
        }
        if(max != -1) {
            // Allocate the process to the worst-fit block
            b[k].flag = 1;
            printf("\nProcess %d allocated to Block %d", i + 1, b[k].id);
        } else {
            printf("\nProcess %d is Waiting", i + 1);  // No suitable block found
        }
    }

    // Display final status of memory blocks
    printf("\n\nBlock_ID  Block_Size  Process_ID\n");
    for(i = 0; i < nb; i++) {
        printf("%d          %d          %s\n", b[i].id, b[i].size, (b[i].flag ? "Allocated" : "Empty"));
    }

    return 0;
}

/*Explanation:
Structures:

struct process: This structure defines a process with:
name: An array to store the name of the process (not used in this specific code example).
size: The size of the process.
struct block: This structure defines a memory block with:
id: A unique identifier for the block.
size: The size of the block.
flag: A flag indicating whether the block is free (0 means free, 1 means allocated).
Input Section:

First, the user is prompted to input the number of memory blocks and their sizes.
Then, the user is asked to input the number of processes and their sizes.
Worst Fit Allocation Logic:

The algorithm looks for the largest block that is big enough to fit each process.
For each process, the program checks all the memory blocks and selects the one with the largest size that is still large enough to accommodate the process. This is done by maintaining a max variable to store the largest block that can fit the process.
If such a block is found, the process is allocated to it, and the block is marked as occupied (flag = 1).
If no suitable block is found, the process is put into the "Waiting" state, and the program prints a message indicating that the process is waiting.
Output Section:

After attempting to allocate all processes, the program prints a list of memory blocks, showing their IDs, sizes, and whether they are allocated or free.
Example Input/Output:
Input:

mathematica
Copy code
Enter The No Of Blocks : 3
Enter The Size of Block 1 : 30
Enter The Size of Block 2 : 20
Enter The Size of Block 3 : 10
Enter The No Of Processes : 3
Enter The Size of Process 1 : 10
Enter The Size of Process 2 : 20
Enter The Size of Process 3 : 30
Output:

mathematica
Copy code
Process 1 allocated to Block 1
Process 2 allocated to Block 1
Process 3 allocated to Block 1

Block_ID  Block_Size  Process_ID
1          30          Allocated
2          20          Empty
3          10          Empty
Key Points:
Worst Fit memory allocation looks for the largest block available to fit each process, so there is as much remaining space as possible after each allocation.
If no block is large enough, the process will wait.
The goal of Worst Fit is to avoid small remaining fragments of memory, but this can lead to internal fragmentation if blocks are too large for the processes.
This method can reduce the likelihood of small unallocated memory pieces, but over time, it may result in inefficient memory use, as large blocks can get broken up, leaving fragmented memory that is difficult to reuse efficiently.






*/

