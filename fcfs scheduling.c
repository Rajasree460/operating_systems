/* fcfs scheduling(array) */
#include <stdio.h>
#include <stdlib.h>
int main() {
 int i, n; //i+1=pid as i=0
 printf("\nFCFS scheduling..\n");
 printf("Enter the number of processes: ");
 scanf("%d", &n);
 int burst_time[n]; // Array to store burst times
 int waiting_time[n]; // Array to store waiting times
 int turnaround_time[n]; // Array to store turnaround times
 int totwtime = 0, totttime = 0;
 
 // if (n > 10) {
 // printf("Error: Maximum number of processes allowed is 10.\n");
 // return 1;
 // }
 for (i = 0; i < n; i++) {
 printf("\nEnter burst time for process %d: ", i + 1);
 scanf("%d", &burst_time[i]);
 }
 // Calculate waiting time and turnaround time
 waiting_time[0] = 0; //as it is the 1st process(no at here)
 turnaround_time[0] = burst_time[0]; //bt is always equal to tt for 1st process
 totttime = turnaround_time[0]; //total tt of 1st process=tt of 1st process
 for (i = 1; i < n; i++) {
 waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
 turnaround_time[i] = waiting_time[i] + burst_time[i];
 totwtime += waiting_time[i];
 totttime += turnaround_time[i];
 }
 printf("\nProcesses\tBurst\tWaiting\tTurnaround\n");
 for (i = 0; i < n; i++) {
 printf("%d\t\t%d\t%d\t%d\n", i + 1, burst_time[i], waiting_time[i], turnaround_time[i]);
 }
 printf("\nAverage Waiting time = %f", (float)totwtime / n);
 printf("\nAverage Turnaround time = %f\n", (float)totttime / n);
 return 0;
}
