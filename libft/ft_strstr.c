/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:00:06 by nferre            #+#    #+#             */
/*   Updated: 2021/10/20 16:12:30 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (needle[n])
		n++;
	if (n == 0)
		return ((char *)haystack);
	while (*haystack)
	{
		while (haystack[i] == needle[i])
		{
			i++;
			if (i == n)
				return ((char *)haystack);
		}
		i = 0;
		haystack++;
	}
	return (0);
}
