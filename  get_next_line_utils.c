/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmacha <antmacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 13:54:30 by antmacha          #+#    #+#             */
/*   Updated: 2026/11/13 17:16:10 by antmacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	count;

	if (s == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	count = 0;
	while (s[count])
	{
		write(fd, &s[count], 1);
		count++;
	}
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	count;
	size_t	lens1;

	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ptr == NULL)
		return (NULL);
	count = 0;
	lens1 = ft_strlen(s1);
	while (count < lens1)
	{
		ptr[count] = s1[count];
		count++;
	}
	while (count < lens1 + ft_strlen(s2))
	{
		ptr[count] = s2[count - lens1];
		count++;
	}
	ptr[count] = '\0';
	return (ptr);
}

size_t	ft_strlen(char const *str)
{
	size_t	count;

	count = 0;
	while (str)
	{
		count++;
	}
	return (count);
}

char	*ft_strchr(const char *word, int c)
{
	int		length;
	char	*ptr;

	length = 0;
	ptr = (char *) word;
	while (ptr[length] != '\0' && ptr[length] != (unsigned char) c)
	{
		length = length + 1;
	}
	if (ptr[length] == (unsigned char) c)
		return (&ptr[length]);
	return (NULL);
}
