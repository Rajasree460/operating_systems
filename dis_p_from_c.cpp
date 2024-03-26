//distinguish parent from child
#include<stdio.h>
#include<unistd.h>
#define MAX_COUNT 5
void child_process();
void parent_process();

void main(){
	int f_val=fork();
	if(f_val==0){
		child_process();
	}
	else{
		parent_process();
	}
}

void child_process(){
	for(int i=1;i<=MAX_COUNT;i++){
		printf("this line is from child, value:%d\n",i);
	}
	printf("**child process ends**\n");
}

void parent_process(){
	for(int i=1;i<=MAX_COUNT;i++){
		printf("this line is from parent, value:%d\n",i);
	}
	printf("**parent process ends**\n");
}
