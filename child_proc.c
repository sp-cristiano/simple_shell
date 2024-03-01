#include "shell.h"

/**
 * child_proc_exec_cmd_with_path - Find the full path and execute it
 * Description: this will find path and execute it
 * @array: Pointer  pointing to the address of the array.
 * Return: The will return the file path.
 */

char *child_proc_exec_cmd_with_path(const char *array)
{
	char *full_path = find_path(array);

	if (full_path == NULL)
	{
		char *err_msg = (char *)malloc(strlen(array) +  20 + strlen(array + 11));

		if (err_msg == NULL)
		{
			perror(array);
			exit(EXIT_FAILURE);
		}
		/*sprintf(err_msg, "%s: %d: %s: not found\n", SHELL_NAME, __LINE__, array);*/
/*		sprintf(err_msg, "%s: %d: %s: not found\n", array[-1], __LINE__, array[0]);
		write(STDERR_FILENO, err_msg, strlen(err_msg));*/
		perror("Error::");
		free(err_msg);
		exit(EXIT_FAILURE);
	}
	return (full_path);
}
