/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   papute_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:44:20 by ndonaire          #+#    #+#             */
/*   Updated: 2022/06/02 18:04:41 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	if (!sol || !args)
		return (NULL);
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
	int	i;
	int	y;

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

/*
void	join_file(char *s[], char *args, int i)
{
	//char		*file;
	int		y;

	y = 0;
	//file = malloc(sizeof(char) * (lens(args) + 1));
	while (args[y])
	{
		s[i][y] = args[y];
		y++;
	}
	s[i++][y] = '\0';
	s[i] = NULL;
}
*/
void	execute_a(char *str, char	*const env[], char *args)
{
	char	*com;
	char	**spliteao;
	char	*help;
	char	*b;

	spliteao = ft_split(str, ' ');
	if (checkin_path(str, ".") == 0 && checkin_path(str, "/") == 0)
	{
		help = find_path(env);
		b = split_path(help, spliteao[0]);
		com = join_path(b, spliteao[0]);
	}
	else if (checkin_path(str, ".") == 1)
		com = spliteao[0];
	else if (checkin_path(str, "/") == 1)
		com = spliteao[0];
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
	char	*b;
	char	*help;

	spliteao = ft_split(str, ' ');
	if (checkin_path(str, ".") == 0 && checkin_path(str, "/") == 0)
	{
		help = find_path(env);
		b = split_path(help, spliteao[0]);
		com = join_path(b, spliteao[0]);
	}
	else if (checkin_path(str, ".") == 1)
		com = spliteao[0];
	else if (checkin_path(str, "/") == 1)
		com = spliteao[0];
	if (execve(com, spliteao, env) == -1)
	{
		perror("command not found");
		exit(-1);
	}
}
