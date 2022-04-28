#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char * const s[] = {"holaa", NULL};
	char * const s2[] = {"holaa", NULL};

	execve("/bin/ls", s, s2);
	return (0);
}
