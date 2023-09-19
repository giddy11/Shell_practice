#include "main.h"

void interactive()
{
	char *buffer = NULL, *tok = NULL;
	size_t len = 0;
	char *delim = {"lo "};
	ssize_t rtn_val = 0;

	printf("$ ");

	rtn_val = getline(&buffer, &len, stdin);
	if (rtn_val == -1)
	{
		free(buffer);
		exit(EXIT_FAILURE);
	}

	printf("len = %ld\n", len);
	tok = strtok(buffer, delim);
	printf("Token is %s\n", tok);
}

void non_interactive()
{
	printf("I am not in interactive mode\n");
}

int main(void)
{
	if (isatty(STDIN_FILENO))
	{
		interactive();
	}
	else
	{
		printf("Nah\n");
		non_interactive();
	}

	return (0);
}
