/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:47:56 by ndonaire          #+#    #+#             */
/*   Updated: 2022/06/24 12:52:39 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipexlib.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	**ft_split(char const *s, char c);
/*
int	create_file(char *s, char *const env[])
{
	int			fd;
	int			pid;
	char*const	file[] = {"touch", s, NULL};

	fd = 0;
	pid = fork();
	if (pid == 0)
		execve("/usr/bin/touch", file, env);
	else
	{
		wait(NULL);
		fd = open(s, O_WRONLY);
		return (fd);
	}
	return (fd);
}
*/

void	father(char *args[], int fd[2], char *const env[], int fd_in)
{
	int	pid;
	int	fd2;

	pid = fork();
	fd2 = 0;
	if (pid == 0)
	{
		fd2 = open(args[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd2 < 0)
			perror("Can´t open outfile");
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		dup2(fd2, 1);
		execute_b(args[3], env);
	}
	else
	{
		wait(NULL);
		close(fd_in);
		close(fd2);
		return ;
	}
}

char	*find_path(char *const env[])
{
	int		i;
	int		check;

	i = 0;
	check = checkin_path(env[i], "PATH");
	while (check == 0)
	{
		i++;
		check = checkin_path(env[i], "PATH");
	}
	return (env[i]);
}

char	*pseudo_join(char *path, char *com)
{
	char	*sol;
	int		i;
	int		y;

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
	char	**sol;
	//int		res;
	int		auxy;
	char	*k;

	auxy = 0;
	sol = ft_split(env, ':');
	auxy = 0;
	i = 0;
	k = pseudo_join(sol[i], arg);
	//k = ft_strjoin(
	while (sol[auxy])
		auxy++;
	while (sol[i] && access(k, F_OK) < 0)
	{
		//free(sol[i]);
		free(k);
		i++;
		if (sol[i])
			k = pseudo_join(sol[i], arg);
	}
	//res = i;
	i = 0;
	while (sol[i])
		free(sol[i++]);
	free(sol);
	if (i >= auxy)
	{
		free(k);
		return (NULL);
	}
	return (k);
}
