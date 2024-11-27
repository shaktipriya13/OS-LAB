#include <stdio.h>
#include <unistd.h>  // for fork()

int main() {
    printf("Before FORK \n");
    fork();
    printf("After FORK \n\n");
    return 0;
}
