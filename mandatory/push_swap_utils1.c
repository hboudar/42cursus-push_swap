/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:47:13 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/04 08:15:35 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi_p(char *s)
{
	long	nbr;
	long	pre_nbr;
	int		sign;

	sign = (*s == '-') * -1 + (*s == '+' || (*s != '+' && *s != '-')) * 1;
	s += (*s == '-' || *s == '+');
	nbr = 0;
	pre_nbr = 0;
	while (*s >= '0' && *s <= '9')
	{
		nbr = nbr * 10 + *s - 48;
		if (nbr / 10 != pre_nbr)
			return ((long)INT_MAX + 1);
		pre_nbr = nbr;
		s++;
	}
	return (nbr * sign);
}

int	ft_nbrlen(char *s)
{
	int	i;

	i = (*s == '+' || *s == '-');
	s += i;
	while (*s >= '0' && *s <= '9')
	{
		i++;
		s++;
	}
	return (i);
}

t_stack	*ft_lstlast(t_stack *lst, int op)
{
	while (lst && lst->next != NULL)
	{
		if (!op && lst && lst->next && !lst->next->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	add_node(t_stack **lst, long nbr)
{
	t_stack	*root;

	if (!((long)INT_MIN <= nbr && nbr <= (long)INT_MAX))
		return (0);
	if (!*lst)
	{
		*lst = malloc (sizeof(t_stack));
		if (!*lst)
			return (0);
		(*lst)->nbr = nbr;
		(*lst)->next = NULL;
	}
	else
	{
		root = ft_lstlast(*lst, 1);
		root->next = malloc (sizeof(t_stack));
		if (!root->next)
			return (0);
		root->next->nbr = nbr;
		root->next->next = NULL;
	}
	return (1);
}

int	free_all(t_stack **lst, int op)
{
	t_stack	*tmp;

	if (op)
		write (2, "Error\n", 6);
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	return (-1);
}
