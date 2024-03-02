#include "shell.h"
/**
 * main - This is the Entry point of the program
 * @av: Argument vector
 * @ac: Argument count
 * Description: This is a simple shell C program.
 * Author: [Odili Chinedum]
 *
 * Return: Always return 0 if successful or 1 on error.
 */

int main(int ac, char **av)
{
	char *cmd = NULL, *cmd_cp = NULL, *name = "#Cisfun$ ", **array,
	     *token, *delimiters = " \t\n";
	int i, j;
	bool run = true;
	size_t cmd_len = 0;
	ssize_t read_cmd;

	/* Declaring void variables */
	(void)ac;

	while (run)
	{
		print_cmd_prompt(name); /* Print programa prompt to standard output */
		read_cmd = getline(&cmd, &cmd_len, stdin);
		if (read_cmd == -1)
		{
			if (feof(stdin))
			{
				exit_shell();
			}
			else
			{
				perror("Error reading input");
				free(cmd);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			cmd_cp = malloc(sizeof(char *) * read_cmd); /* Allocate memory to command */
                        if (cmd_cp == NULL)
                        {
                                perror("Error allocating memory");
                                exit_shell();
                        }
                        strcpy(cmd_cp, cmd);/* copying the command */
                        token = strtok(cmd, delimiters); /* String Tokenization */

                        if (token == NULL)
                                continue; /* If no command enterd, prompt again */
                        i = 0;
                        while (token != NULL)
                        {
                                i++;
                                token = strtok(NULL, delimiters);
                        }
                        i++;
                        array = av = malloc((sizeof(char *) * i)); /* Allocate memory to array */
                        token = strtok(cmd_cp, delimiters);
                        for (j = 0; token != NULL; j++)
                        {
                                array[j] = av[j] = malloc(sizeof(char) * strlen(token));
                                strcpy(array[j], token);
                                token = strtok(NULL, delimiters);
                        }
			execute_cmd(array);
		}
	}
	free(array);
	free(cmd_cp);
	free(cmd);

	return (0);
}
