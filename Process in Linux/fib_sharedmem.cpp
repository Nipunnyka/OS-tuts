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
	
	if(n<MAX_SEQ){
		int seg_id=shmget(IPC_PRIVATE, 4096, S_IRUSR | S_IWUSR);
		pid_t p;
	
		p=fork();
		
		if(p<0){
			cout<<"failed to create a child"<<endl;
			return -1;
		}
		else if(p==0){
			//child
			fib *ans=(fib *)shmat(seg_id, NULL, 0);
			int a=0, b=1, i=0;
			while(n>0){
				
				int t=a+b;
				(*ans).seq[i]=t;
				i++;
				a=b;
				b=t;
				n--;
			}
			shmdt(ans);
			return 0;
		}
		
		else{
			wait(NULL);
			fib * ans= (fib *)shmat(seg_id, NULL, 0);
			for(int i=0; i<n; i++)
				cout<<(*ans).seq[i]<<" ";
			cout<<endl<<"child has completed"<<endl;
			shmdt(ans);
		}
		shmctl(seg_id, IPC_RMID, NULL);
	}
	else{
		cout<<"out of bounds";
	}
	

	return 0;
}
