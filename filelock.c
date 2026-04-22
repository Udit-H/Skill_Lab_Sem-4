#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <string.h>

int main()
{

    int fd;
    struct flock lock;

    fd = open("testfile.txt", O_WRONLY | O_CREAT, 0644);

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("Trying to acquire lock\n");

    fcntl(fd, F_SETLKW, &lock);

    write(fd, "Writing with file lock\n", 23);
    sleep(10);

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Lock released\n");
    close(fd);
    return 0;
}