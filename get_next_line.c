/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:27:48 by mjales            #+#    #+#             */
/*   Updated: 2021/12/21 12:28:32 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char *s, size_t new_size, size_t i)
{
	char	*newptr;

	newptr = malloc(new_size);
	ft_memcpy(newptr, s, i);
	free(s);
	return (newptr);
}

// Precisamos agora de guardar o que lemos, e não vamos voltar a ler
// Essa variável é que em principio vai ser static i think
char	*get_next_line(int fd)
{
	static char	remain[BUFFER_SIZE];
	char		*s;
	size_t		i;
	size_t		size;

	i = 0;
	size = BUFFER_SIZE * 2;
	s = malloc(size);
	copy_remain(remain, s, &i);
	while (i += read(fd, s + i, BUFFER_SIZE))
	{
		if (same_line(s))
			break ;
		if (i + BUFFER_SIZE >= size)
		{
			size *= 2;
			s = ft_realloc(s, size, i);
		}
	}
	s = find_impostor(s, remain);
	return (s);
}

int	main(void)
{
	int		fd;
	char	*s;

	s = malloc(100);
	fd = open("file.txt", O_RDONLY);
	while (strcmp(s = get_next_line(fd), ""))
		printf("gnl: |%s|\n", s);
}
