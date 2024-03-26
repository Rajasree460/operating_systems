//rr with at
#include <stdio.h>

int main() {
    int n;
    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);

    int wt = 0, tt = 0;
    int arrt[n],burst[n], rburst[n];
    int q;

    for (int i = 0; i < n; i++) {
        printf("\nEnter Burst Time for Process %d: ", i + 1);
        scanf("%d", &burst[i]);
        printf("\nEnter arrival Time for Process %d: ", i + 1);
        scanf("%d", &arrt[i]);
        rburst[i] = burst[i];
    }

    printf("Enter Time Slice (Quantum): ");
    scanf("%d", &q);

    int total_time = 0;
    int completed_processes = 0;

    printf("\nProcess ID\tBurst Time\tArrival Time\tTurnaround Time\tWaiting Time\n");

    int curp = 0;
    
    while (completed_processes < n) {
        if (rburst[curp] > 0) {
            int exet;
            if (rburst[curp] > q) {
                exet = q;
            } else {
                exet = rburst[curp];
            }

            total_time += exet;
            rburst[curp] -= exet;

            if (rburst[curp] == 0) {
                completed_processes++;

                int turnaround_time = total_time-arrt[curp];
                int waiting_time = turnaround_time - burst[curp];

                printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", curp + 1, burst[curp], arrt[curp],turnaround_time, waiting_time);

                wt += waiting_time;
                tt += turnaround_time;
            }

            curp = (curp + 1) % n;
        } else {
            curp = (curp + 1) % n;
        }
    }

    float avg_waiting_time = (float)wt / n;
    float avg_turnaround_time = (float)tt / n;

    printf("\nAverage Waiting Time: %f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %f\n", avg_turnaround_time);
}

