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
		/** getting a copy of the path*/
		path_copy = strdup(path);

		/** getting the length of the command*/
		command_length = strlen(shell_command);

		/** breaking the readables into an array of strings using strtok()*/
		path_token = strtok(path_copy, ":");

		/** getting the exact path and of the command*/
		while (path_token != NULL)
		{

			/** getting the length of the newly created  string arrays*/
			directory_length = strlen(path_token);

			/** allocating memory size to for the path*/
			file_path = malloc(command_length + directory_length + 2);

			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, shell_command);
			strcat(file_path, "\0");
			/** validating the path*/
			if (stat(file_path, &buffer) == 0)
			{
				/** if successful free up space and return the path*/
				free(path_copy);
				return (file_path);
			}
			else
			{
				/** still free up space and continue the check*/
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
