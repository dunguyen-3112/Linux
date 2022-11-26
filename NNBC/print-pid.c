#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    printf("ID of process is %d\n", (int)getpid());         // get id of process currently running
    printf("ID of process parent is %d\n", (int)getppid()); // get id of process parent
    return 0;
}
