//distinguish between parent & child process
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#define MAX_COUNT 5
#define BUF_SIZE 100

void main(){
	int i;
	pid_t pid;
	char buf[BUF_SIZE];
	
	fork();
	pid=getpid();
	
	for(i=1;i<=MAX_COUNT;i++){
		sprintf(buf,"this line is from pid:%d, value:%d\n",pid,i);
		write(1,buf,strlen(buf));
	}
}
