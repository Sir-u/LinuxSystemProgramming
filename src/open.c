#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	int fd;
	fd = open("my_file.txt", O_WRONLY | O_CREAT | O_TRUNC,
			  S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP | S_IRGRP | S_IROTH | S_IWOTH);
	//open(file name, flag, permission)
	
	if (fd == -1){
		const int err = errno;
		perror("open error");
	}
	
	return 0;
}