#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int cpid;
    cpid = fork();
    if (cpid == -1)
    {
        printf("\nFork failed\n");
        exit(1);
    }
    if (cpid == 0) // child code
        printf("\n Hello I am child \n");
    else
        // parent code
        printf("\n Hello I am parent \n");
}