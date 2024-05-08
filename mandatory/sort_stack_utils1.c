/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:54:35 by hboudar           #+#    #+#             */
/*   Updated: 2024/01/22 11:15:32 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_set_dest(t_stack *a, int size)
{
	t_stack	*tmp;
	t_stack	*current;
	int		i;

	current = a;
	while (size--)
	{
		i = 0;
		tmp = a;
		while (tmp)
		{
			if (current->nbr > tmp->nbr)
				i++;
			tmp = tmp->next;
		}
		current->dest = i;
		current = current->next;
	}
	return (1);
}

int	ft_set_target(t_stack **a, t_stack **b, int size)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		target_index;

	tmp_b = *b;
	while (tmp_b)
	{
		tmp_a = *a;
		target_index = size;
		while (tmp_a)
		{
			if (tmp_b->dest < tmp_a->dest && target_index > tmp_a->dest)
			{
				tmp_b->target = tmp_a;
				target_index = tmp_a->dest;
			}
			tmp_a = tmp_a->next;
		}
		if (target_index == size)
			tmp_b->target = find_min(*a);
		tmp_b = tmp_b->next;
		tmp_a = *a;
	}
	return (1);
}

int	ft_set_pos(t_stack *stack)
{
	int		p;

	p = 0;
	while (stack)
	{
		stack->pos = p;
		p++;
		stack = stack->next;
	}
	return (1);
}

void	ft_push_cheapest(t_stack **a, t_stack **b, t_stack *node)
{
	int	mid_a;
	int	mid_b;
	int	i;

	(1 == 1) && (mid_a = ft_size(*a) / 2, mid_b = ft_size(*b) / 2);
	while (*b != node)
	{
		i = 0;
		if (*a != node->target && node->pos > mid_b
			&& node->target->pos > mid_a)
			(op(a, b, 'O', 'a'), i = 1);
		else if (*a != node->target && node->pos <= mid_b
			&& node->target->pos <= mid_a)
			(op(a, b, 'R', 'a'), i = 1);
		if (!i && node->pos > mid_b)
			(op(a, b, 'o', 'b'));
		else if (!i && node->pos <= mid_b)
			(op(a, b, 'r', 'b'));
	}
	while (*a != node->target)
	{
		(node->target->pos <= mid_a) && (op(a, b, 'r', 'a'));
		(node->target->pos > mid_a) && (op(a, b, 'o', 'a'));
	}
	op(a, b, 'p', 'a');
}

int	is_sorted(t_stack *a)
{
	while (a->next)
	{
		if (a->nbr > a->next->nbr)
			return (0);
		a = a->next;
	}
	return (1);
}
