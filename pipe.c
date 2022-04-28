#include <unistd.h>
#include <stdio.h>

int main()
{
	int fd[2];
	int pid;
	int lec;
	char buff[6];

	pipe(fd);
	pid = fork();

	if (pid == 0) //hijo
	{
		close(fd[0]);
		write(fd[1], "kahoot", 6);
	}
	else if (pid == -1)
		return (0);
	else
	{
		close(fd[1]);
		lec = read(fd[0], buff, sizeof(buff));
		printf("buff: %s, pid: %d, lec: %d", buff, pid, lec);
	}
	return (0);
}


