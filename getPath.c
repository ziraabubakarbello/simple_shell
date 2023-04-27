#include "simpleshell.h"

/**
 * getPath- get the correct path
 * @shell_command: executeable commands
 * Return: returns a pointer
 *
*/

char *getPath(char *shell_command)
{
	char *path;
	char *path_copy;
	char *path_token;
	char *file_path;
	int directory_length;
	int command_length;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		path_copy = strdup(path);
		command_length = strlen(shell_command);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			directory_length = strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, shell_command);
			strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(shell_command, &buffer) == 0)
		{
			return (shell_command);
		}
		return (NULL);
	}
	return (NULL);
}
