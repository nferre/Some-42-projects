/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:32:35 by nferre            #+#    #+#             */
/*   Updated: 2021/11/01 10:46:39 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit (0);
	move(keycode, vars);
	draw_all(vars);
	printf("nb moves : %d\n", vars->nb_moves);
	return (0);
}

void	free_all(t_vars *vars)
{
	int	i;

	i = -1;
	while (vars->tab[++i])
		free(vars->tab[i]);
	free(vars->tab);
}

int	close_w(void)
{
	exit (0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		i;

	i = 0;
	if (argc != 2)
	{
		printf("Error\nInvalid argument\n");
		return (-1);
	}
	if (check_ber(argv[1]) == -1)
		return (-1);
	if (check_all(&vars, argv[1]) != 0)
		return (-1);
	get_map(&vars, argv[1]);
	if (check_walls(&vars) != 0)
	{
		free_all(&vars);
		return (printf("Error\nWall not correct\n"));
	}
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.l * 60, vars.col * 60, "so_long");
	draw_all(&vars);
	mlx_hook(vars.win, 2, 0, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, close_w, &vars);
	mlx_loop(vars.mlx);
}
