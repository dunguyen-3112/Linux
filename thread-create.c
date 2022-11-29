#include <pthread.h>
#include <stdio.h>
/*Hàm in ra các lỗi chuẩn.
Tham số unused, hàm không
trả về giá trị.
*/
void *print_xs(void *unused)
{
    while (1)
        fputc('x', stderr);
    return NULL;
}

int main()
{
    pthread_t thread_id;
    /* Tạo ra một luồng mới chạy hàm
    print_xs()
    */
    pthread_create(&thread_id, NULL, &print_xs, NULL);
    /* Hàm print tiếp tục in chuỗi 'o'. */
    while (1)
        fputc('o', stderr);
    return 0;
}