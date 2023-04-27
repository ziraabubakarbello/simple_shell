#include "simpleshell.h"

/**
 * main- maint function of the shell
 * @ac: an integer type that counts the
 * number of argument passed.
 * @argv: pointer to pointer to a string type.
 * Return: returns an integer value
 * 0 or any other number for
 * success or failure respectively
*/

int main(int ac, char **argv)
{
	(void)ac;
	char *command_prompt = "$ ";
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t nreads;
	char *lineptr_copy = NULL;
	const char *DELIMETER = " \n";
	char *lineptr_tokens;
	int token_count = 0;
	int position;
	while (1)
	{
		printf("%s ", command_prompt);
		nreads = getline(&lineptr, &n, stdin);
		if (nreads == -1)
		{
			if (feof(stdin))
			{
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("read line");
				exit(EXIT_FAILURE);
			}
			return (nreads);
		}
		lineptr_copy = malloc(sizeof(char) * nreads);
		if (lineptr_copy == NULL)
		{
			perror("Memoray Allocation Failed..\n");
			return (2);
		}
		strcpy(lineptr_copy, lineptr);
		lineptr_tokens = strtok(lineptr, DELIMETER);
		while (lineptr_tokens != NULL)
		{
			token_count++;
			lineptr_tokens = strtok(NULL, DELIMETER);
		}
		token_count++;
		argv = malloc(sizeof(char *) * token_count);
		if (argv == NULL)
		{
			perror("MEmory Allocation Failed\n");
			return (2);
		}
		lineptr_tokens = strtok(lineptr_copy, DELIMETER);
		for (position = 0; lineptr_tokens != NULL; position++)
		{
			argv[position] = malloc(sizeof(char) * strlen(lineptr_tokens));
			strcpy(argv[position], lineptr_tokens);
			lineptr_tokens = strtok(NULL, DELIMETER);
		}
		argv[position] = NULL;
		execute(argv);
	}
	free(lineptr);
	free(lineptr_copy);
	free(argv);
	return (0);
}
