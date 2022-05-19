#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "pipexlib.h"

char	*join_path(char *sol, char *args)
{
	int		i;
	int		y;
	char	*res;

	res = malloc(sizeof(char) * (lens(sol) + lens(args) + 1));
	i = 0;
	y = 0;
	while (sol[i])
	{
		res[i] = sol[i];
		i++;
	}
	res[i++] = '/';
	while (args[y])
	{
		res[i++] = args[y++];
	}
	res[i] = '\0';
	return (res);
}

int	checkin_path(char *s, char *find)
{
	int i; 
	int y;

	y = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == find[y])
		{
			i++;
			y++;
			if (find[y] == '\0')
				return (1);
		}
		y = 0;
		i++;
	}
	return (0);
}

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
	char	*help;
	int		i;
	char	*b;

	i = 0;
	spliteao = ft_split(str, ' ');
	if (str[0] != '/')
	{
		help = find_path(env);
		b = split_path(help, spliteao[0]);
		com = join_path(b, spliteao[0]);
	}
	else
		com = spliteao[0];
	while (spliteao[i])
		i++;
	if (!args)
		return ;
	if (execve(com, spliteao, env) == -1)
	{
		perror("command not found");
		exit(-1);
	}
	
}

void	execute_b(char *str, char *const env[])
{
	char	*com;
	char	**spliteao;
	int		i;
	char	*b;
	char	*help;

	i = 0;
	spliteao = ft_split(str, ' ');
	if (str[0] != '/')
	{
		help = find_path(env);
		b = split_path(help, spliteao[0]);
		com = join_path(b, spliteao[0]);
	}
	else
		com = spliteao[0];
	if (execve(com, spliteao, env) == -1)
	{
		perror("command not found");
		exit(-1);
	}
}

char	*find_path(char *const env[])
{
	int	i;
	int	check;
	char *sol;

	i = 0;
	check = checkin_path(env[i], "PATH");
	while (check == 0)
	{
		i++;
		check = checkin_path(env[i], "PATH");
	}
	sol = env[i];
	return (env[i]);
}

char	*pseudo_join(char *path, char *com)
{
	char *sol;
	int i;
	int y;

	y = 0;
	i = 0;
	sol = malloc(sizeof(char) * (lens(path) + lens(com) + 1));
	while (path[i])
	{
		sol[i] = path[i];
		i++;
	}
	sol[i++] = '/';
	while (com[y])
	{
		sol[i++] = com[y++];
	}
	sol[i] = '\0';
	return (sol);
}

char	*split_path(char *env, char *arg)
{
	int		i;
	char	**first;
	char	**sol;

	i = 0;
	first = ft_split(env, '=');
	sol = ft_split(first[1], ':');
	//printf("\n%s\n", sol);
	while (access(pseudo_join(sol[i], arg) , F_OK) < 0)
		i++;
	return (sol[i]);
}
/*
int main(int arg, char **args, char * const env[])
{
	if (args[0][0] == '0')
		return (0);
	if (arg != 1)
		return (0);
	char *s;

	s = find_path(env);
	printf("%s", s);
	return (0);
}
*/

