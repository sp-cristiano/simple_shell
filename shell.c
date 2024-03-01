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
		/* Read user's input using getline()*/
		read_cmd = getline(&cmd, &cmd_len, stdin);
		/*token = strtok(cmd, delimiters);*/ /* String Tokenization */

		/*array = malloc(sizeof(char *) * 1024);*/ /* Allocate memory to array*/

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
			/*	free(cmd_cp); */
				exit_shell();
			}
			strcpy(cmd_cp, cmd);/* copying the command */

			token = strtok(cmd, delimiters); /* String Tokenization */
		/*	array = malloc(sizeof(char *) * 1024); *//* Allocate memory to array*/

			if (token == NULL)
				continue; /* If no command enterd, prompt again */
			i = 0;
			while (token != NULL)
			{
				i++;
				/*array[i] = token;*/
				/* Re-assigning the token first parameter to be Null */
				token = strtok(NULL, delimiters);
				/*i++;*/
			}
			i++;

			array = av = malloc((sizeof(char *) * i)); /* Allocate memory to array */
	/*		if (array == NULL)
			{
				perror("Error allocating memory");
				free(cmd);
				exit(EXIT_FAILURE)
			}*/
			token = strtok(cmd_cp, delimiters);
			for (j = 0; token != NULL; j++)
			{
				/* Allocate memory to each index of the array */
				array[j] = av[j] = malloc(sizeof(char) * strlen(token));
				strcpy(array[j], token);
				token = strtok(NULL, delimiters);
			}

			/*array[i] = NULL;*/
			array[j] = NULL;
			execute_cmd(array);

		/*	for (k = 0; k < j; k++)
			{
				free(arrray[k]);
			}*/
		}
		/*free(cmd_cp);*/
	}
	free(array);
	free(cmd_cp);
	free(cmd);

	return (0);
}
