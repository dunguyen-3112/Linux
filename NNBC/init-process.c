#include <stdlib.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a = 12;
    int *b = &a;
    *b = 100;
    printf("a = %d\n", a);
    int return_value;
    return_value = system("ls -l");
    return return_value;
}
