/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:51:28 by arebelo           #+#    #+#             */
/*   Updated: 2022/02/07 16:38:37 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

unsigned long	counter(char *buf, int j)
{
	unsigned long	i;

	i = 0;
	while (buf[i] && buf[i] != '\n' && i + j < (BUFFER_SIZE - 1))
		i++;
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter])
		counter++;
	return (counter);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	counter;

	if (dst == 0 && src == 0)
		return (0);
	counter = 0;
	while (counter < n)
	{
		((char *)dst)[counter] = ((char *)src)[counter];
		counter++;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*ptr;
	unsigned long	counter;
	unsigned long	size;
	char			*temp;

	temp = ft_strndup(s1, ft_strlen(s1));
	free(s1);
	counter = 0;
	if (!s1 || !s2)
		return (0);
	size = ft_strlen(temp) + ft_strlen(s2);
	ptr = malloc(size + 1);
	if (!ptr)
		return (0);
	ft_memcpy(ptr, temp, ft_strlen(temp));
	ft_memcpy(&ptr[ft_strlen(temp)], s2, ft_strlen(s2));
	ptr[size] = '\0';
	free(temp);
	free(s2);
	return (ptr);
}

char	*ft_strndup(char *s1, size_t n)
{
	char			*ptr;
	unsigned long	counter;

	counter = 0;
	ptr = malloc((n + 1) * sizeof(char));
	if (!ptr)
		return (0);
	while (counter < n)
	{
		ptr[counter] = s1[counter];
		counter++;
	}
	ptr[counter] = '\0';
	return (ptr);
}
