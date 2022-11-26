#include <stdlib.h>
#include <stdio.h>

int main() {
    int i = 0;
    char* buffer = (char*) calloc(3000000000,1);
    printf("Done allocating\n");
    scanf("%d",&i);
    free(buffer);
    return 0;
}