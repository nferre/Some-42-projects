/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:58:29 by nferre            #+#    #+#             */
/*   Updated: 2021/11/03 14:04:16 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);

void	show_pid(void)
{
	char	*tmp_pid;

	tmp_pid = ft_itoa(getpid());
	write(1, "pid: ", 5);
	write(1, tmp_pid, ft_strlen(tmp_pid));
	write(1, "\n", 1);
	free(tmp_pid);
}

int	binary_to_decimal(char buf[7])
{
	int	i;
	int	final_nb;
	int	power;

	i = 0;
	final_nb = 0;
	power = 1;
	while (i != 8)
	{
		final_nb += (buf[i++] * power);
		power *= 2;
	}
	write(1, &final_nb, 1);
	return (final_nb);
}

void	my_handler(int signum)
{
	static int	counter;
	static char	buf[8];
	int			i;

	i = 0;
	if (signum == SIGUSR1)
		buf[counter++] = 1;
	else if (signum == SIGUSR2)
		buf[counter++] = 0;
	if (counter == 8)
	{
		counter = 0;
		binary_to_decimal(buf);
	}
}

int	main(void)
{
	show_pid();
	if (signal(SIGUSR1, my_handler) == SIG_ERR)
		write(1, "Error sig1\n", 11);
	else if (signal(SIGUSR2, my_handler) == SIG_ERR)
		write(1, "Error sig2\n", 11);
	while (1)
		sleep(1);
}
