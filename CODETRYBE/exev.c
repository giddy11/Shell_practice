#include "main.h"


int main()
{
	char *_getline[] = {"/bin/ls", "-l", "/usr/", NULL};
	int execvRV = 0;

	printf("Before calling Execve\n");

	execvRV = execve("/bin/ls", _getline, NULL);

	if (execvRV == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	printf("After execve\n");


	return (0);
}
