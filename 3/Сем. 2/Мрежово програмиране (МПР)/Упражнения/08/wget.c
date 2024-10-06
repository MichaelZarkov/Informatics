#include <sys/socket.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/sendfile.h>
#include <assert.h>
#include <stdio.h>
//#define __DEBUG__ 1

/*
    wget прави get заявка в следния вид: Get  url/file_name и запазва резултата в текущата директория със същото име.
    Тествайте програмата като се намирате в друга директория с wget localhost:4095/file_name, като file_name трябва да
    се намира в същата директория в която е wget.c
*/

void main()
{

    struct sockaddr_in remoteaddr;

    int s = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr = {
        AF_INET,
        htons(4095),
        0

    };

    bind(s, (const struct sockaddr *)&addr, sizeof(const struct sockaddr));

    int file_fd;

    listen(s, 20);

    socklen_t addrlen = sizeof(struct sockaddr);

    int client_fd = accept(s, (struct sockaddr *)&remoteaddr, &addrlen);

    char buffer[1024] = {0};

    recv(client_fd, buffer, 1024, 0);

    char *f = buffer + 5;

    *strchr(f, ' ') = 0;
    file_fd = open( f, O_RDONLY);

    int filesize = lseek(file_fd, 0, SEEK_END);
    lseek(file_fd, 0, SEEK_SET);

    int total_bytessent = 0;

    int sent_bytes;

    while ( sent_bytes= sendfile(client_fd, file_fd, 0, 1024) > 0)
    {
       total_bytessent += sent_bytes;
    }
    
   printf("%d bytes were sent \n", total_bytessent);

   assert(("Not all bytes have been sent, try again", total_bytessent!=filesize));

    close(file_fd);
    close(client_fd);
    close(s);
}