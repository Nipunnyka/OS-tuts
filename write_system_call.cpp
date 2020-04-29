#include<stdlib.h>
#include<stdio.h>
#include <fcntl.h>
#include<string>
#include<cstring>
#include <unistd.h>
main()
{
int siz;

int file_descripter = open("sample.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
if (file_descripter < 0)
{
	perror("r1");
	exit(1);
}

siz = write(file_descripter, "hello world\n", strlen("hello world\n"));

printf("called write(% d, \"hello world\\n\", %d)."
	" It returned %d\n", file_descripter, strlen("hello world\n"), siz);

close(file_descripter);
}
