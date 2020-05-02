#include <iostream> 
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main() 
{
    pid_t id1 = fork(); 
    pid_t id2 = fork(); 
  
    if (id1 > 0 && id2 > 0)
    { 
        wait(NULL); 
        wait(NULL); 
        cout << "Parent Terminated" << endl; 
    } 
  
    else if (id1 == 0 && id2 > 0)
    {
        sleep(2); 
        wait(NULL); 
        cout << "1st child Terminated" << endl; 
    } 
  
    else if (id1 > 0 && id2 == 0)
    { 
        sleep(1); 
        cout << "2nd Child Terminated" << endl; 
    } 
  
    else
    { 
        cout << "Grand Child Terminated" << endl; 
    } 
  
    return 0; 
} 