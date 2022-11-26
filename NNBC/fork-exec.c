#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int spawn(char *program, char **arg_list)
{
    int child_pid = fork();
    if (child_pid != 0)
        return child_pid;
    else
    {
        printf("Process child with pid %d running...\n", (int)getpid());
        execvp(program, arg_list);
        fprintf(stderr, "Loi xay ra trong execvpn");
        abort();
    }
}

int main()
{
    char *arg_list[] = {"ls", "-l", "/", NULL};
    printf("Process main with PIP %d and terminate. \n",(int)getpid());
    spawn("ls", arg_list);
    printf("Process main with pid %d sleeping...\n", (int)getpid());
    sleep(5);
    printf("wakeup Process main with PIP %d and terminate. \n",(int)getpid());
    return 0;
}