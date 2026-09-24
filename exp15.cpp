#define EXP15_PROGRAM 1

#if EXP15_PROGRAM == 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int req[20], n, head, i;
    int seek = 0;

    printf("Enter Number of Requests: "); scanf("%d",&n);
    printf("Enter Request Queue:\n"); for(i=0;i<n;i++) scanf("%d",&req[i]);
    printf("Enter Initial Head Position: "); scanf("%d",&head);

    for(i=0;i<n;i++)
    {
        seek += abs(req[i] - head);
        head = req[i];
    }

    printf("Total Head Movement = %d\n",seek);
    return 0;
}
#elif EXP15_PROGRAM == 2
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int req[20], visited[20]={0};
    int n, head, i, count=0, seek=0, index, min, distance;

    printf("Enter Number of Requests: "); scanf("%d",&n);
    printf("Enter Request Queue:\n"); for(i=0;i<n;i++) scanf("%d",&req[i]);
    printf("Enter Initial Head Position: "); scanf("%d",&head);

    while(count<n)
    {
        min=9999;
        for(i=0;i<n;i++)
            if(!visited[i])
            {
                distance=abs(req[i]-head);
                if(distance<min) { min=distance; index=i; }
            }
        seek+=min;
        head=req[index];
        visited[index]=1;
        count++;
    }

    printf("Total Head Movement = %d\n",seek);
    return 0;
}
#elif EXP15_PROGRAM == 3
#include<stdio.h>

int main()
{
    int disk_size = 200;
    int head = 53;

    printf("SCAN Disk Scheduling\n");
    printf("Initial Head Position : %d\n", head);

    printf("Head moves towards higher cylinders,\n");
    printf("then reverses direction.\n");

    return 0;
}
#elif EXP15_PROGRAM == 4
#include<stdio.h>

int main()
{
    int head = 53;

    printf("C-SCAN Disk Scheduling\n");
    printf("Initial Head Position : %d\n", head);
    printf("Head moves in one direction.\n");
    printf("After reaching the end, it returns to the beginning.\n");

    return 0;
}
#endif
