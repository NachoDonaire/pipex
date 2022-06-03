/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   papute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:54:43 by ndonaire          #+#    #+#             */
/*   Updated: 2022/06/02 18:02:54 by ndonaire         ###   ########.fr       */
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

int	main(int arg, char *args[], char *const env[])
{
	int		fd[2];
	int		pid;
	int		fd_in;

	if (arg != 5)
		return (0);
	pipe(fd);
	fd_in = open(args[1], O_RDONLY);
	if (fd_in < 0)
		perror("Can`t open infile");
	pid = fork();
//	write(1, "hoola", 5);
	if (pid == 0)
	{
		close(fd[0]);
		if (fd_in > 0)
			dup2(fd_in, 0);
		dup2(fd[1], 1);
		execute_b(args[2], env);
	}
	else
		father(args, fd, env, fd_in);
	system("leaks pipex");
	return (0);
}
