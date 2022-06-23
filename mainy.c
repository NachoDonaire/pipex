#include <unistd.h>
#include <stdio.h>

int	main()
{
	int i;
	char	*const sol[] = {"continuara", NULL};
	i = execve(NULL, sol, NULL);
	printf("%d",  i);
	return (0);
}
