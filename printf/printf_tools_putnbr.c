/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tools_putnbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 09:17:53 by nferre            #+#    #+#             */
/*   Updated: 2021/10/23 09:31:15 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	p_putnbr_base(unsigned long nbr, char *base, int *i)
{
	unsigned long	l_base;

	l_base = ft_strlen(base);
	if (nbr % l_base < nbr)
	{
		*i = *i + 1;
		p_putnbr_base((nbr / l_base), base, i);
		ft_putchar(base[nbr % l_base]);
	}
	else if (nbr < 0)
	{
		*i = *i + 1;
		ft_putchar('-');
		p_putnbr_base((nbr * -1), base, i);
	}
	else
	{
		*i = *i + 1;
		ft_putchar(base[nbr % l_base]);
	}
}

void	putnbr_base(int n, char *base, int *i)
{
	int				l_base;
	unsigned int	nbr;

	nbr = (unsigned int)n;
	l_base = ft_strlen(base);
	if (nbr % l_base < nbr)
	{
		*i = *i + 1;
		putnbr_base((nbr / l_base), base, i);
		ft_putchar(base[nbr % l_base]);
	}
	else if (nbr < 0)
	{
		*i = *i + 1;
		ft_putchar('-');
		putnbr_base((nbr * -1), base, i);
	}
	else
	{
		*i = *i + 1;
		ft_putchar(base[nbr % l_base]);
	}
}

void	u_putnbr_base(unsigned int nbr, char *base, int *i)
{
	int		l_base;

	l_base = ft_strlen(base);
	if (nbr % l_base < nbr)
	{
		*i = *i + 1;
		putnbr_base((nbr / l_base), base, i);
		ft_putchar(base[nbr % l_base]);
	}
	else if (nbr < 0)
	{
		*i = *i + 1;
		ft_putchar('-');
		putnbr_base((nbr * -1), base, i);
	}
	else
	{
		*i = *i + 1;
		ft_putchar(base[nbr % l_base]);
	}
}
