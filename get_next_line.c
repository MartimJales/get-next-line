/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:27:48 by mjales            #+#    #+#             */
/*   Updated: 2022/03/01 15:50:04 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	size;

	size = ft_strlen ((char *)s);
	i = 0;
	if (!s)
		return (NULL);
	while (i <= size)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(&s[i]));
		i++;
	}
	return (NULL);
}

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin_kitado(buffer, buf);
	// free em memoria nao alocada
	if (*buffer)
		free(buffer);
	free(buf);
	buffer = NULL;
	return (temp);
}

char	*ft_strjoin_kitado(char const *s1, char const *s2)
{
	size_t	i;
	size_t	size1;
	size_t	size2;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen((char *)s1);
	size2 = ft_strlen((char *)s2);
	new = malloc(size1 + size2 + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (++i < size1)
		new[i] = s1[i];
	while (i < size1 + size2)
	{
		new[i] = s2[i - size1];
		i++;
	}
	new[i] = 0;
	return (new);
}

char	*analise(int fd, char *resto)
{
	int		control;
	char	*analise;

	if (!resto)
	{
		printf("princesa\n");
		resto = malloc(1);
		*resto = 0;
	}
	analise = malloc(BUFFER_SIZE + 1);
	control = 1;
	while (control > 0)
	{
		control = read(fd, analise, BUFFER_SIZE);
		if (control == -1)
		{
			free(analise);
			return (NULL);
		}
		else if (control == 0)
			break ;
		analise[control] = 0;
		resto = ft_free(resto, analise);
		if (ft_strchr(analise, '\n'))
			break ;
	}
	free(analise);
	analise = NULL;
	return (resto);
}

char	*clean_line(char **buffer)
{
	char	*line;
	char	*old;
	int		i;

	old = *buffer;
	i = 0;
	while ((**buffer) != '\n' && (**buffer) != 0)
	{
		i++;
		(*buffer)++;
	}
	line = malloc(i + 1);
	ft_strlcpy(line, *buffer - i, i + 2);
	(*buffer)++;
	// free em memoria nao alocada
	old[i] = 0;
	free(old);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = analise(fd, buffer);
	if (!buffer)
		return (NULL);
	s = clean_line(&buffer);
	// buffer = get_remain(buffer);
	return (s);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*s;

// 	s = malloc(100);
// 	fd = open("file.txt", O_RDONLY);
// 	while (strcmp(s = get_next_line(fd), ""))
// 		printf("gnl: |%s|\n", s);
// }

// copy_remain(remain, s, &i);
// 	while (i += read(fd, s + i, BUFFER_SIZE))
// 	{
// 		if (same_line(s))
// 			break ;
// 		if (i + BUFFER_SIZE >= size)
// 		{
// 			size += BUFFER_SIZE;
// 			s = ft_realloc(s, size, i);
// 		}
// 	}
// 	s = find_impostor(s, remain);
