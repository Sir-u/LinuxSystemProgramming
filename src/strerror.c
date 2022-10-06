#include <stdio.h>
#include <errno.h>
#include <string.h>

void ListErrorMsg()
{
	int i = 0;
	char *errmsg;
	
	printf("== Error Message List ==\n");
	for(i = 0; i < 45; i++)
	{
		errmsg = strerror(i);
		printf("<%d>:%s\n", i, errmsg);
	}
}

int main(void)
{
	FILE * fp;

	ListErrorMsg();

	printf("\nPrint error message from opening a non-existent file.\n");
	fp = fopen("noexist.txt", "rt");
	if (fp == NULL)
	{
		perror("file not existed");
		printf("%d: %s\n", errno, strerror(errno));
		return 0;
	}
	fclose(fp);
	return 0;
}