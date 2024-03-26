/*printing process id for parent & child*/
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#define MAX_COUNT 5
#define BUF_SIZE 100
void main(){
	pid_t pid;  //no need of pid_t,basically it is showing the use of #include<sys/types.h> ,we can take int instead of pid_t
	int i;
	char buf[BUF_SIZE];
	fork();
	pid=getpid();
	for(i=1;i<=MAX_COUNT;i++){
		sprintf(buf,"this line is from pid:%d,value=%d\n",pid,i);
		write(1,buf,strlen(buf));
	}
}
