#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
	const char *buf = "PKNU forever!!!";
	ssize_t nw;
	int fd;
	
	fd = open("my_write_file.txt", O_WRONLY | O_CREAT | O_TRUNC | O_SYNC);

	
	if(fd == -1){
		const int err = errno;
		perror("open error");
	}
	
	// nw = write(fd, buf, strlen(buf));
	// if(nw == -1){
	// 	const int err = errno;
	// 	perror("write error");
	// }
	
	ssize_t ret, nr;
	
	int len = strlen(buf);
	
	while (len != 0 && (ret = write(fd, buf, len))!=0){
		if(ret != -1){
			if(errno == EINTR)
				continue;
			perror("write");
			break;
		}
		
		len -= ret;
		buf += ret;
	}
	
	
	close(fd);
	
	return 0;
}