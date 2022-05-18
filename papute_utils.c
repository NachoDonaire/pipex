#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "pipexlib.h"

void	join_file(char *s[], char *args, int i)
{
	char	*file;
	int		y;

	y = 0;
	file = malloc(sizeof(char) * (lens(args) + 1));
	while (args[y])
	{
		s[i][y] = args[y];
		y++;
	}
	s[i++][y] = '\0';
	s[i] = NULL;
}

void	execute_a(char *str, char	*const env[], char *args)
{
	char	*com;
	char	**spliteao;
	int		i;

	i = 0;
	spliteao = ft_split(str, ' ');
	if (str[0] != '/')
		com = join_bin(spliteao[0]);
	else
		com = spliteao[0];
	while (spliteao[i])
		i++;
	if (!args)
		return ;
	execve(com, spliteao, env);
}

void	execute_b(char *str, char *const env[])
{
	char	*com;
	char	**spliteao;
	int		i;
	int		y;

	i = 0;
	y = 0;
	spliteao = ft_split(str, ' ');
	if (str[0] != '/')
		com = join_bin(spliteao[0]);
	else
		com = spliteao[0];
	execve(com, spliteao, env);
}
