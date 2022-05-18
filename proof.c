#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char **flags;
	char *com;
	flags = malloc(sizeof(char *) * 9);
   flags[0] = "ls";
	flags[1] = "-a";
	flags[2] = NULL;
	com = "/bin/ls";
	char * const env[] = {"hola", NULL};
 execve(com, flags, env);
}
