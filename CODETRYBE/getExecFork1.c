#include "main.h"


int main(int ac, char **argv)
{
	char *store = NULL, *_getline = *argv;
	size_t size = 0;
	ssize_t r_val;
	pid_t pid;
	int running = 1, exeRV, wait_status;

	while(running)
	{
		printf("#cisfun$ ");
		r_val = getline(&store, &size, stdin);

		if (r_val == -1)
		{
			free(store);
			exit(0);
		}

		// Remove the trailing newline character from the input
		if (store[r_val - 1] == '\n')
			store[r_val - 1] = '\0';

		pid = fork();
		if (pid == -1)
		{
			perror("Error creating a new process");
			return (-1);
		}

		if (pid == 0)
		{
			// look at execvp which solves this
			char *args[] = {store, NULL};
			exeRV = execve(args[0], args, NULL);
			if (exeRV == -1)
			{
				perror("Error ");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&wait_status);
			printf("Child PID is %u\n", pid);
			printf("Parent has been called with PPID: %u\n", getppid());
		}

	}
	free(store);


	return (0);
}
