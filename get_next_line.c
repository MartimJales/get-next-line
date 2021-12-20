// C program to illustrate
// open system call
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include <string.h>

extern int	g_errno;

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

// Precisamos agora de guardar o que lemos, e não vamos voltar a ler
// Essa variável é que em principio vai ser static i think
char	*get_next_line(int fd)
{
	static char	remain[BUFFER_SIZE];
	char		*s;
	size_t		sz;
	size_t		j;

	sz = 0;
	j = 0;
	s = malloc(100);
	while (remain[j])
	{
		s[sz] = remain[j];
		sz++;
		j++;
	}
	while (sz += read(fd, s + sz, BUFFER_SIZE))
	{
		if (same_line(s))
			break ;
	}
	s = find_impostor(s, remain);
	//printf("resto: %s\n", remain);
	return (s);
}

int	main(void)
{
	int	fd;
	//int	teste;
	char	*s;

	s = malloc(100);
	fd = open("file.txt", O_RDONLY);
	//teste = 0;
	while (strcmp(s = get_next_line(fd), ""))
	{
		//printf("===line(%d)===\n", teste);
		printf("gnl: |%s|\n", s);
		//teste++;
	}
}
