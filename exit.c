#include "shell.h"

/**
 * exit_shell - This will exit the shell
 * Description: This will exit the shell with a
 * loading process.
 *
 * Return: Does not have any return value.
 */

void exit_shell(void)
{
	bool run;

	char *msg4_0 = SHELL_NAME " is exiting ";
	char *msg4_1 = ".";
	char *msg4_2 = "..";
	char *msg4_3 = "...\n";
	char *msg5 = SHELL_NAME " exited with success\n";

	write(STDOUT_FILENO, msg4_0, strlen(msg4_0));
	sleep(1);
	write(STDOUT_FILENO, msg4_1, strlen(msg4_1));
	sleep(1);
	write(STDOUT_FILENO, msg4_2, strlen(msg4_2));
	sleep(1);
	write(STDOUT_FILENO, msg4_3, strlen(msg4_3));
	write(STDOUT_FILENO, msg5, strlen(msg5));

	run = false;
	run = run;

	exit(EXIT_SUCCESS);
}
