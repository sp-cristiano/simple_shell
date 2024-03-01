#include "shell.h"

/**
 * execute_builtin_cmd - This execute builtin commands
 * Description: This will execute built-in command
 * @array: Double pointer pointing to the address
 * of the array
 */

void execute_builtin_cmd(char **array)
{
	if (array == NULL  || array[0] == NULL)
	{
		return;
	}

	/* Check if the command is a built-in command */
	if (strcmp(array[0], "cd") == 0)
	{
		/* when built-in command is "cd" */
		if (array[1] != NULL)
		{
			if (chdir(array[1]) != 0)
			{
				perror("cd");
			}
		}
		else
		{
			/*change the directory to home if no argument is given */
			chdir_home();
		}
	}
	else if (strcmp(array[0], "exit") == 0)
	{
		/* when built-in command is "exit" */
		exit_shell();
	}
	else
	{
		/* this is not a built-in function*/
		char *err_msg3 = ("Command not found builtin\n");

		write(STDERR_FILENO, err_msg3, strlen(err_msg3));
	}
}
