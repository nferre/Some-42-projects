/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 08:16:15 by nferre            #+#    #+#             */
/*   Updated: 2021/10/23 20:53:44 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h" 

void	determine(t_var *var, char c, va_list arg)
{
	if (c == 'c' || c == 'd' || c == 'x' || c == 'i' || c == 'X')
		var->i = va_arg(arg, int);
	else if (c == 's')
		var->s = va_arg(arg, char *);
	else if (c == 'p')
		var->void_v = va_arg(arg, void *);
	else if (c == 'u')
		var->j = va_arg(arg, unsigned int);
	else
		return ;
}

void	tests(char *container, t_var var, int *i)
{
	if (*container == 'c')
	{
		*i = *i + 1;
		ft_putchar(var.i);
	}
	else if (*container == 'd')
		putnbr(var.i, i);
	else if (*container == 's')
	{
		if (var.s == NULL)
			putstr("(null)", i);
		else
			putstr(var.s, i);
	}
	else if (*container == 'X')
		putnbr_base(var.i, "0123456789ABCDEF", i);
	else if (*container == 'x')
		putnbr_base(var.i, "0123456789abcdef", i);
	else if (*container == 'u')
		u_putnbr_base(var.j, "0123456789", i);
	else if (*container == '%')
	{
		*i = *i + 1;
		ft_putchar('%');
	}
}

void	other_tests(char *container, t_var var, int *i)
{
	if (*container == 'p')
	{
		*i = *i + 2;
		ft_putstr("0x");
		p_putnbr_base((unsigned long )var.void_v, "0123456789abcdef", i);
	}
	else if (*container == 'i')
		putnbr(var.i, i);
}

void	all_fonctions(t_var var, char *container, int *i)
{
	tests(container, var, i);
	other_tests(container, var, i);
	return ;
}

int	ft_printf(const char *format, ...)
{
	va_list			arg;
	char			*container;
	t_var			var;
	int				i;

	i = 0;
	va_start(arg, format);
	container = (char *)format;
	while (*container)
	{
		while (*container != '%' && *container)
		{
			i = i + 1;
			ft_putchar(*container++);
		}
		if (*container)
			container++;
		else
			break ;
		determine(&var, *container, arg);
		all_fonctions(var, container, &i);
		container++;
	}
	va_end(arg);
	return (i);
}
