/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 08:51:13 by nferre            #+#    #+#             */
/*   Updated: 2021/11/01 09:22:59 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	check_nb_char(t_vars *vars, char *map)
{
	char	buf[1];
	int		fd;
	int		ret;

	vars->nb_exit = 0;
	vars->collec = 0;
	fd = open(map, O_RDONLY);
	ret = 1;
	while (ret == 1)
	{
		ret = read(fd, buf, 1);
		if (buf[0] == 'P')
			vars->nb_player = vars->nb_player + 1;
		else if (buf[0] == 'E')
			vars->nb_exit = vars->nb_exit + 1;
		else if (buf[0] == 'C')
			vars->collec = vars->collec + 1;
	}
	if (vars->nb_player != 1)
		return (-1);
	else if (vars->nb_exit < 1)
		return (-2);
	else if (vars->collec < 1)
		return (-3);
	return (0);
}

int	check_char(char *map)
{
	char	buf[1];
	int		fd;
	int		ret;

	fd = open(map, O_RDONLY);
	ret = 1;
	while (ret == 1)
	{
		ret = read(fd, buf, 1);
		if (buf[0] != 'P' && buf[0] != '1' && buf[0] != '0' && buf[0] != 'E'
			&& buf[0] != 'C' && buf[0] != '\n')
		{
			printf("Error\nInvalid char in map\n");
			return (-1);
		}
	}
	return (0);
}

int	check_if_rectangular(char *map)
{
	char	buf[1];
	int		fd;
	int		ret;
	int		i;

	i = 0;
	ret = 1;
	fd = open(map, O_RDONLY);
	buf[0] = '\0';
	while (buf[0] != '\n')
	{
		ret = read(fd, buf, 1);
		i++;
	}
	return (rectangular_loop(i, ret, fd, buf));
}

int	check_walls(t_vars *vars)
{
	int	i;
	int	j;

	j = -1;
	i = -1;
	vars->collec = 0;
	vars->nb_moves = 0;
	while (vars->tab[0][++j])
		if (vars->tab[0][j] != '1')
			return (-1);
	while (vars->tab[++i])
		if (vars->tab[i][0] != '1')
			return (-1);
	j = -1;
	while (vars->tab[i - 1][++j])
		if (vars->tab[i - 1][j] != '1')
			return (-1);
	i = -1;
	while (vars->tab[++i])
		if (vars->tab[i][j - 1] != '1')
			return (-1);
	return (0);
}

int	check_all(t_vars *vars, char *map)
{
	int	i;

	i = 0;
	vars->nb_player = 0;
	i = check_nb_char(vars, map);
	if (i == -1)
	{
		printf("Error\nInvalid number of players\n");
		return (-1);
	}
	else if (i == -2)
	{
		printf("Error\nInvalid number of exit\n");
		return (-1);
	}
	else if (i == -3)
	{
		printf("Error\nInvalid number of collectibles\n");
		return (-1);
	}
	i += check_char(map);
	i += check_if_rectangular(map);
	if (i == 0)
		return (0);
	return (-1);
}
