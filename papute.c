/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   papute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:54:43 by ndonaire          #+#    #+#             */
/*   Updated: 2022/05/18 14:03:48 by ndonaire         ###   ########.fr       */
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

void	father(int fd2, char *s[], int fd[2], char *const env[])
{
	if (fd2 < 0)
		fd2 = create_file(s[1], env);
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	dup2(fd2, 1);
	execute_b(s[0], env);
}

void	son(int fd[2], int fd_in, char *s[], char *const env[])
{
	close(fd[0]);
	dup2(fd_in, 0);
	dup2(fd[1], 1);
	execute_a(s[2], env, s[3]);
}


int	main(int arg, char *args[], char *const env[])
{
	int		fd[2];
	int		pid;
	int		fd2;
	int		fd_in;
	char	*s[4];

	if (arg != 5)
		return (0);
	pipe(fd);
	pid = fork();
	fd2 = open(args[4], O_WRONLY);
	fd_in = open(args[1], O_RDONLY);
	s[0] = args[3];
	s[1] = args[4];
	s[2] = args[2];
	s[3] = args[1];
	if (fd_in < 0)
		return (0);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd_in, 0);
		dup2(fd[1], 1);
		execute_a(args[2], env, args[1]);
	}
	else
	{
		while (1);
		father(fd2, s, fd, env);
	}
	return (0);
}
