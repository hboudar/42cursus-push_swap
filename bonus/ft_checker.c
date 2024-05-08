/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:33:02 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/15 16:32:44 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int	free_all(t_stack **lst, int op)
{
	t_stack	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	if (op == 2)
		exit(1);
	return (-1);
}

static int	is_sorted(t_stack *a, t_stack *b)
{
	if (b)
		return (write (1, "KO\n", 3));
	while (a->next)
	{
		if (a->nbr > a->next->nbr)
			return (write (1, "KO\n", 3));
		a = a->next;
	}
	return (write (1, "OK\n", 3));
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		pre_size;
	int		size;
	int		i;

	(1 == 1) && (i = 1, a = NULL, b = NULL, size = 0, pre_size = 0);
	while (i < argc)
	{
		size += is_args_valid(&a, argv[i]);
		(size == pre_size) && (write (2, "Error\n", 6), i = free_all(&a, 1));
		if (i == -1)
			exit(1);
		pre_size = size;
		i++;
	}
	(a && ft_dup(a, 0, 0)) && (write (2, "Error\n", 6), i = free_all(&a, 1));
	if (i == -1)
		exit(EXIT_FAILURE);
	(argc > 1) && (ft_do_ops(get_operations(&i), &a, &b));
	(argc > 1 && i != -2) && (is_sorted(a, b));
	exit(0);
}
