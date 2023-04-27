#include "simpleshell.h"
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
/**
* shell_launch- A function that launch process
* @argv: command line arguements
* Return: 0 on success and -1 on error
*
*/
int shell_launch(char **argv)
{
	int status;
	pid_t my_pid;
	char *shell_command = NULL;
	char *executed_command = NULL;

	my_pid = fork();
	if (my_pid < 0)
	{
		perror("fork error");
	}
	if (my_pid == 0)
	{
		if (argv)
		{
			shell_command = argv[0];
			executed_command = getPath(shell_command);
			if (execve(executed_command, argv, NULL) == -1)
			{
				perror("Error!\n");
			}
		}
	}
	if (my_pid > 0)
	{
		do {
			waitpid(my_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && WIFSIGNALED(status));
	}
	return (1);
}
