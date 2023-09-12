#include "shell.h"

char *build_full_path(const char *directory, const char *cmd)
{
	int cmd_len, dir_len
	char *full_path;

	cmd_len = strlen(cmd);
	dir_len = strlen(directory);
	char *full_path = malloc(cmd_len + dir_len + 2);

	if (!full_path)
		return (NULL);

	strcpy(full_path, directory);
	strcat(full_path, "/");
	strcat(full_path, cmd);

	return (full_path);
}

char *find_executable_in_directory(const char *directory, const char *cmd)
{
	struct stat exist;
	char *full_path;

	full_path = build_full_path(directory, cmd);

	if (!full_path)
		return (NULL);

	if (stat(full_path, &exist) == 0)
		return (full_path);
	else
		free(full_path);

	return (NULL);
}

char *get_path(char *cmd)
{
	char *path, *path_cpy, *token_path, *full_path;
	struct stat exist;

	path = getenv("PATH");

	if (!path)
		return (NULL);

	path_cpy = strdup(path);

	if (!path_cpy)
		return (NULL);

	token_path = strtok(path_cpy, ":");

	while (token_path)
	{
		full_path = find_executable_in_directory(token_path, cmd);

		if (full_path)
			return (full_path);

		token_path = strtok(NULL, ":");
	}
	free(path_cpy);

	if (stat(cmd, &exist) == 0)
		return (strdup(cmd));

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
