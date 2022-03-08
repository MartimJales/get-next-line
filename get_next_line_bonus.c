/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:27:48 by mjales            #+#    #+#             */
/*   Updated: 2022/03/08 18:53:41 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*buffer[FD_SIZE];
	char		*s;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[fd] = analise(fd, buffer[fd]);
	if (!buffer[fd] || !*buffer[fd])
	{
		free(buffer[fd]);
		return (NULL);
	}
	i = find_iter(buffer[fd]);
	s = malloc(i + 1);
	ft_strlcpy(s, buffer[fd], i + 2);
	buffer[fd] = clean_buffer(buffer[fd], i);
	if (!*s)
	{
		free(s);
		if (*buffer[fd])
			free(buffer[fd]);
		return (NULL);
	}
	return (s);
}


// int main()
// {
// 	get_next_line(0);
// }
