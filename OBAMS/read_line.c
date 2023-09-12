#include "shell.h"

void getInput(char **lines_buffer, size_t *line_len, const char *prompt) {
    ssize_t line_size;

    printf("%s", prompt);
    line_size = getline(lines_buffer, line_len, stdin);
    if (line_size == -1) {
        perror("\nExit getline...");
        exit(EXIT_FAILURE); // Exit the program if getline fails.
    }
}

int main(void) {
    char *prompt = "Prompt$ ";
    char *lines_buffer = NULL;
    size_t line_len = 0;
    const char *delim = " \n";
    int argc, i, status;
    pid_t child;
	char **argv;

    argc = i = 0;

    while (1) {
        getInput(&lines_buffer, &line_len, prompt);

        // Rest of your code for splitting and executing commands...
	argv = split_str(lines_buffer, delim);
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

    // Free allocated memory and perform cleanup as needed.
    free(lines_buffer);

    return 0;
}

