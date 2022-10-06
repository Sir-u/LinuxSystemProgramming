#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

void wCheck(ssize_t w);
void rCheck(ssize_t r);

int main(int argc, char *argv[])
{
    int fd;
    char hello[10];
    char world[10];
    char my[3] = "My ";
    ssize_t nr, nw;
    int count = 0;

    fd = open("hello.txt", O_RDWR);
    
    if(fd == -1){
        const int err = errno;
        perror("open error");
    }

    nr = pread(fd, hello, 6, 0);
    rCheck(nr);
    nr = pread(fd, world, 7, 6);
    rCheck(nr);
    nw = write(fd, hello, 6);
    wCheck(nr);
    nw = write(fd, my, 3);
    wCheck(nr);
    nw = write(fd, world, 6);
    wCheck(nr);
    
    close(fd);
    return 0;
}

void wCheck(ssize_t w)
{
    if(w == -1){
        const int err = errno;
        perror("write error");
    }
}

void rCheck(ssize_t r)
{
    if(r == -1){
        const int err = errno;
        perror("read error");
    }
}