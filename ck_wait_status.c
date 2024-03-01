#include "shell.h"

/**
 * ck_wait_status - Check the wait status
 * Description: This will check the waith status of
 * parent process.
 * @c_pid: This is the child process
 * @status: This is the status number
 */

void ck_wait_status(pid_t c_pid, int status)
{
	char *msg_1 = "\nChild process %d exited with status %d\n";
	char *msg_2 = "Child process terminated abnormally\n";

	if (WIFEXITED(status))
	{

		int buf_size = snprintf(NULL, 0, msg_1, c_pid, WEXITSTATUS(status));
		char *buf = malloc(buf_size + 1);

		if (buf == NULL)
		{
			perror("malloc: Unable to dynamically allocate memory");
			exit(EXIT_FAILURE);
		}
		snprintf(buf, buf_size + 1, msg_1, c_pid, WEXITSTATUS(status));
		if (write(STDOUT_FILENO, buf, buf_size) == -1)
		{
			perror("write: Unable to write to standard output");
			exit(EXIT_FAILURE);
		}
		free(buf);
	}
	else
	{
		if (write(STDOUT_FILENO, msg_2, strlen(msg_2)) == -1)
		{
			perror("write: Unable to write to standard output");
			exit(EXIT_FAILURE);
		}
	}
}
