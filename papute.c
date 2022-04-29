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
	char *const flags[2] = {spliteao[0], spliteao[1], NULL};
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
	//char **flags;
	//flags = ft_split(args[2]);
	//char * const s[1];
	//char * const s2[] = {"hola!", NULL};
	//char *com1;
	//char *com2;

	//char buff[200];
	//int lec;
	pipe(fd);
	pid = fork();

	if (pid == 0)
	{
		//printf("hola?");
		close(fd[0]);
		//write(fd[1], "hoola", 5);
		dup2(fd[1], 1);
		//com1 = join_bin(args[2]);
		//close(fd[1]);
		execute(args[2], env);
        //execve(args[2], s2, env);
	}
	else
	{

		fd2 = open(args[4], O_WRONLY);
		//printf("hola!");
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		//lec = read(fd[0], buff, sizeof(buff));
		//printf("lec: %d; buff: %s", lec, buff);
		dup2(fd2, 1);
		//com2 = join_bin(args[3]);
		//execve(args[3], s2, env);
        execute(args[3], env);
	}
	return (0);
}
