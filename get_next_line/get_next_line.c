/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:38:49 by nferre            #+#    #+#             */
/*   Updated: 2021/10/26 18:51:35 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*malloc_line(char *line, size_t *read_len)
{
	*read_len = BUFFER_SIZE;
	line = malloc(sizeof(char) * 1);
	line[0] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	char			*line;
	char			*looking_for_n;
	size_t			read_len;

	line = NULL;
	line = malloc_line(line, &read_len);
	while (BUFFER_SIZE > 0 && line && !read(fd, buf, 0))
	{
		looking_for_n = ft_strchr(buf, '\n');
		line = ft_strjoin(line, buf);
		if (looking_for_n)
		{
			ft_strcpy(buf, looking_for_n);
			return (ft_strjoin(line, "\n"));
		}
		ft_memset(buf, 0, BUFFER_SIZE);
		if (read_len != BUFFER_SIZE)
			return (line);
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len < 1 && line[0] == '\0')
			break ;
	}
	free(line);
	return (NULL);
}
