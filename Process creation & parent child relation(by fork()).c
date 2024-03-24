/*Process creation & parent child relation(fork() system 
call)*/
#include<stdio.h>
#include<unistd.h>
int main(){
 int pr_id;
 if ((pr_id = fork()) == 0)
 printf("\nfrom child with pid=%d, ppid=%d and fork-return value=%d\n", getpid(), getppid(), 
pr_id);
 else if (pr_id >0) 
 printf("\nfrom parent with pid=%d, ppid=%d and fork-return value=%d\n", getpid(), 
getppid(), pr_id);
else
 printf("\nerror in fork pid=%d, ppid=%d and fork-return value=%d\n", getpid(), getppid(), 
pr_id);
}
