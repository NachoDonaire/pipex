#include "pipexlib.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	create_file(char *s, char * const env[])
{
	int fd;
	int pid;
	char * const file[] = {"touch", s, NULL};

	fd = 0;
	pid = fork();
	if (pid == 0)
		execve("/usr/bin/touch", file, env);
	else
	{
		fd = open(s, O_WRONLY);
		return (fd);
	}
	return (fd);
}
/*
int main()
{
	int fd;
	char * const env[] = {"hola", NULL};

	fd = create_file("hola", env);
}

*/


