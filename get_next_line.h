/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:40:07 by arebelo           #+#    #+#             */
/*   Updated: 2022/02/07 16:35:13 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

# include <stdio.h>
# include <unistd.h>

char			*get_next_line(int fd);
void			ft_putstr(char *str);
char			*ft_strndup(char *s1, size_t n);
char			*ft_strjoin(char *s1, char *s2);
char			*first_line(int fd, char buf[BUFFER_SIZE], int *i);
char			*following_lines(int fd, char buf[BUFFER_SIZE], int *i);
unsigned long	counter(char *buf, int j);

#endif
