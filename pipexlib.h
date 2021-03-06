/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexlib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:52:50 by ndonaire          #+#    #+#             */
/*   Updated: 2022/07/10 17:57:46 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEXLIB_H
# define PIPEXLIB_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>

char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		create_file(char *s, char *const env[]);
int		bin_or_usr(char *s);
int		lens(char *s);
void	execute_a(char *str, char *const env[], char *args);
void	execute_b(char *str, char *const env[]);
char	*check_join(char *s);
char	*join_bin(char *s);
char	*find_path(char *const env[]);
char	*split_path(char *env, char *arg);
char	check(char **sol);
char	*join_path(char *sol, char *args);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strlen(const char *s);
int		checkin_path(char *s, char *find);
int		father(char *args[], int fd[2], char *const env[], int fd_in);
char	*find_pwd(char *const env[]);
char	*join_pwd(char *env, char *com);
int		files_error(int i);
char	*freeear(char **sol, char *k);

#endif
