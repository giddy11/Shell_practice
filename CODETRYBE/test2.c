#include "main.h"

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
	getline(&buf, &n, stdin);

	printf("Name is %sBuffer size is %ld\n", buf, n);
	//printf("Name is %sName again is %s", buf, buf);


	//free(buf);


	return (0);
}
