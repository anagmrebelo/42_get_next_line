/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:42:37 by arebelo           #+#    #+#             */
/*   Updated: 2022/02/07 17:59:24 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean_buffer(char buf[BUFFER_SIZE])
{
	unsigned long	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buf[i] = 0;
		i++;
	}
}

int	read_aux(int fd, char buf[BUFFER_SIZE], char *result)
{
	ssize_t	ret;

	clean_buffer(buf);
	ret = read(fd, buf, BUFFER_SIZE);
	if (ret == -1)
	{
		free(result);
		result = 0;
		return (0);
	}
	else if (ret == 0)
		return (0);
	else
		return (1);
}

char	*get_next_line(int fd)
{
	static int	i = 0;
	char		*result;
	static char	buf[BUFFER_SIZE];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	if (i == 0)
	{	
		clean_buffer(buf);
		result = first_line(fd, buf, &i);
	}
	else
	{
		if (i >= BUFFER_SIZE)
			result = first_line(fd, buf, &i);
		else
		{
			if (buf[i] == 0)
				return (0);
			result = following_lines(fd, buf, &i);
		}
	}
	return (result);
}

char	*first_line(int fd, char buf[BUFFER_SIZE], int *i)
{
	int		ret;
	char	*result;
	char	*temp;

	*i = 0;
	clean_buffer(buf);
	ret = read(fd, buf, BUFFER_SIZE);
	if (ret == -1 || ret == 0)
		return (0);
	result = ft_strndup(buf, (counter(buf, *i) + 1));
	while (counter(buf, *i) == (BUFFER_SIZE - 1) && buf[BUFFER_SIZE - 1] != '\n'
		&& buf[BUFFER_SIZE - 1] != '\0')
	{
		if (!read_aux(fd, buf, result))
			return (result);
		temp = ft_strndup(buf, (counter(buf, *i) + 1));
		result = ft_strjoin(result, temp);
	}
	*i = counter(buf, *i) + 1;
	return (result);
}

char	*following_lines(int fd, char buf[BUFFER_SIZE], int *i)
{
	char	*result;
	char	*temp;

	result = ft_strndup(&buf[*i], counter(&buf[*i], *i) + 1);
	*i += counter(&buf[*i], *i) + 1;
	if (buf[*i - 1] != '\n' && buf[*i - 1] != '\0')
	{
		*i = 0;
		if (!read_aux(fd, buf, result))
			return (result);
		temp = ft_strndup(buf, counter(buf, *i) + 1);
		result = ft_strjoin(result, temp);
		while (counter(buf, *i) == (BUFFER_SIZE - 1)
			&& buf[BUFFER_SIZE - 1] != '\n' && buf[BUFFER_SIZE - 1] != '\0')
		{	
			if (!read_aux(fd, buf, result))
				return (result);
			temp = ft_strndup(buf, counter(buf, *i) + 1);
			result = ft_strjoin(result, temp);
		}
		*i = counter(buf, *i) + 1;
	}
	return (result);
}
