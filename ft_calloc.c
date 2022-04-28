/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:13:58 by ndonaire          #+#    #+#             */
/*   Updated: 2022/04/28 12:21:05 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pipexlib.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*p;
	unsigned long	i;

	i = 0;
	p = (void *)malloc(nmemb * size);
	if (!p)
		return (0);
	while (i < nmemb * size)
	{
		((char *)p)[i] = '\0';
		i = i + 1;
	}
	return (p);
}
