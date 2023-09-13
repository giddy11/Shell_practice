#include "main.h"

char *_strtok(char *str, const char *delim)
{

}

int main()
{
	char *src = "0";
	char *str = malloc(sizeof(char) * strlen(src));
	strcpy(str, src);
	char *delim = " ";
	char *token;
	int i = 0;

	token = strtok(str, delim);
	for (; token != NULL; i++)
	{		
		//token = strtok(str, delim);
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}

	free(str);








	/*token = strtok(str, delim);
	printf("%s\n", token);

	token = strtok(NULL, delim);
	printf("%s\n", token);

	token = strtok(NULL, delim);
	printf("%s\n", token);

	token = strtok(NULL, delim);
	printf("%s\n", token);*/

	return (0);
}
