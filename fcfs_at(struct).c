/* fcfs scheduling using at(struct) */
#include <stdio.h>
#include <stdlib.h>
struct fcfs {
 int pid, btime, wtime, ttime, atime;
};
int main() {
 int i, n;
 int totwtime = 0, totttime = 0;
 printf("\n FCFS Scheduling\n");
 printf("Enter the number of processes: ");
 scanf("%d", &n);
 struct fcfs p[n]; //struct fcfs p[10]; declares an array named p that can hold n elements, and each 
element is of the struct fcfs type.
 for (i = 0; i < n; i++) {
 p[i].pid = i + 1;
 printf("\nEnter burst time of process %d: ", p[i].pid);
 scanf("%d", &p[i].btime);
 printf("Enter arrival time of process %d: ", p[i].pid);
 scanf("%d", &p[i].atime);
 }
 // Sort the processes by their arrival times
 for (i = 0; i < n ; i++) {
 for (int j = i+1; j < n ; j++) {
 if (p[i].atime > p[j].atime) {
 struct fcfs temp = p[i];
 p[i] = p[j];
 p[j] = temp;
 }
 }
 }
 // Calculate waiting time and turnaround time
 for (i = 0; i < n; i++) { //index of struct arry p is starting from 0 but pid starts from 1
 if (i > 0) {
 p[i].wtime = p[i - 1].wtime + p[i - 1].btime - p[i].atime;
 if (p[i].wtime < 0) {
 p[i].wtime = 0; //if the prv waiting time is (-)ve then it becomes 0 as waiting time cant be 
negative 
 }
 } else {
 p[i].wtime = 0; // for the first process
 }
 p[i].ttime = p[i].wtime + p[i].btime; //as bt+wt==tt
 totwtime += p[i].wtime;
 totttime += p[i].ttime;
 }
 printf("\nProcesses\tBurst\tWaiting\tTurnaround\tArrival\n");
 for (i = 0; i < n; i++) {
 printf("%d\t\t%d\t%d\t%d\t\t%d\n", p[i].pid, p[i].btime, p[i].wtime, p[i].ttime, p[i].atime);
 }
 printf("\nAverage Waiting time = %f", (float)totwtime / n);
 printf("\nAverage Turnaround time = %f\n", (float)totttime / n);
 return 0;
}
