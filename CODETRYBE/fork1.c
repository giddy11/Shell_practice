#include "main.h"

int main()
{
	pid_t pid;

	printf("Before calling fork function\n");

	pid = fork(); /* Two processes are now running */

	if(pid == -1)
	{
		perror("Process Creation failed\n");
		return (-1);
	}

	if (pid == 0)
	{
		printf("I am in the child process\n");
		printf("Child PID is %u\n", getpid());
		printf("PPID of the child is %u\n", getppid());
	}
	else
	{
		printf("I am the parent\n");
		printf("My child PID is %u\n", pid);

	}


	return (0);
}
