/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmacha <antmacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 13:44:56 by antmacha          #+#    #+#             */
/*   Updated: 2026/11/13 17:17:16 by antmacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 7
#endif

char	*get_next_line(int fd)
{
	int			count;
	char		*buff;
	static char	*prev;
	static char	*to_free;

	if (fd == -1 || BUFFER_SIZE <= 0 || (buff = malloc(BUFFER_SIZE + 1)) == NULL)
		return (NULL);
	while ((count = read(fd, buff, BUFFER_SIZE)) > 0 && ft_strchr(buff, '\n') == NULL)
	{
		//ft_putstr_fd("salut", 1);
		buff[count] = '\0';
		prev = ft_strjoin(prev, buff);
	}
	free(buff);
	return (prev);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test1.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_putstr_fd(line, 1);
		free(line);
	}
	close(fd);
	return (0);
}
