/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:19:00 by mjales            #+#    #+#             */
/*   Updated: 2021/12/21 12:27:36 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include<stdio.h>
# include<fcntl.h>
# include<unistd.h>
# include<stdlib.h>
# include <string.h>

size_t	ft_strlen(const char *s);
char	*find_impostor(char *s, char *remain);
int		same_line(char *s);
size_t	copy_remain(char *remain, char *s, size_t *i);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_realloc(char *s, size_t new_size, size_t i);
char	*get_next_line(int fd);

#endif
