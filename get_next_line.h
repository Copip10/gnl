/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmacha <antmacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 13:45:17 by antmacha          #+#    #+#             */
/*   Updated: 2026/11/13 17:04:25 by antmacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

# include <unistd.h>
# include <string.h>
# include <stdint.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

size_t	ft_strlen(char const *str);
char	*get_next_line(int fd);
size_t	ft_index(const char *word, int c);
char	*ft_strjoin(char *s1, char *s2);
int	ft_putstr(char *s, int fd);
char	*ft_substr(char *s, unsigned int start, size_t len, int dele);
char	*ft_strchr(const char *s, int c);

#endif
