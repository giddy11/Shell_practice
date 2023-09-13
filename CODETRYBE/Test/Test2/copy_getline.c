#include "main.h"
/**
 * exit_helper - Entry point
 * Description: print env vars
 * @buff: line buffer
 * Return: none
 */
void exit_helper(char **buff)
{
	printf("Realloc failed. Exit function");
	free(*buff);
	exit(EXIT_FAILURE);
}

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t i = 0;
	char c;
	int readFile = 0, len = 0;

	/*printf("Address of i = %lx\n", i);
	printf("Address of c = %x\n", c);
	printf("Address of readFile = %x\n", readFile);
	printf("Address of len = %x\n", len);
	printf("Address of lineptr = %x\n", **lineptr);
	printf("Address of n = %lx\n\n\n", *n);*/



	(void) stream;
	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		printf("LINE-32>>stream was null or lineptr or n\n");
		exit(EXIT_FAILURE);
	}
	*n = 10;
	*lineptr = malloc(*n);
	if (*lineptr == NULL)
		exit(EXIT_FAILURE);
	printf("LINE-39>>>n : %ld and [lineptr before NULL: %s]\n", *n, *lineptr);
	(*lineptr)[0] = '\0';/*ensure that its an empty string*/
	printf("LINE-41[lineptr after NULL: %s]\n", *lineptr);
	for (i = 0; ; i++)
	{	
		len = strlen(*lineptr);
		printf("\n\n<<<\n\n%ld\n>>>", i);
		printf("LINE-45>>[lineptr length: %u]\n", len);
		if (len + 1 == *n)
		{
			printf("LINE-48>>Time to use realloc to double the size\n");
			*n *= 2;
			printf("LINE-50>>n is now: %ld\n", *n);
			*lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL)
				exit_helper(lineptr);
		}
		readFile = read(STDIN_FILENO, &c, 1);
		printf("LINE-56>>readFile return: %d\n", readFile);
		printf("LINE-57>>c: %c\n", c);
		if (readFile == 0)
		{
			printf("LINE-65>>encountered an EOF:%d\n", readFile);
			return(-1);
		}
		if (c == 10)
		{
			printf("LINE-71>>c is a new line\n");
			printf("LINE-72>>lineptr is %s\n", *lineptr);
			(*lineptr)[i] = c;
			printf("LINE-74>>lineptr updated is %s\n", *lineptr);
			return (i + 1);/*the +1 is for null*/
		}
		printf("LINE-77>>lineptr contains: %s", *lineptr);
		(*lineptr)[i] = c;
		printf("\nLINE-79>>lineptr now contains: %s", *lineptr);
		(*lineptr)[i + 1] = '\0';
	}
}

int main()
{
        size_t n = 0;
        char *buf = NULL;

        printf("Enter name: ");
        _getline(&buf, &n, stdin);

        printf("Name is %sBuffer size is %ld\n", buf, n);

        free(buf);

        return (0);
}
