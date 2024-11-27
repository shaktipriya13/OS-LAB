// Lab code - Display parent id & process id
#include<stdio.h>
#include <unistd.h>
#include <cstdlib>

int main()
{
printf("\n Parent Process ID %d",getppid());
printf("\n Child Process ID %d\n",getpid());
}