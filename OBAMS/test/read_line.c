#include "shell.h"

/**
 * main - reads user input and print
 * Return: 0
 */

int main(void)
{
	char *prompt = "Prompt$ ";
	size_t line_len = 0;
	char *lines_buffer = NULL;
	ssize_t line_size = 0;
	char *lines_read;
	const char *delim = " \n";
	char **argv;
	int argc = 0, i = 0;

	pid_t child;
	int status;
	while (1)
	{
		printf("%s", prompt);
		line_size = getline(&lines_buffer, &line_len, stdin);
		/*check if getline return -1 or EOF*/
		if (line_size == -1)
		{
			perror("\nExit getline...");
			return (-1);
		}
		/*allocate space for lines read*/
		lines_read = strdup(lines_buffer);
		if (lines_read == NULL)
			return (-1);

		argv = split_str(lines_read, delim);
		if (argv == NULL)
			return (-1);

		/*create child process*/
		child = fork();
		/*check return value*/
		if (child == -1)
		{
			perror("process failed");
			return (-1);
		}

		if (child == 0)
			run_cmd(argv);
		else
		{
			wait(&status);
		}
	}
	/*free the allocated space*/
	free(lines_buffer);
	free(lines_read);
	i = 0;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);

	return (0);
}
