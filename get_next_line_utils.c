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

int	ft_putstr(char *s, int fd)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	count;
	size_t	lens1;

	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	
	if (ptr == NULL || (ft_strlen(s1) + ft_strlen(s2))  == 0)
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
	free(s1);
	return (ptr);
}

size_t	ft_strlen(char const *str)
{
	size_t	count;

	count = 0;
	if (str == NULL)
		return (0);
	while (str[count])
	{
		count++;
	}
	
	return (count);
}

size_t	ft_index(const char *word, int c)
{
	size_t				length;
	unsigned char	*ptr;

	length = 0;
	ptr = (unsigned char *) word;
	while (ptr[length] != '\0' && ptr[length] != (unsigned char) c)
	{
		length = length + 1;
	}
	if (ptr[length] == (unsigned char) c)
		return (length);
	return (0);
}

char	*ft_substr(char *s, unsigned int start, size_t len, int dele)
{
	size_t	slen;
	size_t	i;
	char	*ptr;

	if (s == NULL)
		return (NULL);
	
	slen = ft_strlen(s);
	if (start >= slen)
		len = 0;
	else if (len > slen - start)
		len = slen - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	if (dele == 1)
		free(s);
	if (i != 0)
		return (ptr);
	free(ptr);
	return (NULL);
}


