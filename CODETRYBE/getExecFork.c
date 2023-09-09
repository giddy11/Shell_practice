#include "main.h"


int main()
{
	char *_getline[] = {"/bin/ls", "-l", NULL};
	int exeRV, wait_status, i;
	pid_t pid;

	printf("Before calling Execve\n");

	for (i = 0; i < 5; i++)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Error creating a new process");
			return (-1);
		}

		if (pid == 0)
		{
			exeRV = execve(_getline[0], _getline, NULL);
			if (exeRV == -1)
			{
				perror("Error ");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&wait_status);
			printf("Child[%d] and PID is %u\n", i, pid);
			printf("Parent has been called with PPID: %u\n", getppid());
		}
	}

	return (0);
}
