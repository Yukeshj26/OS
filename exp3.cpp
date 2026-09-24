#define EXP3_PROGRAM 1

#if EXP3_PROGRAM == 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    pid = fork();

    if(pid < 0)
    {
        printf("Fork Failed\n");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("\nCHILD PROCESS");
        printf("\nChild PID : %d", getpid());
        printf("\nParent PID : %d\n", getppid());
        exit(0);
    }
    else
    {
        wait(NULL);
        printf("\nPARENT PROCESS");
        printf("\nParent PID : %d", getpid());
        printf("\nParent's Parent PID : %d\n", getppid());
    }

    return 0;
}
#elif EXP3_PROGRAM == 2
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;

    fd = open("sample.txt", O_RDONLY);

    if(fd < 0)
    {
        printf("File Opening Failed\n");
        return 1;
    }

    printf("File Opened Successfully\n");

    close(fd);

    printf("File Closed Successfully\n");

    return 0;
}
#endif
