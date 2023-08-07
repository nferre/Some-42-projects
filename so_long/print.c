/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:32:52 by nferre            #+#    #+#             */
/*   Updated: 2021/11/01 10:46:33 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	print_tab(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->tab[i])
		printf("%s\n", vars->tab[i++]);
}

int	rectangular_loop(int i, int ret, int fd, char *buf)
{
	int	j;

	j = 0;
	while (ret == 1)
	{
		ret = read(fd, buf, 1);
		j++;
		if (buf[0] == '\n')
		{
			if (j != i)
			{
				printf("Error\nMap is not rectangular\n");
				return (-1);
			}	
			j = 0;
		}
	}
	if (j != i)
	{
		printf("Error\nMap is not rectangular\n");
		return (-1);
	}
	return (0);
}

int	check_ber(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	i--;
	if (map[i] == 'r' && map[i - 1] == 'e' && map[i - 2] == 'b'
		&& map[i - 3] == '.')
		return (0);
	printf("Error\nfile is not a .ber\n");
	return (-1);
}
