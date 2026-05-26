#include <stdio.h>

struct Process {
    int pid;        // Process ID
    int bt;         // Burst Time
    int rt;         // Remaining Time
    int wt;         // Waiting Time
    int tat;        // Turnaround Time
};

int main() {
    int n, quantum, i, time = 0, done = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter burst time for process %d: ", p[i].pid);
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt;
        p[i].wt = 0;
        p[i].tat = 0;
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    while (done < n) {
        for (i = 0; i < n; i++) {
            if (p[i].rt > 0) {
                if (p[i].rt > quantum) {
                    time += quantum;
                    p[i].rt -= quantum;
                } else {
                    time += p[i].rt;
                    p[i].wt = time - p[i].bt;
                    p[i].rt = 0;
                    p[i].tat = p[i].wt + p[i].bt;
                    done++;
                }
            }
        }
    }

    float avgWT = 0, avgTAT = 0;
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].bt, p[i].wt, p[i].tat);
        avgWT += p[i].wt;
        avgTAT += p[i].tat;
    }

    avgWT /= n;
    avgTAT /= n;

    printf("\nAverage Waiting Time: %.2f", avgWT);
    printf("\nAverage Turnaround Time: %.2f\n", avgTAT);

    return 0;
}
