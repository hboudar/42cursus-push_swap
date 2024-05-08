/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:12:42 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/04 08:10:34 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_format(char format, t_menu *menu, int *count)
{
	if (format == '%')
		ft_print_c('%', menu, count, ' ');
	else if (format == 'c')
		ft_print_c(va_arg(menu->list, int), menu, count, ' ');
	else if (format == 's')
		ft_print_s(va_arg(menu->list, char *), menu, count, ' ');
	else if (format == 'd' || format == 'i')
		ft_print_di((int)va_arg(menu->list, int), menu, count, ' ');
	else if (format == 'x')
		ft_print_x(va_arg(menu->list, unsigned int), menu, count, ' ');
	else if (format == 'X')
		ft_print_xx(va_arg(menu->list, unsigned int), menu, count, ' ');
	else if (format == 'p')
		ft_print_p(va_arg(menu->list, unsigned long long), menu, count, ' ');
	else if (format == 'u')
		ft_print_u(va_arg(menu->list, unsigned int), menu, count, ' ');
}

int	ft_printf(const char *str, ...)
{
	t_menu	menu;

	if (write(1, "", 0) == -1)
		return (-1);
	va_start(menu.list, str);
	menu.count = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '\0')
		{
			str++;
			str += ft_flags((char *)str, &menu);
			ft_format(*str, &menu, &menu.count);
		}
		else if (*str != '%')
			menu.count += write(1, str, 1);
		str++;
	}
	va_end(menu.list);
	return (menu.count);
}
