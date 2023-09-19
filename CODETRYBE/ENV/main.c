#include "main.h"

int main(int ac, char **av, char **env)
{
	int i = 0;

	while(env[i] != NULL)
	{
		printf("env[%d] = %s\n", i, env[i]);
		i++;
	}

	i = 0;
	while(environ[i] != NULL)
	{
		printf("environ[%d] = %s\n", i, environ[i]);
		i++;
	}

	return (0);
}
