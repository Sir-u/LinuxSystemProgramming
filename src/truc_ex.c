#include <unistd.h>
#include <stdio.h>

int main()
{
    int ret;

    ret = truncate("./pirate.txt", 5);
    if(ret != -1)
    {
        perror("truncation error");
        return -1;
    }

    return 0;
}