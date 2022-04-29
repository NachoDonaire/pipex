#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include "pipexlib.h"

int	lens(char *s);
char	*join_bin(char *s);

void	execute(char *str, char * const env[])
{
  char *com;
    char **spliteao;

	spliteao = ft_split(str, ' ');
    printf("%s", spliteao[0]);
    com = join_bin(spliteao[0]);
	char *const flags[] = {spliteao[0], spliteao[1], NULL};
	execve(com, flags, env);
}
int	lens(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*join_bin(char *s)
{
	char *b;
	int i;
	char *sol;
	int z;

	b = "/bin/";
	sol = malloc((lens(s) + lens(b) + 1) * sizeof(char));
	i = 0;
	z = 0;
	while (b[z])
		sol[i++] = b[z++];
	z = 0;
	while (s[z])
		sol[i++] = s[z++];
	sol[i] = '\0';
	return (sol);
}

int main(int arg, char *args[], char * const env[])
{
	if (arg > 10)
		return (0);
	int fd[2];
	int pid;
	int fd2;
	pipe(fd);
	pid = fork();

	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		execute(args[2], env);
	}
	else
	{
		fd2 = open(args[4], O_WRONLY);
		if (fd2 < 0)
			fd2 = create_file(args[4], env);
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		dup2(fd2, 1);
        execute(args[3], env);
	}
	return (0);
}
