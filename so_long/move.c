/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:15:15 by nferre            #+#    #+#             */
/*   Updated: 2021/11/01 09:18:07 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	move_player(t_vars *vars, int v1, int v2)
{
	char	temp;

	if (vars->tab[vars->x + v1][vars->y + v2] == '1')
		return ;
	if (vars->tab[vars->x + v1][vars->y + v2] == 'E')
	{
		if (vars->total_collec == vars->collec)
		{	
			printf("you win !\n");
			exit (0);
		}
		return ;
	}
	if (vars->tab[vars->x + v1][vars->y + v2] == 'C')
	{
		vars->tab[vars->x + v1][vars->y + v2] = '0';
		vars->collec = vars-> collec + 1;
	}
	temp = vars->tab[vars->x][vars->y];
	vars->tab[vars->x][vars->y] = vars->tab[vars->x + v1][vars->y + v2];
	vars->tab[vars->x + v1][vars->y + v2] = temp;
	vars->x = vars->x + v1;
	vars->y = vars->y + v2;
	vars->nb_moves = vars->nb_moves + 1;
}

int	move(int keycode, t_vars *vars)
{
	if (keycode == 13)
		move_player(vars, -1, 0);
	else if (keycode == 0)
		move_player(vars, 0, -1);
	else if (keycode == 1)
		move_player(vars, 1, 0);
	else if (keycode == 2)
		move_player(vars, 0, 1);
	return (0);
}
