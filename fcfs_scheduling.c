#include <stdio.h>

int main()
{
    int pid[4] = {1,2,3,4};
    int AT[4] = {0,8,3,5};
    int BT[4] = {7,3,4,6};
    int CT[4], TAT[4], WT[4], RT[4];
    int i, j, temp;
    int n = 4;

    float avgTAT = 0, avgWT = 0, avgRT = 0;

    // Sort according to Arrival Time
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(AT[i] > AT[j])
            {
                temp = AT[i];
                AT[i] = AT[j];
                AT[j] = temp;

                temp = BT[i];
                BT[i] = BT[j];
                BT[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // Completion Time
    CT[0] = AT[0] + BT[0];

    for(i=1;i<n;i++)
    {
        if(CT[i-1] < AT[i])
            CT[i] = AT[i] + BT[i];
        else
            CT[i] = CT[i-1] + BT[i];
    }

    // Calculate TAT, WT, RT
    for(i=0;i<n;i++)
    {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
        RT[i] = WT[i];

        avgTAT += TAT[i];
        avgWT += WT[i];
        avgRT += RT[i];
    }

    // Display table
    printf("PID\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i], AT[i], BT[i], CT[i], TAT[i], WT[i], RT[i]);
    }

    // Display averages
    printf("\nAverage Turnaround Time = %.2f", avgTAT/n);
    printf("\nAverage Waiting Time = %.2f", avgWT/n);
    printf("\nAverage Response Time = %.2f\n", avgRT/n);

    return 0;
}
