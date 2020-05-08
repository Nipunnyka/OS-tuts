#include <bits/stdc++.h>
#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <sys/types.h> 
#include <string.h> 
#include <stdlib.h> 
#include <sys/shm.h>
#include <sys/stat.h>
using namespace std;
#define MAX_SEQ 10

typedef struct{
	int seq[MAX_SEQ];
	int size;
}fib;


int main(){
	int n;
	cin>>n;
	
	pid_t p;
	
	p=fork();
	
	if(p<0){
		cout<<"failed to create a child"<<endl;
		return -1;
	}
	else if(p==0){
		//child
		int a=0, b=1;
		while(n>0){
			
			int t=a+b;
			cout<<t<<" ";
			a=b;
			b=t;
			n--;
		}
		return 0;
	}
	
	else{
		wait(NULL);
		cout<<endl<<"child has completed"<<endl;
	}

	
	
	return 0;
}
