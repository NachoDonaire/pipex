#include "pipexlib.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
char	**ft_split(char const *s, char c);
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
		wait(NULL);
		fd = open(s, O_WRONLY);
		return (fd);
	}
	return (fd);
}
/*
int	bin_or_usr(char *s, char * const env[])
{
	char **spliteo;
	int pid;
	int lec;
	char *buff;
	spliteo = ft_split(s, ' ');
	char * const s2[] = {"/usr/bin/", spliteo[0], NULL};
	buff = malloc(sizeof(char) * 100);

	pid = fork();
	if (pid == 0)
	{
		execve("/bin/ls", s2, env);
	}
	else
	{
		lec = read(1, buff, 1000);
		if (lec <= 0)
			return (1);
		else
			return (0);
	}
	return (0);
}

int main()
{
	int fd;
	char * const env[] = {"hola", NULL};

	fd = bin_or_usr("ls", env);
	printf("%d", fd);
	return (0);

}*/
