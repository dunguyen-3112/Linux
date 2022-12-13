#define MAX_THREAD 4
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *routine(void *arg)
{
    sleep(1);
    int index = *(int *)arg;
    int s = 0;
    int *result = malloc(sizeof(int));

    int MIN = index * MAX_THREAD, MAX = (index + 1) * MAX_THREAD - 1;
    printf("Thread %d xu ly cac phan tu tu %d den %d.\n", index, MIN, MAX);
    for (int i = MIN; i <= MAX; i++)
    {
        s += i;
    }
    *result = s;
    printf("Thread %d, ThreadSum = %d\n", index, s);

    free(arg);
    return (void *)result;
}

int main(int argc, char *argv[])
{

    printf("*********************************************************************\n\
* Bai thi ket thuc mon: Lap trình tren Linux.                       *\n\  
* Ho va ten: NGUYEN HUU DU                                          *\n\
* Nhom: Nh19??                                                      *\n\
* Masv: 102190157                                                   *\n\
* De so: 05.                                                        *\n\
*********************************************************************\n\n");
    unsigned long long int Sum = 0;
    pthread_t th[MAX_THREAD];
    int i;
    long *res;
    for (i = 0; i < MAX_THREAD; i++)
    {
        int *a = malloc(sizeof(int));
        *a = i;
        if (pthread_create(&th[i], NULL, &routine, a) != 0)
        {
            perror("Failed to created thread");
        }
    }
    for (i = 0; i < MAX_THREAD; i++)
    {
        if (pthread_join(th[i], (void **)&res) != 0)
        {
            perror("Failed to join thread");
        }

        Sum += *res;
        free(res);
    }

    printf("Sum of SumThreads = %llu\n", Sum);

    return 0;
}