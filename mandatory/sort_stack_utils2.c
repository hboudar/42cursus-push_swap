/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:27:18 by hboudar           #+#    #+#             */
/*   Updated: 2024/01/22 09:00:03 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_stack **a, t_stack **b)
{
	if ((*a)->next->nbr > (*a)->next->next->nbr && (*a)->next->nbr > (*a)->nbr)
		op(a, b, 'o', 'a');
	else if ((*a)->nbr > (*a)->next->next->nbr)
		op(a, b, 'r', 'a');
	((*a)->nbr > (*a)->next->nbr) && (op(a, b, 's', 'a'));
	return (1);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min_node;

	min_node = stack;
	while (stack->next)
	{
		(min_node->nbr > stack->next->nbr) && (min_node = stack->next);
		stack = stack->next;
	}
	return (min_node);
}

t_stack	*ft_find_cheapest(t_stack *b, int size_a, int size)
{
	int		min;
	int		size_b;
	t_stack	*cheapest;

	(1 == 1) && (size_b = size - size_a, min = INT_MAX);
	while (b)
	{
		(b->pos <= size_b / 2) && (b->cost = b->pos);
		(b->pos > size_b / 2) && (b->cost = size_b - b->pos);
		(b->target->pos <= size_a / 2) && (b->cost += b->target->pos);
		(b->target->pos > size_a / 2) && (b->cost += size_a - b->target->pos);
		(min > b->cost) && (min = b->cost, cheapest = b);
		b = b->next;
	}
	return (cheapest);
}

int	ft_size(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
		(1 == 1) && (i = i + 1, a = a->next);
	return (i);
}
