/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:16:16 by nferre            #+#    #+#             */
/*   Updated: 2021/10/21 12:13:59 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = ft_strlen((char *)s) + 1;
	dest = malloc(i + 1);
	if (!dest)
		return (NULL);
	i = -1;
	while (s[++i])
	{
		dest[i] = (*f)(i, s[i]);
	}
	dest[i] = '\0';
	return (dest);
}
