/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:36:10 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/04 08:10:22 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_sign(t_menu *menu, int *count)
{
	if (menu->plus)
		*count += ft_write_c('+');
	else if (menu->space)
		*count += ft_write_c(' ');
}

static void	ft_print_all(t_menu *menu, int *count)
{
	if (menu->minus)
	{
		if (menu->plus || menu->space)
			menu->width--;
		ft_print_sign(menu, count);
		while (menu->lenght-- > 0)
		{
			*count += ft_write_c('0');
			menu->width--;
		}
		while (menu->width-- > 0)
			*count += ft_write_c(' ');
	}
	else
	{
		if (menu->plus || menu->space)
			menu->width--;
		while (menu->width-- - menu->lenght > 0)
			*count += ft_write_c(' ');
		ft_print_sign(menu, count);
		while (menu->lenght--)
			*count += ft_write_c('0');
	}
}

void	ft_special_di(t_menu *menu, int *count)
{
	if (!menu->lenght && !menu->width)
	{
		ft_print_sign(menu, count);
		return ;
	}
	else if (menu->width && !menu->lenght)
	{
		if (menu->minus)
			ft_print_sign(menu, count);
		if (menu->plus || menu->space)
			menu->width--;
		while (menu->width--)
			*count += ft_write_c(' ');
		if (!menu->minus)
			ft_print_sign(menu, count);
	}
	else if (menu->lenght && !menu->width)
	{
		ft_print_sign(menu, count);
		while (menu->lenght--)
			*count += ft_write_c('0');
	}
	else
		ft_print_all(menu, count);
}

static void	ft_special_x_p(t_menu *menu, int *count)
{
	if (menu->minus)
	{
		while (menu->lenght-- > 0)
		{
			*count += ft_write_c('0');
			menu->width--;
		}
		while (menu->width-- > 0)
			*count += ft_write_c(' ');
	}
	else
		while (menu->width-- - menu->lenght > 0)
			*count += ft_write_c(' ');
	while (menu->lenght-- > 0)
		*count += ft_write_c('0');
}

void	ft_special_x(t_menu *menu, int *count)
{
	if (!menu->width && !menu->lenght && menu->precision)
		return ;
	else if (!menu->lenght)
	{
		while (menu->width-- > 0)
			*count += ft_write_c(' ');
	}
	else
		ft_special_x_p(menu, count);
}
