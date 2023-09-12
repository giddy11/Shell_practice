#include "main.h"


int main(int ac, char **argv)
{
	struct stat check;
	int stat_rv;
	int loop = 1;

	while(argv[loop])
	{
		stat_rv = stat(argv[loop], &check);
		if (stat_rv == 0)
		{
			printf("%s found\n", argv[loop]);
		}
		else
		{
			printf("%s not found\n", argv[loop]);
		}
		loop++;
	}


	return (0);
}
