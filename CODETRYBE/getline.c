#include "main.h"

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	(void) stream;
	if (lineptr == NULL || n == NULL || stream == NULL)
		exit(EXIT_FAILURE);
	*n = 1024;
	*lineptr = malloc(*n);
	if (*lineptr == NULL)
		exit(EXIT_FAILURE);


}
