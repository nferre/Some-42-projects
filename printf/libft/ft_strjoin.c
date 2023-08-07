/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 22:00:29 by nferre            #+#    #+#             */
/*   Updated: 2021/10/21 14:28:56 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
	return (dest);
}
