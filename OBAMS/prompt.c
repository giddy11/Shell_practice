#include "shell.h"

/** 
 * prompt - gets user input
 * Return: total user input
 */

char *prompt(void)
{
	char *input = "Prompt$ ";
	/*buffer for getline*/
	char *lines_buffer = NULL;
	/*length of lines read*/
	size_t line_len = 0;
	/*return value of getline*/
	ssize_t line_size = 0;
	char *lines_read;

	printf("%s", input);
	line_size = getline(&lines_buffer, &line_len, stdin);
	/*handle getline return*/
	if (line_size == -1)
	{
		perror("\nExiting getline...");
		return (NULL);

	}
	lines_read = strdup(lines_buffer);

	free(lines_buffer);
	return (lines_read);
}

