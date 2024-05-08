/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:52:22 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/04 08:10:12 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_treat_nbr(long int nbr, t_menu *menu, int *count, int operator)
{
	int	i;

	i = 1;
	if (operator == 1)
	{
		if ((menu->plus || menu->space) && nbr >= 0)
			i++;
		if (nbr < 0)
		{
			i++;
			nbr *= -1;
		}
		while (nbr / 10)
		{
			i++;
			nbr /= 10;
		}
		return (i);
	}
	else if (nbr > 9)
		ft_treat_nbr(nbr / 10, menu, count, 2);
	*count += ft_write_c("0123456789"[nbr % 10]);
	return (0);
}

static void	ft_treat_flag(long int *n, t_menu *menu, int *count)
{
	if (!menu->zero && (*n < 0 || menu->plus || menu->space))
	{
		if (*n < 0)
		{
			*n *= -1;
			*count += ft_write_c('-');
			if (!menu->space && !menu->plus)
				(*menu).width--;
		}
		else if (menu->plus)
			*count += ft_write_c('+');
		else if (menu->space)
			*count += ft_write_c(' ');
	}
	ft_treat_nbr(*n, menu, count, 2);
}

static void	ft_flag(long int *n, t_menu *menu, int *count, char *c)
{
	if (menu->zero)
	{
		*c = '0';
		if (*n < 0)
		{
			*count += ft_write_c('-');
			*n *= -1;
			if (!menu->space && !menu->plus)
				menu->width--;
		}
		else if (menu->plus)
			*count += ft_write_c('+');
		else if (menu->space)
			*count += ft_write_c(' ');
	}
}

void	ft_print_di(long int n, t_menu *menu, int *count, char c)
{
	if (!n && menu->precision)
		ft_special_di(menu, count);
	else if (menu->precision)
		ft_precision_di(n, menu, count);
	else if (menu->width <= ft_treat_nbr(n, menu, count, 1))
	{
		menu->zero = 0;
		ft_treat_flag(&n, menu, count);
	}
	else if (menu->minus)
	{
		menu->zero = 0;
		ft_treat_flag(&n, menu, count);
		while (menu->width-- - ft_treat_nbr(n, menu, count, 1) > 0)
			*count += ft_write_c(' ');
	}
	else
	{
		ft_flag(&n, menu, count, &c);
		while (menu->width-- - ft_treat_nbr(n, menu, count, 1) > 0)
			*count += ft_write_c(c);
		ft_treat_flag(&n, menu, count);
	}
}
