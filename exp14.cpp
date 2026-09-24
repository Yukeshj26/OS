#define EXP14_PROGRAM 1

#if EXP14_PROGRAM == 1
#include <stdio.h>

int main()
{
    int start, length, i;

    printf("Enter Starting Block: "); scanf("%d", &start);
    printf("Enter File Length (Number of Blocks): "); scanf("%d", &length);

    printf("\nAllocated Blocks:\n");
    for(i = 0; i < length; i++)
        printf("%d ", start + i);

    printf("\n");
    return 0;
}
#elif EXP14_PROGRAM == 2
#include <stdio.h>

int main()
{
    int n, blocks[20], i;

    printf("Enter Number of Blocks: "); scanf("%d", &n);
    printf("Enter Block Numbers:\n");
    for(i = 0; i < n; i++) scanf("%d", &blocks[i]);

    printf("\nLinked Allocation:\n");
    for(i = 0; i < n - 1; i++)
        printf("%d --> ", blocks[i]);

    printf("%d --> NULL\n", blocks[n - 1]);

    return 0;
}
#endif
