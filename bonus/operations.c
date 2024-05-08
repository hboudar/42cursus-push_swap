/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:44:57 by hboudar           #+#    #+#             */
/*   Updated: 2024/02/02 10:51:29 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

static void	ft_swap(t_stack **a, t_stack **b, char op, char stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if ((op == 'S' || (op == 's' && stack == 'a')) && *a && (*a)->next)
	{
		tmp = (*a)->next;
		(*a)->next = (*a)->next->next;
		tmp->next = *a;
		*a = tmp;
		i++;
	}
	if ((op == 'S' || (op == 's' && stack == 'b')) && *b && (*b)->next)
	{
		tmp = (*b)->next;
		(*b)->next = (*b)->next->next;
		tmp->next = *b;
		*b = tmp;
		i += 2;
	}
}

static void	ft_push(t_stack **a, t_stack **b, char stack)
{
	t_stack	*tmp;

	if (stack == 'a' && *b)
	{
		tmp = (*b)->next;
		(*b)->next = *a;
		*a = *b;
		*b = tmp;
	}
	else if (stack == 'b' && *a)
	{
		tmp = (*a)->next;
		(*a)->next = *b;
		*b = *a;
		*a = tmp;
	}
}

static void	ft_rotate(t_stack **a, t_stack **b, char op, char stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if ((op == 'R' || (op == 'r' && stack == 'a')) && *a && (*a)->next)
	{
		ft_lstlast(*a, 1)->next = *a;
		tmp = (*a)->next;
		(*a)->next = NULL;
		*a = tmp;
		i++;
	}
	if ((op == 'R' || (op == 'r' && stack == 'b')) && *b && (*b)->next)
	{
		ft_lstlast(*b, 1)->next = *b;
		tmp = (*b)->next;
		(*b)->next = NULL;
		*b = tmp;
		i += 2;
	}
}

static void	ft_rrotate(t_stack **a, t_stack **b, char op, char stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if ((op == 'O' || (op == 'o' && stack == 'a')) && *a && (*a)->next)
	{
		tmp = ft_lstlast(*a, 1);
		ft_lstlast(*a, 0)->next = NULL;
		tmp->next = *a;
		*a = tmp;
		i++;
	}
	if ((op == 'O' || (op == 'o' && stack == 'b')) && *b && (*b)->next)
	{
		tmp = ft_lstlast(*b, 1);
		ft_lstlast(*b, 0)->next = NULL;
		tmp->next = *b;
		*b = tmp;
		i += 2;
	}
}

int	operation(t_stack **a, t_stack **b, char op, char stack)
{
	if ((op == 's' || op == 'S'))
		ft_swap(a, b, op, stack);
	else if (op == 'p')
		ft_push(a, b, stack);
	else if (op == 'r' || op == 'R')
		ft_rotate(a, b, op, stack);
	else
		ft_rrotate(a, b, op, stack);
	return (1);
}
