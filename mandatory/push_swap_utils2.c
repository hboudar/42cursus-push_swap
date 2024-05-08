/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:07:48 by hboudar           #+#    #+#             */
/*   Updated: 2024/01/17 14:47:40 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_len(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_dup(t_stack *lst, int len, int i)
{
	int	*arr;

	arr = malloc (ft_len(lst) * sizeof(int));
	if (!arr)
		return (1);
	while (lst != NULL)
	{
		len = i;
		while (len--)
		{
			if (lst->nbr == arr[len])
			{
				free(arr);
				return (1);
			}
		}
		arr[i++] = lst->nbr;
		lst = lst->next;
	}
	free(arr);
	return (0);
}
