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
	(void)argv;
	char *command_prompt = "$ ";

	/**
	 * passing arguments and displaying using the getline()
	 * @lineeptr: buffer to hold the strings.
	 * @n: size of the string allocated
	 * @nreads: holds the return value of the function.
	*/
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t nreads;

	/**
	 * usng the strtok() to break down the strings
	 * @lineptr_copy: holing a copy of the original string
	 * @delimeter: delimiting values
	 * Return: returns NULL
	*/
	char *lineptr_copy = NULL;

	const char *DELIMETER = " \n";

	char *lineptr_tokens;
	int token_count = 0;
	int i;

	while (1)
	{
		printf("%s ", command_prompt);
		nreads = getline(&lineptr, &n, stdin);

		if (nreads == -1)
		{
			perror("Error! exiting...");
			return (1);
		}
		/**dynamically allocating memery for lineptr_copy and validating*/
		lineptr_copy = malloc(sizeof(char) * nreads);

		if (lineptr_copy == NULL)
		{
			perror("Memoray Allocation Failed..\n");
			return (2);
		}
		/**copying the values from lineptr to lineptr_copy*/
		strcpy(lineptr_copy, lineptr);
		/**using the strtok() to convert the lineptr values into an array of strings and counting*/
		lineptr_tokens = strtok(lineptr, DELIMETER);

		while (lineptr_tokens != NULL)
		{
			token_count++;
			lineptr_tokens = strtok(NULL, DELIMETER);
		}
		token_count++;
		/**allocating a space a for the total newly created string arrays*/
		argv = malloc(sizeof(char *) * token_count);

		if (argv == NULL)
		{
			perror("MEmory Allocation Failed\n");
			return(2);
		}
		lineptr_tokens = strtok(lineptr_copy, DELIMETER);

		/***allocating memory space for each tokenized strings */

		for (i = 0; lineptr_tokens != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(lineptr_tokens));

			strcpy(argv[i], lineptr_copy);
			lineptr_tokens = strtok(NULL, DELIMETER);
		}
		argv[i] = NULL;

		printf("%s\n ", lineptr);
	}
	free(lineptr);
	free(lineptr_copy);
	free(argv);
	return (0);
}
