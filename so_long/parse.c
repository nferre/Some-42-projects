/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 09:18:17 by nferre            #+#    #+#             */
/*   Updated: 2021/11/01 09:23:04 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	get_size_map(int *length, int *heigth, t_vars *vars, char *map)
{
	char	buf[1];
	int		fd;
	int		ret;

	ret = 1;
	fd = open(map, O_RDONLY);
	vars->total_collec = 0;
	while (ret == 1)
	{
		ret = read(fd, buf, 1);
		if (*heigth == 0 && buf[0] != '\n')
			*length = *length + 1;
		if (buf[0] == '\n' || ret == 0)
			*heigth = *heigth + 1;
		if (buf[0] == 'C')
			vars->total_collec = vars->total_collec + 1;
	}
	vars->col = *heigth;
	vars->l = *length;
	close(fd);
}

void	fill_if(t_vars *vars, char *buf, int i, int j)
{
	if (buf[0] == 'P')
	{
		vars->x = i;
		vars->y = j;
	}
}

void	fill_tab(t_vars *vars, char *map)
{
	char	buf[1];
	int		fd;
	int		return_value;
	int		j;
	int		i;

	i = 0;
	j = 0;
	return_value = 1;
	fd = open(map, O_RDONLY);
	while (return_value == 1)
	{
		return_value = read(fd, buf, 1);
		fill_if(vars, buf, i, j);
		if (buf[0] == '\n' || return_value == 0)
		{
			vars->tab[i++][j] = '\0';
			j = 0;
		}
		else
			vars->tab[i][j++] = buf[0];
	}
	vars->tab[i] = NULL;
	close(fd);
}

void	get_map(t_vars *vars, char *map)
{
	int		length;
	int		i;
	int		heigth;

	i = 0;
	heigth = 0;
	length = 0;
	get_size_map(&length, &heigth, vars, map);
	vars->tab = malloc((heigth + 1) * sizeof(char *));
	while (i != heigth)
		vars->tab[i++] = malloc((length + 1) * sizeof(char));
	fill_tab(vars, map);
}
