// PRODUCER CONSUMER PROBLEM USING SEMAPHORE

#include <stdio.h>    /* Standard I/O routines */
#include <stdlib.h>   /* For rand() and srand() functions */
#include <unistd.h>   /* For fork(), etc. */
#include <time.h>     /* For nanosleep() function */
#include <sys/types.h>/* Various type definitions */
#include <sys/ipc.h>  /* General SysV IPC structures */
#include <sys/sem.h>  /* Semaphore functions and structs */

#define NUM_LOOPS 10  /* Number of loops to perform */

int main() {
    int sem_set_id;    /* ID of the semaphore set */
    int child_pid;     /* PID of the child process */
    int i;             /* Counter for loop operation */
    struct sembuf sem_op; /* Structure for semaphore operations */
    int rc;            /* Return value of system calls */
    struct timespec delay; /* Used for wasting time */

    /* Create a private semaphore set with one semaphore in it */
    /* With access only to the owner */
    sem_set_id = semget(IPC_PRIVATE, 1, 0600);
    if (sem_set_id == -1) {
        perror("Error creating semaphore");
        exit(1);
    }

    printf("Semaphore set created, semaphore set id: '%d'\n", sem_set_id);

    /* Initialize the semaphore to 0 */
    rc = semctl(sem_set_id, 0, SETVAL, 0);
    if (rc == -1) {
        perror("Error initializing semaphore");
        exit(1);
    }

    /* Fork-off a child process and start a producer/consumer job */
    child_pid = fork();
    switch (child_pid) {
        case -1: /* Fork failed */
            perror("Fork failed");
            exit(1);

        case 0: /* Child process (Consumer) */
            for (i = 0; i < NUM_LOOPS; i++) {
                /* Wait (decrement) on the semaphore, block if it's zero */
                sem_op.sem_num = 0;
                sem_op.sem_op = -1;
                sem_op.sem_flg = 0;
                semop(sem_set_id, &sem_op, 1);

                printf("Consumer: '%d'\n", i);
                fflush(stdout);
            }
            break;

        default: /* Parent process (Producer) */
            for (i = 0; i < NUM_LOOPS; i++) {
                printf("Producer: '%d'\n", i);
                fflush(stdout);

                /* Signal (increment) the semaphore by 1 */
                sem_op.sem_num = 0;
                sem_op.sem_op = 1;
                sem_op.sem_flg = 0;
                semop(sem_set_id, &sem_op, 1);

                /* Pause execution for a bit to allow the child process to run */
                if (rand() > 3 * (RAND_MAX / 4)) {
                    delay.tv_sec = 0;
                    delay.tv_nsec = 10000000; /* 10 ms */
                    nanosleep(&delay, NULL);
                }
            }
            break;
    }

    return 0;
}
