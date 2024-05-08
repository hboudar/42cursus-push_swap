/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:16:28 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/04 08:10:06 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_write_c(int c)
{
	return (write(1, &c, 1));
}

void	ft_print_c(char s, t_menu *menu, int *count, char c)
{
	if (menu->width < 1)
		*count += ft_write_c(s);
	else if (menu->minus)
	{
		menu->zero = 0;
		*count += ft_write_c(s);
		while (menu->width-- - 1 > 0)
			*count += ft_write_c(c);
	}
	else
	{
		if (menu->zero)
			c = '0';
		while (menu->width-- - 1 > 0)
			*count += ft_write_c(c);
		*count += ft_write_c(s);
	}
}
