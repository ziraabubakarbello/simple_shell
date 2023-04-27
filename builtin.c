#include"simpleshell.h"
#include<stdio.h>
#include<unistd.h>
#include<string.h>
int shell_cd(char **argv);
int shell_help(char **argv);
int shell_exit(char **argv);
char *builtin_str[] = {
	"cd",
	"help",
	"exit"
};
int (*builtin_arrayfun[]) (char **) = {
	&shell_cd,
	&shell_help,
	&shell_exit
};

/**
* shell_builtins - a function that returns the size of builtin_str array
*
* Return: the size of builtin_str array
*/
int shell_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

/**
* shell_cd - a function that can implement the cd of a shell program
* @argv: array of string arguments
*
* Return: 1 (Success)
*/
int shell_cd(char **argv)
{
	(void)argv;
	if (argv[1] == NULL)
	{
		fprintf(stderr, "Error: expected argument to cd\n");
	}
	else
	{
		if (chdir(argv[1]) != 0)
		{
			perror("Error\n");
		}
	}
	return (1);
}

/**
* shell_help - A function that display the list of available builtin commands
* @argv: array of string arguments
*
* Return: 1 (Success)
*/
int shell_help(char **argv)
{
	(void)argv;
	int i;

	printf("This is a simple C shell built by Kenny and Bello\n");
	printf("Please enter program names and arguments then press enter.\n");
	printf("The following are built in commands: \n");
	for (i = 0; i < shell_builtins(); i++)
	{
		printf(" %s\n", builtin_str[i]);
	}
	printf("Use the man command for information on other programs.\n");
	return (1);
}

/**
* shell_exit - A function that implements the exit command of a shell
* @argv: array of string arguments
*
* Return: 0 (Success)
*/
int shell_exit(char **argv)
{
	(void)argv;
	return (0);
}

/**
* execute - a function that execute a builtin command or launch a process
* @argv: array of string arguments
*
* Return: builtin command or a launch process
*/
int execute(char **argv)
{
	int i;

	if (argv[0] == NULL)
	{
		return (1);
	}
	for (i = 0; i < shell_builtins(); i++)
	{
		if (strcmp(argv[0], builtin_str[i]) == 0)
		{
		return ((*builtin_arrayfun[i])(argv));
		}
	}
	return (shell_launch(argv));
}
