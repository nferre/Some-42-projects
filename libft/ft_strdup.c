/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:27:24 by nferre            #+#    #+#             */
/*   Updated: 2021/10/21 15:52:27 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *src)
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
