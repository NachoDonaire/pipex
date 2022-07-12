/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   papute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:54:43 by ndonaire          #+#    #+#             */
/*   Updated: 2022/07/12 16:43:29 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include "pipexlib.h"

int	lens(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*freeear(char **sol, char *k)
{
	int	i;

	i = 0;
	while (sol[i])
		free(sol[i++]);
	free(sol);
	if (!k)
		return (NULL);
	return (k);
}

/*
char	*check_join(char *s)
{
	int		i;
	int		z;
	char	*b;
	char	*sol;

	i = 0;
	z = 0;
	b = "/bin/";
	sol = malloc((lens(s) + lens(b) + 1) * sizeof(char));
	while (b[i])
		sol[z++] = b[i++];
	i = 0;
	while (s[i])
		sol[z++] = s[i++];
	sol[z] = '\0';
	return (sol);
}

char	*join_bin(char *s)
{
	char	*b;
	int		i;
	char	*sol;
	int		z;
	int		check;

	b = check_join(s);
	check = access(b, F_OK);
	if (check == 0)
		b = "/bin/";
	else if (check != 0)
		b = "/usr/bin/";
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
*/

int	files_error(int i)
{
	if (i == 0)
		perror("Can´t open infile");
	else
		perror("Can´t open outfile");
	return (0);
}

void	zero_pid(int fd[2], int fd_in, char **args, char *const env[])
{
	close(fd[0]);
	if (fd_in > 0)
		dup2(fd_in, 0);
	dup2(fd[1], 1);
	execute_b(args[2], env);
}

int	main(int arg, char *args[], char *const env[])
{
	int		fd[2];
	int		pid;
	int		fd_in;
	int		check;

	if (arg != 5)
		return (0);
	pipe(fd);
	check = 0;
	fd_in = open(args[1], O_RDONLY);
	if (fd_in < 0)
		return (files_error(0));
	pid = fork();
	if (pid == 0)
		zero_pid(fd, fd_in, args, env);
	else
	{
		check = father(args, fd, env, fd_in);
		if (check == 0)
			return (0);
	}
	return (0);
}
