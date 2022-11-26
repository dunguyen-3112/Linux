#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

/* Ghi TEXT len file socket. Chi ra boi SOCKET_FD */
void write_text(int socket_fd, const char *text)
{
    /* Ghi so byte cua string, bao gom gia tri ket thuc NUL */
    int length = strlen(text) + 1;
    write(socket_fd, &length, sizeof(length));
    /* Ghi chuoi */
    write(socket_fd, text, length);
}

int main(int argc, char *const argv[])
{
    const char *const socket_name = argv[1];
    const char *const message = argv[2];
    int socket_fd;
    struct sockaddr_un name;
    /* Tao socket */
    socket_fd = socket(PF_LOCAL, SOCK_STREAM, 0);
    /* Luu ten server trong dia chi socket */
    name.sun_family = AF_LOCAL;
    strcpy(name.sun_path, socket_name);

    /* Ket noi den socket */
    connect(socket_fd, &name, SUN_LEN(&name));
    /* Ghi text tren command line den socket*/
    write_text(socket_fd, message);
    close(socket_fd);
    return 0;
}