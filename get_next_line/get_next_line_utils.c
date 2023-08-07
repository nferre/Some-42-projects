/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 09:57:04 by nferre            #+#    #+#             */
/*   Updated: 2021/10/26 18:51:52 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	while (*s != c)
		if (*s++ == '\0')
			return (NULL);
	*s++ = '\0';
	return (s);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*dest;
	int		len_s1;
	int		len_s2;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	dest = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (dest == NULL)
		return (dest);
	while (s1[++i])
		dest[i] = s1[i];
	while (*(s2))
		dest[i++] = *(s2++);
	dest[i] = '\0';
	free(s1);
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*copy_s1;
	int		i;

	if (!src)
		return (0);
	copy_s1 = malloc(ft_strlen(src) + 1);
	if (copy_s1 == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		copy_s1[i] = src[i];
		i++;
	}
	copy_s1[i] = '\0';
	return (copy_s1);
}

char	*ft_strcpy(char *dst, char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (dst);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	i = -1;
	while (++i != len)
		*(ptr++) = (unsigned char)c;
	return (b);
}
