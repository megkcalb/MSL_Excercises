#include <ubacipc/Semaphore.h>
#include <sys/signal.h>
#include <sys/types.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

Semaphore s;
//block going to be used by the process
void critical_resource()
{
     	cout << "process " << getpid() << " is using now " << endl;  
}


void process_for_write()
{
    int i;
    while(1) {
        //locking the critical source
        i = s.semaphoreLock(0);
        if(i == 0) {
            cout <<"Resource locked......." << endl;
            critical_resource();
            //Unlocking
            s.semaphoreUnLock(0);
            cout << "Resource unlocked......." << endl;
        }
        sleep(1);
    }
}

void process_exit(int exitNum){
    s.removeSemaphore();
    exit(1);
}

void init_process_one()
{
    if(fork() == 0) {
        cout << " process id : " << getpid() << endl;   
        signal(SIGINT, process_exit);
	process_for_write();
        while(1);
    }
}

void init_process_two()
{
    if(fork() == 0) {
        cout << " process id : " << getpid() << endl;
        signal(SIGINT, process_exit);
	process_for_write();
        while(1);
    }
}

int main()
{
    signal(SIGINT, SIG_DFL);
    signal(SIGINT, process_exit);
    s.initSemaphore(2000, 1);
    s.setSemaphoreValue();
    init_process_one();
    init_process_two();
    while(1);
    return 0;
}
