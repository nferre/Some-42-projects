/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:56:11 by nferre            #+#    #+#             */
/*   Updated: 2021/11/03 13:57:51 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	nbr_len(int n)
{
	int	i;

	if (n <= 0)
		i = 1;
	else
		i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_fill(char *str, int i, int len, int n)
{
	while (len > i)
	{
		str[len - 1] = (n % 10) + '0';
		len--;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		i;

	i = 0;
	len = nbr_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == -2147483648)
	{
		n = 147483648;
		i = 2;
		str[0] = '-';
		str[1] = '2';
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		i = 1;
	}
	ft_fill(str, i, len, n);
	str[len] = '\0';
	return (str);
}
