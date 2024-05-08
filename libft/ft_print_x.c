/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:19:12 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/04 08:10:27 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_treat_nbr(unsigned int nbr, t_menu *menu, int *count, int op)
{
	int				i;
	unsigned int	n;

	n = nbr;
	i = 1;
	if (op == 1)
	{
		while (nbr / 16)
		{
			i++;
			nbr /= 16;
		}
		if (menu->precision && i < menu->lenght)
			return (menu->lenght);
		return (i);
	}
	else if (nbr > 15)
		ft_treat_nbr(nbr / 16, menu, count, 2);
	*count += ft_write_c("0123456789abcdef"[nbr % 16]);
	return (0);
}

static void	ft_treat_flag(unsigned int *n, t_menu *menu, int *count, int i)
{
	if (menu->hash && *n)
	{
		*count += write (1, "0x", 2);
		menu->width -= 2;
	}
	if (i == 1)
		ft_treat_nbr(*n, menu, count, 2);
	else if (i == 2)
	{
		while (menu->lenght-- - ft_treat_nbr(*n, menu, count, 1) > 0)
		{
			*count += ft_write_c('0');
			(*menu).width--;
		}
	}
}

static void	ft_treat_all(unsigned int n, t_menu *menu, int *count, char c)
{
	if (c == 1)
	{
		ft_treat_flag(&n, menu, count, 2);
		if (menu->lenght == -1 && n == 0)
			*count += ft_write_c(' ');
		else
			ft_treat_nbr(n, menu, count, 2);
	}
	else if (c == '0')
	{
		ft_treat_flag(&n, menu, count, 3);
		while (menu->width-- - ft_treat_nbr(n, menu, count, 1) > 0)
			*count += ft_write_c('0');
		ft_treat_nbr(n, menu, count, 2);
	}
	else if (c == ' ')
	{
		if (menu->hash && n)
			menu->width -= 2;
		while (menu->width-- - ft_treat_nbr(n, menu, count, 1) > 0)
			*count += ft_write_c(' ');
		ft_treat_flag(&n, menu, count, 3);
		ft_treat_nbr(n, menu, count, 2);
	}
}

static void	ft_precision(unsigned int n, t_menu *menu, int *count)
{
	if (menu->width < ft_treat_nbr(n, menu, count, 1))
	{
		ft_treat_flag(&n, menu, count, 2);
		ft_treat_nbr(n, menu, count, 2);
	}
	else if (menu->minus)
	{
		menu->zero = 0;
		ft_treat_all(n, menu, count, 1);
		while (menu->width-- - ft_treat_nbr(n, menu, count, 1) > 0)
			*count += ft_write_c(' ');
	}
	else
	{
		if (menu->hash && n)
			menu->width -= 2;
		while (menu->width-- - ft_treat_nbr(n, menu, count, 1) > 0)
			*count += ft_write_c(' ');
		ft_treat_all(n, menu, count, 1);
	}
}

void	ft_print_x(unsigned int n, t_menu *menu, int *count, char c)
{
	if (!n && menu->precision)
		ft_special_x(menu, count);
	else if (menu->precision)
		ft_precision(n, menu, count);
	else if (menu->width < ft_treat_nbr(n, menu, count, 1))
		ft_treat_flag(&n, menu, count, 1);
	else if (menu->minus)
	{
		menu->zero = 0;
		ft_treat_flag(&n, menu, count, 1);
		while (menu->width-- - ft_treat_nbr(n, menu, count, 1) > 0)
			*count += ft_write_c(' ');
	}
	else
	{
		if (menu->zero)
			c = '0';
		ft_treat_all(n, menu, count, c);
	}
}
