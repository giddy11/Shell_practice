#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	char *store = NULL;
	size_t size = 0;
	ssize_t r_val;
	char *temp;

	printf("$ ");
	r_val = getline(&store, &size, stdin);
	printf("$ ");

	if (r_val == -1)
	{
		free(store);
		exit(0);
	}

	printf("Before tokenizing\n");
	printf("%s", store);

	printf("After tokenizing\n");

	temp = strtok(store, "\n");
	printf("%s", temp);

	free(store);



	return (0);
}
