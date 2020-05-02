
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
extern int errno;
int main()
{

	int file_descripter = open("sample.txt", O_RDONLY | O_CREAT);

	printf("file descripter = %d\n", file_descripter);

	if (file_descripter ==-1)
	{
		printf("Error Number % d\n", errno);

		perror("Program");
	}
	return 0;
}
