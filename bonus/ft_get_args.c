/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:25:47 by hboudar           #+#    #+#             */
/*   Updated: 2024/02/04 14:34:50 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

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

static long	ft_atoii(char *s)
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

static int	ft_nbrlen(char *s)
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

static int	add_node(t_stack **lst, long nbr)
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

int	is_args_valid(t_stack **a, char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		if ((*s >= '0' && *s <= '9') || ((*s == '-' || *s == '+')
				&& (*(s + 1) >= '0' && *(s + 1) <= '9')))
		{
			if (!add_node(a, ft_atoii(s)))
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
