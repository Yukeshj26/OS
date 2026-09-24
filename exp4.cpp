#define EXP4_PROGRAM 1

#if EXP4_PROGRAM == 1
#include<stdio.h>

int main()
{
    int n, i;
    int bt[20], wt[20], tat[20];
    float avg_wt=0, avg_tat=0;

    printf("Enter Number of Processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter Burst Time for P%d: ",i+1);
        scanf("%d",&bt[i]);
    }

    wt[0]=0;

    for(i=1;i<n;i++)
        wt[i]=wt[i-1]+bt[i-1];

    for(i=0;i<n;i++)
    {
        tat[i]=wt[i]+bt[i];
        avg_wt+=wt[i];
        avg_tat+=tat[i];
    }

    printf("\nProcess\tBT\tWT\tTAT\n");

    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]);

    printf("\nAverage Waiting Time = %.2f",avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n",avg_tat/n);

    return 0;
}
#elif EXP4_PROGRAM == 2
#include<stdio.h>

int main()
{
    int n, i, j, temp;
    int bt[20], wt[20], tat[20];
    float avg_wt=0, avg_tat=0;

    printf("Enter Number of Processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter Burst Time for P%d: ",i+1);
        scanf("%d",&bt[i]);
    }

    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(bt[i] > bt[j])
            {
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
            }

    wt[0] = 0;

    for(i=1;i<n;i++)
        wt[i] = wt[i-1] + bt[i-1];

    printf("\nProcess\tBT\tWT\tTAT\n");

    for(i=0;i<n;i++)
    {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);

    return 0;
}
#elif EXP4_PROGRAM == 3
#include<stdio.h>

int main()
{
    int n, i, j, temp;
    int bt[20], pr[20], wt[20], tat[20];
    float avg_wt=0, avg_tat=0;

    printf("Enter Number of Processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nEnter Burst Time for P%d: ",i+1);
        scanf("%d",&bt[i]);
        printf("Enter Priority for P%d: ",i+1);
        scanf("%d",&pr[i]);
    }

    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(pr[i] > pr[j])
            {
                temp=pr[i]; pr[i]=pr[j]; pr[j]=temp;
                temp=bt[i]; bt[i]=bt[j]; bt[j]=temp;
            }

    wt[0] = 0;

    for(i=1;i<n;i++)
        wt[i] = wt[i-1] + bt[i-1];

    printf("\nProcess\tPriority\tBT\tWT\tTAT\n");

    for(i=0;i<n;i++)
    {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
        printf("P%d\t%d\t\t%d\t%d\t%d\n",i+1,pr[i],bt[i],wt[i],tat[i]);
    }

    avg_wt /= n; avg_tat /= n;
    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}
#elif EXP4_PROGRAM == 4
#include<stdio.h>

int main()
{
    int n, tq, i;
    int bt[20], rem_bt[20];
    int wt[20], tat[20];
    int time=0, done;
    float avg_wt=0, avg_tat=0;

    for(i=0;i<20;i++) wt[i]=0;

    printf("Enter Number of Processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter Burst Time for P%d: ",i+1);
        scanf("%d",&bt[i]);
        rem_bt[i]=bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    do {
        done=1;
        for(i=0;i<n;i++)
        {
            if(rem_bt[i]>0)
            {
                done=0;
                if(rem_bt[i]>tq) { time+=tq; rem_bt[i]-=tq; }
                else { time+=rem_bt[i]; wt[i]=time-bt[i]; rem_bt[i]=0; }
            }
        }
    } while(!done);

    printf("\nProcess\tBT\tWT\tTAT\n");

    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avg_wt+=wt[i];
        avg_tat+=tat[i];
        printf("P%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);

    return 0;
}
#endif
