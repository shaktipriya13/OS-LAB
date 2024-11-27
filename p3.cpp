// Process creation using fork
#include <stdio.h>
#include <unistd.h>  // for fork()

int main() {
    printf("Before FORK \n");

    pid_t pid = fork();  // Create a new process

    if (pid < 0) {
        // If fork failed
        printf("Fork failed!\n");
    } else if (pid == 0) {
        // This is the child process
        printf("After FORK: I am the child process.\n");
    } else {
        // This is the parent process
        printf("After FORK: I am the parent process. My child's PID is %d\n", pid);
    }

    return 0;
}
