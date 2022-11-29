#include <pthread.h>
#include <stdio.h>
struct char_print_parms
{
    char character; // ký tự để in
    int count;      // Số lần in ký tự
};
/* Hàm in số ký tự được cho bởi *PARAMETERS, trỏ
đến cấu trúc char_print_parms. */
void *char_print(void *parameters)
{
    /* Cast the cookie pointer to the right type. */
    struct char_print_parms *p = (struct
                                  char_print_parms *)parameters;
    int i;
    for (i = 0; i < p->count; ++i)
        fputc(p->character, stderr);
    return NULL;
}

int main()
{
    pthread_t thread1_id;
    pthread_t thread2_id;
    struct char_print_parms thread1_args;
    struct char_print_parms thread2_args;
    /* Tạo luồng 1 để in 30,000 ký tự x */
    thread1_args.character = 'x';
    thread1_args.count = 30000;
    pthread_create(&thread1_id, NULL,
                   &char_print, &thread1_args);
    /* Tạo luồng 2 để in 20,000 ký tự o. */
    thread2_args.character = 'o';
    thread2_args.count = 20000;
    pthread_create(&thread2_id, NULL,
                   &char_print, &thread2_args);
    return 0;
}