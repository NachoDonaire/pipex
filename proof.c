#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int arg, char **args, char *env[])
{
	if (!args)
		return (0);
	if (!arg)
		return (0);
	int pid;
	char *const s[] = {"/home/nikole_kush/C/pipex", NULL};

	pid = fork();
	if (pid == 0)
	{
		execve("./ls.sh", s, env);
	}
	else
		printf("hola");
	return (0);
}

