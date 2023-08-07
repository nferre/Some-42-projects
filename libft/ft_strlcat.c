/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:32:07 by nferre            #+#    #+#             */
/*   Updated: 2021/10/21 15:54:17 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!src || !dst)
		return (0);
	i = 0;
	j = 0;
	k = 0;
	while (dst[i])
		i++;
	while (src[k])
		k++;
	if (dstsize <= i)
		k += dstsize;
	else
		k += i;
	while (src[j] && (i + 1 < dstsize))
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (k);
}
