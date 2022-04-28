#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int arg, char **args)
{
	int fd[2];
	int pid;
	int i;
	int lec;
	char buff[10];
	if (!args)
		return (0);

	if (arg != 5)
		return (0);
	i = 0;
	fd[0] = open("in", O_RDWR);
	fd[1] = open("out", O_RDWR);
	pipe(fd);
	pid = fork();
	printf("-----pid: %d----", pid);
	if (pid == -1)
		return (0);
	else if (pid == 0)
	{
		printf("etras?");
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);

		execlp("/bin/ls", "ls", NULL);
	}
	else
	{
		close(fd[1]);
		lec = read(fd[0], buff, sizeof(buff));

		execlp("/bin/ls", args[2], NULL);

	}
	wait(&pid);
	return (0);
}



