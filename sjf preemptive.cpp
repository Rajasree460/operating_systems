//Preemptive SJF scheduling
#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

typedef struct {
    int pid, bt, wt, tt, at, remaining_time;
} sp;

int main() {
    int i, j, n, tbm = 0, towt = 0, tott = 0;

    printf("Preemptive SJF scheduling with arrival time\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    sp *p, t;
    p = (sp *)malloc(n * sizeof(sp));

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nEnter burst time of process id %d: ", p[i].pid);
        scanf("%d", &p[i].bt);
        printf("Enter arrival time of process id %d: ", p[i].pid);
        scanf("%d", &p[i].at);
        p[i].remaining_time = p[i].bt;
    }

    // Sort processes by their arrival time
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }

    printf("\nProcess scheduling\n");
    printf("Process\tBurst\tArrival\tWaiting\tTurnaround\n");

    int current_time = 0;

    while (1) {
        int idx = -1, min_bt = INT_MAX;

        // Find the process with the shortest remaining burst time at the current time
        for (i = 0; i < n; i++) {
            if (p[i].at <= current_time && p[i].remaining_time > 0 && p[i].remaining_time < min_bt) {
                min_bt = p[i].remaining_time;
                idx = i;
            }
        }

        if (idx == -1) {
            // No processes remaining
            break;
        }

        // Update current time
        current_time++;

        // Update waiting and turnaround times
        if (p[idx].remaining_time == p[idx].bt) {
            // First time the process is executed
            p[idx].wt = current_time - p[idx].at - 1;
        }

        // Update remaining time
        p[idx].remaining_time--;

        // Check if the process is completed
        if (p[idx].remaining_time == 0) {
            p[idx].tt = current_time - p[idx].at;  //when p[idx].remaining_time,then current_time==p[i].bt(idx==i)
            tbm += p[idx].bt;
            towt += p[idx].wt;
            tott += p[idx].tt;

            printf("%d\t\t%d\t%d\t%d\t%d\n", p[idx].pid, p[idx].bt, p[idx].at, p[idx].wt, p[idx].tt);
        }
    }

    printf("\nAverage waiting time: %.2f\n", (float)towt / n);
    printf("Average turnaround time: %.2f\n", (float)tott / n);

    free(p);
}

