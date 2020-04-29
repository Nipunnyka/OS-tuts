#include<stdio.h>
#include <fcntl.h>
#include<iostream>
#include<stdlib.h>
#include <unistd.h>
int main()
{
    int file_descripter_1 = open("os.txt", O_RDONLY| O_CREAT);
    if (file_descripter_1 < 0)
    {
        perror("c1");
        exit(1);
    }
    printf("recently opened fd = % d\n", file_descripter_1);


    if (close(file_descripter_1) < 0)
    {
        perror("c1");
        exit(1);
    }
    printf("closed this fd.\n");
    printf("Now opening another file descripter as the previous one is pointing to NULL \n");


    int file_descripter_2 = open("sample.txt", O_RDONLY, 0);

    printf("fd2 = % d\n", file_descripter_2);
    exit(0);
}
