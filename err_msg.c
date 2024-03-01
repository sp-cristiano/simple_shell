#include "shell.h"

/**
 * err_msg - This will display error mesages.
 * @cmd: This is the command to find
 * Return: This will return error messages
 */

void err_msg(char *cmd)
{
	char *err_msg, *err_msg2;

	/* This will get display the mesage */
	err_msg = "Command";
	write(STDERR_FILENO, err_msg, strlen(err_msg));
	write(STDERR_FILENO, cmd, strlen(cmd));
	err_msg2 = " not found\n";
	write(STDERR_FILENO, err_msg2, strlen(err_msg2));
	exit(EXIT_FAILURE);
}
