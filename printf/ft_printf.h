/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 08:23:01 by nferre            #+#    #+#             */
/*   Updated: 2021/10/23 20:54:42 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
void	putnbr_base(int nbr, char *base, int *i);
void	putnbr(int nb, int *i);
void	u_putnbr_base(unsigned int nbr, char *base, int *i);
void	putstr(char *str, int *j);
void	p_putnbr_base(unsigned long nbr, char *base, int *i);

typedef struct s_var
{
	int				i;
	char			*s;
	unsigned int	j;
	void			*void_v;
}	t_var;

#endif
