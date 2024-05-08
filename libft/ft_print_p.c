/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:20:45 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/04 08:10:16 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_treat_nbr(unsigned long long nbr, int *count, int op)
{
	int	len;

	len = 2;
	if (op == 1)
	{
		if (nbr < 0)
		{
			len++;
			nbr *= -1;
		}
		else if (nbr == 0)
			return (3);
		while (nbr != 0)
		{
			len++;
			nbr /= 16;
		}
	}
	else
	{
		if (nbr > 15)
			ft_treat_nbr(nbr / 16, count, 2);
		*count += ft_write_c("0123456789abcdef"[nbr % 16]);
	}
	return (len);
}

static void	ft_treat_flag(unsigned long long nbr, t_menu *menu, int *count)
{
	(*menu).lenght = 2;
	ft_write_s("0x", count, menu);
	if (menu->precision && !nbr)
		return ;
	ft_treat_nbr(nbr, count, 2);
}

void	ft_print_p(unsigned long long nbr, t_menu *menu, int *count, char c)
{
	if (menu->width < ft_treat_nbr(nbr, count, 1))
		ft_treat_flag(nbr, menu, count);
	else if (menu->minus)
	{
		menu->zero = 0;
		ft_treat_flag(nbr, menu, count);
		if (menu->precision && !nbr)
			menu->width++;
		while (menu->width-- - ft_treat_nbr(nbr, count, 1) > 0)
			*count += ft_write_c(c);
	}
	else
	{
		if (menu->precision && !nbr)
			menu->width++;
		while (menu->width-- - ft_treat_nbr(nbr, count, 1) > 0)
			*count += ft_write_c(c);
		ft_treat_flag(nbr, menu, count);
	}
}
