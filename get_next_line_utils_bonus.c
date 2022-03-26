/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:27:45 by mjales            #+#    #+#             */
/*   Updated: 2022/03/26 14:11:56 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	clean_buffer(char *buffer)
{
	int		i;
	int		sobra;

	i = -1;
	sobra = -1;
	while (buffer[++i])
	{
		if (buffer[i] == '\n' && sobra == -1)
			sobra = 0;
		else if (sobra != -1)
			buffer[sobra++] = buffer[i];
		buffer[i] = 0;
	}
}

char	ft_strchr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	return (s[i]);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*new;

	new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i++] = s2[j];
		if (s2[j++] == '\n')
			break ;
	}
	new[i] = 0;
	if (s1)
		free(s1);
	return (new);
}
