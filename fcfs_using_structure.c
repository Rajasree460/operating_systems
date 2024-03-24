/* fcfs scheduling(struct) */
#include <stdio.h>
#include <stdlib.h>
struct fcfs {
 int pid, btime, wtime, ttime;
};
int main() {
 int i, n;
 int totwtime = 0, totttime = 0;
 printf("\nFCFS scheduling..\n");
 printf("Enter the number of processes: ");
 scanf("%d", &n);
 struct fcfs p[n]; //struct fcfs p[10]; declares an array named p that can hold n elements, and each 
element is of the struct fcfs type.
 for (i = 0; i < n; i++) {
 //for the 0'th index of the structure array the process id(pid)=1(0+1)
 p[i].pid = i + 1; // Process IDs start from 1
 printf("\nBurst time of process %d: ", p[i].pid);
 scanf("%d", &p[i].btime);
 }
 // Calculate waiting time and turnaround time
 for (i = 0; i < n; i++) { //index of struct arry p is starting from 1
 if (i > 0) {
 p[i].wtime = p[i - 1].wtime + p[i - 1].btime;
 } else {
 p[i].wtime = 0; //for process residing at 1st id(pid=1)
 }
 p[i].ttime = p[i].wtime + p[i].btime; //for process residing at 1st id(pid=1)(tt=bt)
 totwtime += p[i].wtime;
 totttime += p[i].ttime;
 }
 printf("\nProcesses\tBurst\tWaiting\tTurnaround\n");
 for (i = 0; i < n; i++) {
 printf("%d\t\t%d\t%d\t%d\n", p[i].pid, p[i].btime, p[i].wtime, p[i].ttime);
 }
 printf("\nAverage Waiting time = %.6f", (float)totwtime / n);
 printf("\nAverage Turnaround time = %.6f\n", (float)totttime / n);
 return 0;
}
