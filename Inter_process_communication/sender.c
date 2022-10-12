#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>
int main(){
	char buff[100];
	void *shared_memory;
	int shmid;
	shmid=shmget((key_t)2345,1024,0666 | IPC_CREAT);
	printf("Key of shared memory is %d\n",shmid);
	shared_memory=shmat(shmid,NULL,0);
	printf("process attached at %p\n",shared_memory);
	printf("Enter some message \n");
	read(0,buff,100);
	strcpy(shared_memory,buff);
	printf("You wrote : %s\n",(char*)shared_memory);
	return 0;
}

