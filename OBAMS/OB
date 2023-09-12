#include "shell.h"


char *get_path(char *cmd)
{
	char *path, *path_cpy, *token_path, *full_path;
	int cmd_len, token_len, stat_rv;
	struct stat exist;

	path = getenv("PATH");

	if (path)
        {
                /*CREATE A COPY OF THE PATH*/
                path_cpy = strdup(path);
                if (!path_cpy)
                        return NULL;

                /*get command length*/
                cmd_len = strlen(cmd);

                /*break down path into tokens with delimiter :*/
                token_path = strtok(path_cpy, ":");

                while (token_path)
                {
                        token_len = strlen(token_path);
                        full_path = malloc(cmd_len + token_len + 2);/*one for / and NULL*/
                        if (full_path == NULL)
                        {
                                free(path_cpy);
                                return (NULL);
                        }
                        /*copy token obtained into the fullpath*/
                        strcpy(full_path, token_path);
                        strcat(full_path, "/");
                        strcat(full_path, cmd);
                        strcat(full_path, "\0");

                        /*check if directory exists*/
                        stat_rv = stat(full_path, &exist);
                        if (stat_rv == 0)
                        {
                                /*free the copied path*/
                                free(path_cpy);

                                /*return the full path*/
                                return (full_path);
                        }
                        else
                        {
                                /*free up the full path*/
                                free(full_path);
                                token_path = strtok(NULL, ":");
                        }
                }

                /*free up path if not exists*/
                free(path_cpy);

                /*check if the command itself is valid*/
                if (stat(cmd, &exist) == 0)
                        return (cmd);
        }
	return (NULL);
}

void run_cmd(char **argv)
{
	char *cmd = NULL, *run_cmd = NULL;
	int rtn_val;

	if (argv)
	{
		/*set the first args command*/
		cmd = argv[0];

		/*generate the path to cmd*/
		run_cmd = get_path(cmd);

		/*call execve to run the command*/
		rtn_val = execve(run_cmd, argv, NULL);

		/*check for potential execve errors*/
		if (rtn_val == -1)
			perror("execve error");
	}
}
