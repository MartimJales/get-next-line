/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:27:45 by mjales            #+#    #+#             */
/*   Updated: 2021/12/21 12:31:32 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*find_impostor(char *s, char *remain)
{
	size_t	i;
	size_t	j;
	char	*new;

	new = malloc(ft_strlen(s));
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		new[i] = s[i];
		i++;
	}
	new[i] = 0;
	j = 0;
	while (s[++i])
	{
		remain[j] = s[i];
		j++;
	}
	remain[j] = 0;
	return (new);
}

int	same_line(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	copy_remain(char *remain, char *s, size_t *i)
{
	size_t	j;

	j = -1;
	while (remain[++j])
	{
		s[*i] = remain[j];
		(*i)++;
	}
	return (*i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*dst;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	str = (unsigned char *)src;
	dst = (unsigned char *)dest;
	i = -1;
	while (++i < n)
		dst[i] = str[i];
	return ((void *)dst);
}
