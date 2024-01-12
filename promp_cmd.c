#include "shell.h"

void promp_cmd(char **av, char **env)
{
	char *cmd_str = NULL;
	int ind, status;
	size_t n = 0;
	char *argv[] = {NULL, NULL};
	ssize_t num_chars;
	pid_t child_pid;

	while(1)
	{
		printf("cisfun$ ");
		num_chars = getline(&cmd_str, &n, stdin);
		if(num_chars == -1)
		{
			free(cmd_str);
			exit(EXIT_FAILURE);
		}
		ind = 0;
		while(cmd_str[ind])
		{
			if(cmd_str[ind] == '\n')
				cmd_str[ind] = 0;
			ind ++;
		}
		argv[0] = cmd_str;
		child_pid = fork();
		if(child_pid == -1)
		{
			free(cmd_str);
			exit(EXIT_FAILURE);
		}
		if(child_pid == 0)
		{
			if(execve(argv[0], argv, env) == -1)
				printf("%s: No such file or directory\n", av[0]);
		}
		else
			wait(&status);
	}
}
