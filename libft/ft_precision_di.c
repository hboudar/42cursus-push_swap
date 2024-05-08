/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_di.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:46:23 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/04 08:09:58 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_nbr(long int nbr, int *count, int op)
{
	int	i;

	if (op == 1)
	{
		i = 1;
		if (nbr < 0)
			nbr *= -1;
		while (nbr / 10)
		{
			i++;
			nbr /= 10;
		}
		return (i);
	}
	else if (nbr > 9)
		ft_count_nbr(nbr / 10, count, 2);
	*count += ft_write_c("0123456789"[nbr % 10]);
	return (0);
}

static int	ft_treat_nbr(long int nbr, t_menu *menu)
{
	int	i;

	i = 1;
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
	if (menu->lenght > i)
		return (menu->lenght);
	return (i);
}

static void	ft_treat_flag(long int *n, t_menu *menu, int *count)
{
	if ((*n < 0 || menu->plus || menu->space))
	{
		if (*n < 0)
		{
			*n *= -1;
			*count += ft_write_c('-');
		}
		else if (menu->plus)
			*count += ft_write_c('+');
		else if (menu->space)
			*count += ft_write_c(' ');
		menu->width--;
	}
	while (menu->lenght-- - ft_count_nbr(*n, count, 1) > 0)
	{
		*count += ft_write_c('0');
		menu->width--;
	}
	ft_count_nbr(*n, count, 2);
	menu->width -= ft_count_nbr(*n, count, 1);
}

void	ft_precision_di(long int n, t_menu *menu, int *count)
{
	if (menu->width < ft_treat_nbr(n, menu))
		ft_treat_flag(&n, menu, count);
	else if (menu->minus)
	{
		menu->zero = 0;
		ft_treat_flag(&n, menu, count);
		while (menu->width-- > 0)
			*count += ft_write_c(' ');
	}
	else
	{
		if ((n < 0 || menu->plus || menu->space)
			&& menu->lenght > ft_count_nbr(n, count, 1))
			menu->width--;
		while (menu->width-- - ft_treat_nbr(n, menu) > 0)
			*count += ft_write_c(' ');
		ft_treat_flag(&n, menu, count);
	}
}
