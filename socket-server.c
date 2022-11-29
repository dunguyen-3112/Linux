#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int server(int client_socket)
{
    while (1)
    {
        int length;
        char *text;
        /* Doc do dai cua doan text tu socket. Neu ham read tra ve gia tri 0, client dong
        ket noi*/
        if (read(client_socket, &length, sizeof(length)) == 0)
            return 0;
        // Cap phat vung dem cho text
        text = (char *)malloc(length);
        // Doc text va in ra man hinh
        read(client_socket, text, length);
        printf("%s\n", text);
        // Giai phong vung dem
        free(text);
        // Neu Client gui message "quit", Thoat
        if (!strcmp(text, "quit"))
            return 1;
    }
}
int main(int argc, char *const argv[])
{
    const char *const socket_name = argv[1];
    int socket_fd;
    struct sockaddr_un name;
    int client_sent_quit_message;
    /* Tao socket */
    socket_fd = socket(PF_LOCAL, SOCK_STREAM, 0);
    /* Chi ra day la server */
    name.sun_family = AF_LOCAL;
    strcpy(name.sun_path, socket_name);
    bind(socket_fd, &name, SUN_LEN(&name));
    /* Lang nghe ket noi*/
    listen(socket_fd, 5);
    /* Lap lai chap nhan ket noi, xoay quanh server lien quan den client. Tiep tuc cho
    den khi client gui message "quit" */
    do
    {
        struct sockaddr_un client_name;
        socklen_t client_name_len;
        int client_socket_fd;
        /* Chap nhan ket noi */
        client_socket_fd = accept(socket_fd, &client_name, &client_name_len);
        /* Dieu khien ket noi */
        client_sent_quit_message = server(client_socket_fd);
        /* Dong va ket thuc ket noi */
        close(client_socket_fd);
    } while (!client_sent_quit_message);
    /* Xoa file socket */
    close(socket_fd);
    unlink(socket_name);
    return 0;
}