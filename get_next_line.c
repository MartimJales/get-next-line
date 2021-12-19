// C program to illustrate
// open system call
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

extern int	g_errno;

char	*find_impostor(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	s[i] = 0;
	return (s);
}

//This function have a problem because if
//BUFFER_SIZE=1 we need a loop to read the file
// until we find a new_line for the return
char	*get_next_line(int fd)
{
	char		*c;
	static int	sz = 0;

	c = malloc(BUFFER_SIZE + 1);
	sz += read(fd, c, BUFFER_SIZE);
	c[sz] = 0;
	printf("sz: %d\n", sz);
	return (find_impostor(c));
}

int	main(void)
{
	int	fd;
	int	teste;

	fd = open("file.txt", O_RDONLY);
	teste = -1;
	while (++teste < 5)
	{
		printf("gnl: %s\n", get_next_line(fd));
	}
}
