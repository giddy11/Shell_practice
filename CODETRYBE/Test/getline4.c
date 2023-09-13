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

/**
 * _getline - Entry point
 * Description: print env vars
 * @lineptr: line buffer
 * @n: length
 * @stream: stream
 * Return: length
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t i = 0;
	char c;
	int readFile;

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
		printf("\n\n<<<\n\n%ld\n>>>", i);
		printf("LINE-45>>[lineptr length: %lu]\n", strlen(*lineptr));
		if (strlen(*lineptr) + 1 == *n)
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
		if (readFile == 0 && i == 0)
		{
			printf("LINE-60>>readfile has read all and i = 0 means EOF\n");
			return (-1);
		}
		else if (readFile == 0)
		{
			printf("LINE-65>>readFile has read all which returns 0:%d\n", readFile);
			i--;
			continue;
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
	free(*lineptr);
	printf("LINE-83>>lineptr contains after been freed: %s", *lineptr);
	exit(EXIT_FAILURE);
}

int main()
{
        size_t n = 0;
        char *buf = NULL;
        /*char *buf = malloc(sizeof(char) * n);
        if (buf == NULL)
        {
                printf("Error");
                return (-1);
        }*/

        printf("Enter name: ");
        _getline(&buf, &n, stdin);

        printf("Name is %sBuffer size is %ld\n", buf, n);
        //printf("Name is %sName again is %s", buf, buf);


        //free(buf);


        return (0);
}
