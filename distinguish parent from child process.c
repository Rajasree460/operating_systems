/*distinguish parent from child process*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX_COUNT 5
void ChildProcess(); /* child process prototype */
void ParentProcess(); /* parent process prototype */
void main()
{
 pid_t pid;
 pid = fork();
 if (pid == 0) 
 ChildProcess();
 else 
 ParentProcess();
}
void ChildProcess()
{
 int i;
 for (i = 1; i <= MAX_COUNT; i++)
 printf(" This line is from child, value = %d\n", i);
 printf(" *** Child process is done ***\n");
}
void ParentProcess()
{
 int i;
 for (i = 1; i <= MAX_COUNT; i++)
 printf("This line is from parent, value = %d\n", i);
 printf("*** Parent is done ***\n");
}
