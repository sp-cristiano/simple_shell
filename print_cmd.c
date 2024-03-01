#include "shell.h"

/**
* print_cmd_prompt - Print command prompt
* Description: This will print the command prompt.
* @name: pointer pointing to the name of the command prompt.
*/

void print_cmd_prompt(const char *name)
{

	if (isatty(STDIN_FILENO))
	{
		/* char cwd[1024]; *//*  This is the maximum path length */

		/**
		 * if (getcwd(cwd, sizeof(cwd)) == NULL)
		{
			perror("Error getting the Current Working Directory");
			return;
		}
		write(STDOUT_FILENO, cwd, strlen(cwd));
		write(STDOUT_FILENO, " ", 1);
		*/
		write(STDOUT_FILENO, name, strlen(name));
		write(STDOUT_FILENO, " ", 1);
	}
}
