#include "simpleshell.h"

/**
 * execute- read and execute commands
 * @argv: command line arguements
 * Return: 0 on success and -1 on error
 *
*/

void execute(char **argv)
{
	char *shell_command = NULL;
	char *executed_command = NULL;

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
