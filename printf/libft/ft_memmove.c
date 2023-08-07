/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:51:27 by nferre            #+#    #+#             */
/*   Updated: 2021/10/20 11:44:58 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;
	size_t			i;

	if (dst == src)
		return (dst);
	if (!dst && !src)
		return (0);
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	i = -1;
	if (ptr_dst > ptr_src)
		while (len-- > 0)
			ptr_dst[len] = ptr_src[len];
	else
		while (++i < len)
			ptr_dst[i] = ptr_src[i];
	return (dst);
}
