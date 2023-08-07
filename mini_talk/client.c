/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:06:38 by nferre            #+#    #+#             */
/*   Updated: 2021/11/03 13:58:22 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	numb;

	if (!str)
		return (0);
	numb = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	else
		sign = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		numb = numb * 10 + (str[i++] - '0');
	return (numb * sign);
}

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

int	send_char(int pid, char c)
{
	int	size;

	size = 0;
	while (size != 8)
	{
		usleep(100);
		if ((c >> size) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		size++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
		return (0);
	i = -1;
	pid = ft_atoi(argv[1]);
	while (argv[2][++i])
		send_char(pid, argv[2][i]);
	return (0);
}
