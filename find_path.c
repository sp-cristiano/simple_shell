#include "shell.h"
/**
 * find_path - This will find the path of a command using PATH
 * @cmd: This is the command to find
 * Return: This will return full path if found. Otherwise NULL
 */

char *find_path(const char *cmd)
{
	/* This will get the path environmental variable */
	char *file_path = getenv("PATH");
	char *file_path_copy = strdup(file_path); /* duplicate path*/

	if (file_path == NULL)
	{
		perror("Error getting PATH");
		free(file_path_copy);
		return (NULL);
	}
	else
	{
		/* Tokenize the PATH variable */
		char *path_dir_token = strtok(file_path_copy, ":");
		char *full_path = NULL;
		size_t full_path_size = strlen(file_path) + strlen(cmd) + 2;

		full_path = (char *)malloc(full_path_size);
		if (full_path == NULL)
		{
			perror("Error allocating memory");
			return (NULL);
		}
		/* loop through each directory in the PATH*/
		while (path_dir_token != NULL)
		{
			snprintf(full_path, full_path_size, "%s/%s", path_dir_token, cmd);
			/* check if the command is in the path */
			if (access(full_path, X_OK) == 0)
			{
				free(file_path_copy);
				return (full_path);
			}

			path_dir_token = strtok(NULL, ":");
		}
		free(full_path);
	}
	free(file_path_copy);
	return (NULL);
}
