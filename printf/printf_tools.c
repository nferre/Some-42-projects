/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:28:47 by nferre            #+#    #+#             */
/*   Updated: 2021/10/23 09:31:27 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	special_case(int *nb)
{
	write(1, "-2", 2);
	*nb = (*nb + 2000000000) * -1;
}

void	putnbr_if(int nb, int *i)
{		
	*i = *i + 1;
	write(1, "-", 1);
	nb = nb * -1;
	putnbr(nb, i);
}

void	putnbr(int nb, int *i)
{
	char	b;

	b = 0;
	if (nb >= 10)
	{
		*i = *i + 1;
		putnbr(nb / 10, i);
		b = (nb % 10) + '0';
		write(1, &b, 1);
	}
	else if (nb == -2147483648)
	{
		*i = *i + 2;
		special_case(&nb);
		putnbr(nb, i);
	}
	else if (nb < 0)
		putnbr_if(nb, i);
	else
	{
		*i = *i + 1;
		b = nb + '0';
		write(1, &b, 1);
	}
}

void	putstr(char *str, int *j)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		*j = *j + 1;
		write(1, &str[i], 1);
		i++;
	}
}
