#ifndef PIPEXLIB_H
# define PIPEXLIB_H
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		create_file(char *s, char * const env[]);

#endif
