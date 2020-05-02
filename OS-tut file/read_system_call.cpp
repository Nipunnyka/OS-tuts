#include<stdlib.h>
#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
int file_descripter, siz;
char *str = (char *) calloc(100, sizeof(char));

file_descripter = open("os.txt", O_RDONLY);
if (file_descripter < 0) { perror("r1"); exit(1); }

siz = read(file_descripter, str, 10);
printf("called read(% d, c, 10). returned that"
		" %d bytes were read.\n", file_descripter, siz);
str[siz] = '\0';
printf("Those bytes are as follows: % s\n", str);
}
