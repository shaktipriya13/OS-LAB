#include <stdio.h>
#include <unistd.h>  // for fork()

int main() {
    printf("Before FORK \n");
    fork();
    printf("After FORK \n\n");
    return 0;
}
/*steps for execution of lab 3:
1. Write your above code and save it.
2. Then compile it first using terminal of vsCODE . type: 
gcc fork.cpp -o fork

note: Ensure that there are no errors in the compilation process. If there are errors, gcc will display them. Fix any errors and recompile if necessary.

3. Execute the compiled program by typing the following command in the terminal:
./fork


Explanation of Code:
This happens because:

    -> Before fork(), only the parent process is running, so you see "Before FORK" printed once.
    -> After fork(), both the parent and child processes are running, and both print "After FORK" independently.
    -> The child doesn't execute the code before fork() since it only exists after fork() is called.

    The area for child process is diff. from the raea of parent process

    What is orphan, zomby and demon process
    -> jiska parent is killed and child is yet not completed -> orphan
    zomby -> process is killed/exit from execution but its code and data is still available in the system

    what if the parent process gets killed and the child process is still alive?
    wHO WILL MANAGE THE CHILD PROCESS. INIT PROCESS IT IS THE SUPER Privelegged process.

    2^n-1 total processes if n times a process gets forked.
*/
