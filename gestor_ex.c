/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestor_ex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:17:11 by ndonaire          #+#    #+#             */
/*   Updated: 2022/05/23 10:17:38 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipexlib.h"

char	*find_pwd(char *const env[])
{
	int	i;
	int	check;

	i = 0;
	check = checkin_path(env[i], "PWD");
	while (check == 0)
	{
		i++;
		check = checkin_path(env[i], "PWD");
	}
	return (env[i]);
}

char	*join_pwd(char *env, char *com)
{
	int		i;
	char	**spliteo;
	char	**path;
	int		y;
	char	*sol;

	i = 0;
	y = 0;
	path = ft_split(env, '=');
	spliteo = ft_split(com, '/');
	sol = malloc(sizeof(char) * (lens(spliteo[1]) + lens(env) + 1));
	while (path[1][i])
	{
		sol[i] = path[1][i];
		i++;
	}
	sol[i++] = '/';
	while (spliteo[1][y])
	{
		sol[i++] = spliteo[1][y++];
	}
	sol[i] = '\0';
	return (sol);
}
/*
int main(int arg, char **args, char *const env[])
{
	if (!arg)
		return (0);
	if (!args)
		return (0);
	char *path;
	char *help;
	char *com = "./ls.sh";
	path = find_pwd(env);
	help = join_pwd(path, com);
	printf("%s", help);
	return (0);
}*/
