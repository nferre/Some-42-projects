/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:54:35 by nferre            #+#    #+#             */
/*   Updated: 2021/11/01 10:21:47 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if ((x < vars->l * 60 && y < vars->col * 60))
	{
		dst = vars->addr + (y * vars->line + x * (vars->bits / 8));
		*(unsigned int *)dst = color;
	}
}

int	find_color(char map_char)
{
	if (map_char == '0')
		return (0x00000000);
	else if (map_char == '1')
		return (0x0000FADA);
	else if (map_char == 'P')
		return (0x00FF0000);
	else if (map_char == 'E')
		return (0x0000CAFE);
	else
		return (0x00FFFFFF);
}

void	draw_square(t_vars *vars, int pos1, int pos2, char map_char)
{
	int	i;
	int	j;
	int	k;
	int	color;

	i = 0;
	j = 0;
	k = 0;
	color = find_color(map_char);
	while (i++ != 60)
	{
		while (j++ != 60)
			my_mlx_pixel_put(vars, i + pos1, j + pos2, color);
		j = 0;
	}
}

void	draw_all(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	mlx_clear_window(vars->mlx, vars->win);
	vars->img = mlx_new_image(vars->mlx, vars->l * 60, vars->col * 60);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits, &vars->line,
			&vars->endian);
	while (vars->tab[++i])
	{
		j = -1;
		while (vars->tab[i][++j])
			draw_square(vars, j * 60, i * 60, vars->tab[i][j]);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_destroy_image(vars->mlx, vars->img);
}
