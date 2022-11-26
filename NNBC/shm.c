#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
int main()
{
    int segment_id;
    char *shared_memory;
    struct shmid_ds shmbuffer;
    int segment_size;
    const int shared_segment_size = 0x6400;

    /* Chi ra shared memory segment */
    segment_id = shmget(IPC_PRIVATE, shared_segment_size, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
    /* Gan ket phan doan bo nho chung*/
    shared_memory = (char *)shmat(segment_id, 0, 0);
    printf("Bo nho chia se gan ket den dia chi %p\n", shared_memory);
    /* Chi dinh kich thuoc phan doan */
    shmctl(segment_id, IPC_STAT, &shmbuffer);
    segment_size = shmbuffer.shm_segsz;
    printf("Kich thuoc segment: %d\n", segment_size);
    /* Ghi mot chuoi len phan doan bo nho dung chung*/
    sprintf(shared_memory, "Hello, hello, hello!!!");
    /* Go bo gan ket phan doan bo nho chung*/
    shmdt(shared_memory);
    /* Gan ket lai phan doan bo nho chung voi dia chi khac*/
    shared_memory = (char *)shmat(segment_id, (void *)0x5000000, 0);
    printf("Bo nho chia se gan ket lai den dia chi %p\n", shared_memory);
    /* In ra chuoi tu bo nho chia se*/
    printf("%s \n", shared_memory);
    /* Go bo gan ket phan doan bo nho chung*/
    shmdt(shared_memory);
    /* Chi dinh lai kich thuoc phan doan */
    shmctl(segment_id, IPC_RMID, 0);
    return 0;
}