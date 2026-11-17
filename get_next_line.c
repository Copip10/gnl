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


char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0' && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

// void	fill_the_line(char *full_line, char * buff, ssize_t count)
// {



// }
char	*get_next_line(int fd)
{
	ssize_t			count;
	char		*buff;
	char	*full_line;
	char *todele;
	static char	*tmp;
	
	count = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (buff == NULL)
		return NULL;

	full_line = ft_substr(tmp, 0,  BUFFER_SIZE, 1);
	tmp = NULL;
	if (ft_strchr(full_line, '\n') != NULL)
	{
		tmp = ft_substr(full_line, ft_index(full_line, '\n') + 1, BUFFER_SIZE, 0);
		free(buff);
		return ft_substr(full_line, 0,  ft_index(full_line, '\n') + 1, 1);
	}
	else
	{	
		count = read(fd, buff, BUFFER_SIZE);
		while (count > 0)
		{
			buff[count] = '\0';
			if (ft_strchr(buff, '\n') != NULL)
			{
				tmp = ft_substr(buff, ft_index(buff, '\n') + 1, BUFFER_SIZE, 0);
				todele = ft_substr(buff, 0 , ft_index(buff, '\n') + 1, 0);
				full_line = ft_strjoin(full_line, todele);
				free(todele);
				free(buff);
				return (full_line);
			}
			else
				full_line = ft_strjoin(full_line, buff);
			count = read(fd, buff, BUFFER_SIZE);
		}
		free(buff);
		if (count == 0)
		{
			free(tmp);
			tmp = NULL;
			return full_line;
		}
		if (count < 0)
		{
			free(tmp);
			free(full_line);
			tmp = NULL;
			return (NULL);
		}
	}
	return (NULL);
}

int	main(void)
{
	int		fd;
	char	*line;
	int	count = 0;
	fd = open("test1.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		//ft_putstr(line, 1);
		printf("%s", line);
		free(line);
		count++;
	}
	
	close(fd);
	return (0);
}

// int	main(void)
// {
// 	char	*hel = NULL;
// 	static char	*line = "line";


// 	printf("%s \n", ft_strjoin(hel, line));
	
// 	return 1;
// }
