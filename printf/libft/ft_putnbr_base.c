/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:21:11 by nferre            #+#    #+#             */
/*   Updated: 2021/10/22 09:39:50 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_base(int nbr, char *base)
{
	int		l_base;

	l_base = ft_strlen(base);
	if (nbr % l_base < nbr)
	{
		ft_putnbr_base((nbr / l_base), base);
		ft_putchar(base[nbr % l_base]);
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr_base((nbr * -1), base);
	}
	else
		ft_putchar(base[nbr % l_base]);
}
