#include <stdio.h>

struct Process {
    int pid;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

// Function to sort processes by priority (lower number = higher priority)
void sortByPriority(struct Process p[], int n) {
    int i, j;
    struct Process temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].priority > p[j].priority) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

// Function to calculate waiting time and turnaround time
void calculateTimes(struct Process p[], int n) {
    int i;

    p[0].waiting_time = 0;

    for (i = 1; i < n; i++) {
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time;
    }

    for (i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }
}

// Function to display process details
void display(struct Process p[], int n) {
    int i;
    float total_wt = 0, total_tat = 0;

    printf("\nPID\tBT\tPriority\tWT\tTAT\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t\t%d\t%d\n",
               p[i].pid,
               p[i].burst_time,
               p[i].priority,
               p[i].waiting_time,
               p[i].turnaround_time);

        total_wt += p[i].waiting_time;
        total_tat += p[i].turnaround_time;
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
}

// Function to display Gantt Chart
void ganttChart(struct Process p[], int n) {
    int i, time = 0;

    printf("\nGantt Chart:\n");

    // Top bar
    printf(" ");
    for (i = 0; i < n; i++) {
        printf("--------");
    }

    printf("\n|");
    for (i = 0; i < n; i++) {
        printf("  P%d   |", p[i].pid);
    }

    printf("\n ");
    for (i = 0; i < n; i++) {
        printf("--------");
    }

    printf("\n0");
    for (i = 0; i < n; i++) {
        time += p[i].burst_time;
        printf("      %d", time);
    }
    printf("\n");
}

int main() {
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nEnter Burst Time for P%d: ", i + 1);
        scanf("%d", &p[i].burst_time);

        printf("Enter Priority for P%d (lower value = higher priority): ", i + 1);
        scanf("%d", &p[i].priority);
    }

    // Sort processes based on priority
    sortByPriority(p, n);

    // Calculate times
    calculateTimes(p, n);

    // Display results
    display(p, n);

    // Display Gantt Chart
    ganttChart(p, n);

    return 0;
}
