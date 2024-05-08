/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:21:29 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/04 08:15:44 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_args_valid(t_stack **a, char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		if ((*s >= '0' && *s <= '9') || ((*s == '-' || *s == '+')
				&& (*(s + 1) >= '0' && *(s + 1) <= '9')))
		{
			if (!add_node(a, ft_atoi_p(s)))
				return (0);
			s += ft_nbrlen(s);
			if (*s != ' ' && *s != '\0')
				return (0);
			count++;
		}
		else if (*s == ' ')
			s++;
		else
			return (0);
	}
	return (count);
}

static int	sort_with_algo(t_stack **a, t_stack **b, int size, int len)
{
	t_stack	*cheapest;

	ft_set_dest(*a, size);
	while (size > len && !is_sorted(*a))
	{
		if ((*a)->dest <= size / 2)
			op(a, b, 'p', 'b');
		else if ((*a)->dest > size / 2)
		{
			op(a, b, 'p', 'b');
			op(a, b, 'r', 'b');
		}
		len++;
	}
	(!is_sorted(*a)) && (sort_three(a, b));
	while (*b)
	{
		(1 == 1) && (ft_set_pos(*a), ft_set_pos(*b));
		ft_set_target(a, b, size);
		cheapest = ft_find_cheapest(*b, ft_size(*a), size);
		ft_push_cheapest(a, b, cheapest);
	}
	return (1);
}

static int	sort_stack(t_stack **a, t_stack **b, int size)
{
	t_stack	*min;

	if (size == 2 && !is_sorted(*a))
		(op(a, b, 's', 'a'));
	else if (size == 3)
		sort_three(a, b);
	if (size >= 4)
	{
		sort_with_algo(a, b, size, 3);
		ft_set_pos(*a);
		min = find_min(*a);
	}
	while (size >= 4 && *a != min)
	{
		if (min->pos <= size / 2)
			op(a, b, 'r', 'a');
		else if (min->pos > size / 2)
			op(a, b, 'o', 'a');
	}
	return (1);
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
		(size == pre_size) && (i = free_all(&a, 1));
		if (i == -1)
			exit(1);
		pre_size = size;
		i++;
	}
	(a && ft_dup(a, 0, 0)) && (i = free_all(&a, 1));
	if (i == -1)
		exit(1);
	(size >= 2 && !is_sorted(a)) && (sort_stack(&a, &b, size));
	free_all(&a, 0);
	exit(0);
}
