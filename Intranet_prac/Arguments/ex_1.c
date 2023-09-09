#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	char *store = NULL;
	size_t size = 0;
	ssize_t r_val;
	int running = 1;

	while(running)
	{
		printf("$ ");
		r_val = getline(&store, &size, stdin);

		if (r_val == -1)
		{
			free(store);
			exit(0);
		}

		printf("%s", store);
	}
	free(store);
	return (0);
}
