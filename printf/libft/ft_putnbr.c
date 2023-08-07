/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:21:33 by nferre            #+#    #+#             */
/*   Updated: 2021/10/23 09:32:20 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	special_case(int *nb);

void	ft_putnbr(int nb)
{
	char	b;

	b = 0;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		b = (nb % 10) + '0';
		write(1, &b, 1);
	}
	else if (nb == -2147483648)
	{
		special_case(&nb);
		ft_putnbr(nb);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
		ft_putnbr(nb);
	}
	else
	{
		b = nb + '0';
		write(1, &b, 1);
	}
}

void	special_case(int *nb)
{	
	write(1, "-2", 2);
	*nb = (*nb + 2000000000) * -1;
}
