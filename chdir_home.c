#include "shell.h"

/**
 * chdir_home - This change dir to home
 * Description: This will change the directory to home
 *
 * Retrun: Will return 0 if true.
 */

void chdir_home(void)
{
	const char *home_dir = getenv("HOME");

	if (home_dir != NULL)
	{
		if (chdir(home_dir) != 0)
		{
			perror("cd");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		perror("cd: HOME not set");
		exit(EXIT_FAILURE);
	}
}
