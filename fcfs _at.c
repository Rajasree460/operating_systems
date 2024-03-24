/* fcfs scheduling using at(array)*/
#include <stdio.h>
#include <stdlib.h>
int main() {
 int i, n;
 int totwtime = 0, totttime = 0;
 printf("\n FCFS Scheduling\n");
 printf("Enter the number of processes: ");
 scanf("%d", &n);
 int pid[n], btime[n], wtime[n], ttime[n], atime[n];
 for (i = 0; i < n; i++) {
 pid[i] = i + 1;
 printf("\nEnter burst time of process %d: ", pid[i]);
 scanf("%d", &btime[i]);
 printf("Enter arrival time of process %d: ", pid[i]);
 scanf("%d", &atime[i]);
 }
 // Sort the processes by their arrival times
 for (i = 0; i < n; i++) {
 for (int j = i + 1; j < n; j++) {
 if (atime[i] > atime[j]) {
 int temp = atime[i];
 atime[i] = atime[j];
 atime[j] = temp;
 temp = btime[i];
 btime[i] = btime[j];
 btime[j] = temp;
 temp = pid[i];
 pid[i] = pid[j];
 pid[j] = temp;
 }
 }
 }
 // Calculate waiting time and turnaround time
 for (i = 0; i < n; i++) {
 if (i > 0) {
 wtime[i] = wtime[i - 1] + btime[i - 1] - atime[i];
 if (wtime[i] < 0) {
 wtime[i] = 0; // If the previous waiting time is negative, set it to 0 as waiting time can't be 
negative
 }
 } else {
 wtime[i] = 0; // For the first process
 }
 ttime[i] = wtime[i] + btime[i];
 totwtime += wtime[i];
 totttime += ttime[i];
 }
 printf("\nProcesses\tBurst\tWaiting\tTurnaround\tArrival\n");
 for (i = 0; i < n; i++) {
 printf("%d\t\t%d\t%d\t%d\t\t%d\n", pid[i], btime[i], wtime[i], ttime[i], atime[i]);
 }
 printf("\nAverage Waiting time = %f", (float)totwtime / n);
 printf("\nAverage Turnaround time = %f\n", (float)totttime / n);
 return 0;
}
