/*getpid()*/
#include <stdio.h>
#include <unistd.h>
int main( void ) {
printf( "The process identifier (pid) of the parent process is %d\n", (int)getpid() );
int pid = fork();
if ( pid == 0 ) {
printf( "After the fork, the process identifier (pid) "
 "of the child is %d\n", (int)getpid() );
} else {
printf( "After the fork, the process identifier (pid) "
 "of the parent is still %d\n - fork() returned %d\n",
 (int)getpid(), pid );
}
return 0;
}
