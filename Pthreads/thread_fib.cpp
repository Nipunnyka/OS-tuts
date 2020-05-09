#include <pthread.h>
//#include <libpthread.a>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int sum[100]={0};

void * fib(void * param);

int main(int argc, char *argv[]){
	if(argc!=2){
		printf("usage: ./a.out <pos number>");
		return -1;
	}
	if (argv[1]<0){
		cout<<"only positive numbers are allowed"<<endl;
		return -1;
	}
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&tid, &attr, fib, argv[1]);
	pthread_join(tid, NULL); //wait for thread to finish
	
	//print the seq
	for(int i=0; i<atoi(argv[1]); i++){	
	cout<<sum[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}

void *fib (void * param){
	int n=atoi((char *)param);
	int i, a=0, b=1;
	for(i=0; i<n; i++){
		sum[i]=a+b;
		a=b;
		b=sum[i];
	}
	pthread_exit(0); //free the thread
}
