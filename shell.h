#ifndef _SHELL_H
#define _SHELL_H

/* Including header files */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <limits.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

/* Prototypes of  Functions */
void print_cmd_prompt(const char *name);
void execute_cmd(char **array);
void ck_wait_status(pid_t c_pid, int status);
char *find_path(const char *cmd);
char *child_proc_exec_cmd_with_path(const char *array);
void execute_builtin_cmd(char **array);
void chdir_home(void);
void exit_shell(void);
void err_msg(char *cmd);

/* Declare enironment variable globally */
extern char **environ;
/* Defining macros */

/* Defining shell name */
#define SHELL_NAME	"hsh"

#endif /* _SHELL_H */
