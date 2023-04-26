#include "simpleshell.h"
#include<sys/wait.h>
#include<unistd.h>

/**
 * execute- read and execute commands
 * @argv: command line arguements
 * Return: 0 on success and -1 on error
 *
*/

void execute(char **argv)
{
	int status;
	pid_t child_pid;
	char *shell_command = NULL;
	char *executed_command = NULL;

	child_pid = fork();
	if (child_pid == 0)
	{
	if (argv)
	{
		/**getting the command*/
		shell_command = argv[0];

		/**getting the path to the command*/
		executed_command = getPath(shell_command);

		/**executing the command*/
		if (execve(executed_command, argv, NULL) == -1)
		{
			perror("Error!\n");
		}
	}
	}
	else if (child_pid > 0)
	{
	do
	{
		waitpid(child_pid, &status, WUNTRACED);
	}while(!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	{
		perror("Error\n");
	}
}
