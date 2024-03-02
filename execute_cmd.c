#include "shell.h"

/**
* execute_cmd - Execute command
* Description: This will execute command
* @array: Double pointer pointing to the
* address of the array
*/

void execute_cmd(char **array)
{
	if (array == NULL || array[0] == NULL)
		return;
	/* This will check if its a built in function */
	if (strcmp(array[0], "cd") == 0 || strcmp(array[0], "exit") == 0)
	{
		execute_builtin_cmd(array);
	}
	else
	{
		/* its not a built-in command */
		pid_t c_pid = fork();

		if (c_pid < 0)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		else if (c_pid == 0)
		{
			char *full_path = child_proc_exec_cmd_with_path(array[0]);

			if (execve(full_path, array, NULL) == -1)
			{
				/*err_msg(array[0]);*/
				perror("Error executing new command: ");
				free(array);
				free(full_path);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			int status;

			waitpid(c_pid, &status, 0);
			ck_wait_status(c_pid, status);
		}
	}
}
