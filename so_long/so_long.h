/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:30:09 by nferre            #+#    #+#             */
/*   Updated: 2021/11/01 09:26:03 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	char	**tab;
	int		collec;
	int		total_collec;
	int		nb_player;
	int		nb_exit;
	int		nb_moves;
	char	*addr;
	void	*img;
	int		line;
	int		bits;
	int		endian;
	int		col;
	int		l;
	int		tile_size_col;
	int		tile_size_l;
}	t_vars;

int		check_ber(char *map);
int		check_walls(t_vars *vars);
int		check_all(t_vars *vars, char *map);
void	draw_all(t_vars *vars);
void	get_map(t_vars *vars, char *map);
int		move(int keycode, t_vars *vars);
int		get_player_pos(char **tab);
void	print_tab(t_vars *vars);
int		rectangular_loop(int i, int ret, int fd, char *buf);
#endif
