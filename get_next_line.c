/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:27:48 by mjales            #+#    #+#             */
/*   Updated: 2022/03/05 19:16:33 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	if (!*temp)
		return (NULL);
	return (temp);
}

char	*analise(int fd, char *resto)
{
	int		control;
	char	*analise;

	if (!resto)
	{
		resto = malloc(1);
		*resto = 0;
	}
	analise = malloc(BUFFER_SIZE + 1);
	control = 1;
	while (control > 0)
	{
		control = read(fd, analise, BUFFER_SIZE);
		if (control == -1 || !control)
			break ;
		analise[control] = 0;
		resto = ft_free(resto, analise);
		if (ft_strchr(analise, '\n'))
			break ;
	}
	free(analise);
	if (!*resto)
	{
		free(resto);
		return (NULL);
	}
	return (resto);
}

int	find_iter(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != 0)
		i++;
	return (i);
}

char	*clean_buffer(char *buffer, int i)
{
	char	*temp;
	int		j;

	j = ft_strlen(buffer) - i;
	temp = malloc(j + 1);
	ft_strlcpy(temp, buffer + i + 1, j + 1);
	free(buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*s;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = analise(fd, buffer);
	if (!buffer || !*buffer)
	{
		free(buffer);
		return (NULL);
	}
	i = find_iter(buffer);
	s = malloc(i + 1);
	ft_strlcpy(s, buffer, i + 2);
	buffer = clean_buffer(buffer, i);
	if (!*s)
	{
		free(s);
		if (*buffer)
			free(buffer);
		return (NULL);
	}
	return (s);
}
