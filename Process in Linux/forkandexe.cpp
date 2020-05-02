#include <iostream> 
#include <sys/wait.h>
#include <unistd.h>
#include<stdio.h>

using namespace std;
/*
wait(NULL) will block parent process until any of its children has finished. If child terminates before parent process reaches wait(NULL) then the child process turns to a zombie process until its parent waits on it and its released from memory.

    fork() returns the process identifier (pid) of the child process in the parent, and
    fork() returns 0 in the child.

    *fork makes the child ihave idetocal adr space as parent



*/

int main(){
    pid_t pid=fork();

    if(pid==0){
        //for(long long i=0; i<10000000; i++);
        printf("hello i am the child process\n");
        execlp("/bin/ls", "ls", NULL);
    }
    else{
        printf("parent process here");
    }



    return 0;
}