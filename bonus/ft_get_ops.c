/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:17:51 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/15 16:31:08 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

static int	is_op_valid(char *op)
{
	int	i;

	i = 0;
	if (!op)
		return (1);
	while (op[i])
		i++;
	if (i == 3)
		return (op[2] == '\n'
			&& ((op[0] == 's' && (op[1] == 'a' || op[1] == 'b'
						|| op[1] == 's'))
				|| (op[0] == 'r' && (op[1] == 'a' || op[1] == 'b'
						|| op[1] == 'r'))
				|| (op[0] == 'p' && (op[1] == 'a' || op[1] == 'b'))));
	else if (i == 4)
		return (op[3] == '\n'
			&& ((op[0] == 'r' && op[1] == 'r'
					&& (op[2] == 'a' || op[2] == 'b' || op[2] == 'r'))));
	return (0);
}

char	*get_all_ops(char *op, char *all_ops)
{
	char	*new_ops;
	int		i;
	int		j;

	(1 == 1) && (i = 0, j = 0);
	while (all_ops && all_ops[i])
		i++;
	while (op && op[j])
		j++;
	new_ops = malloc (sizeof(char) * i + j + 1);
	if (!new_ops)
		return (NULL);
	(1 == 1) && (i = 0, j = -1);
	while (all_ops && all_ops[i])
	{
		new_ops[i] = all_ops[i];
		i++;
	}
	while (op[++j])
		new_ops[i + j] = op[j];
	new_ops[i + j] = '\0';
	free(all_ops);
	free(op);
	return (new_ops);
}

char	**get_operations(int *size)
{
	char	*all_ops;
	char	**buff;
	char	*op;
	int		i;

	(1 == 1) && (all_ops = NULL, op = get_next_line(0), i = 1, *size = 0);
	(!is_op_valid(op)) && (i = -1, *size = -2);
	while (op && i == 1)
	{
		*size += 1;
		(i == 1) && (all_ops = get_all_ops(op, all_ops), op = get_next_line(0));
		(!is_op_valid(op)) && (i = -1, *size = -2);
		(!all_ops) && (i = 0);
	}
	if (i != 1)
	{
		free(all_ops);
		free(op);
		(i == -1) && (write(2, "Error\n", 6), exit(1), i = 0);
		return (NULL);
	}
	buff = NULL;
	(*size != 0) && (buff = ft_split(all_ops, '\n'));
	(*size != 0 && !buff) && (*size = -1);
	return (free(op), free(all_ops), buff);
}

int	ft_do_ops(char **op, t_stack **a, t_stack **b)
{
	int	i;

	if (!op)
		return (0);
	i = 0;
	while (op[i])
	{
		(!ft_strncmp(op[i], "sa\0", 3)) && (operation(a, b, 's', 'a'));
		(!ft_strncmp(op[i], "sb\0", 3)) && (operation(a, b, 's', 'b'));
		(!ft_strncmp(op[i], "ss\0", 3)) && (operation(a, b, 'S', 'r'));
		(!ft_strncmp(op[i], "pa\0", 3)) && (operation(a, b, 'p', 'a'));
		(!ft_strncmp(op[i], "pb\0", 3)) && (operation(a, b, 'p', 'b'));
		(!ft_strncmp(op[i], "rra\0", 4)) && (operation(a, b, 'o', 'a'));
		(!ft_strncmp(op[i], "rrb\0", 4)) && (operation(a, b, 'o', 'b'));
		(!ft_strncmp(op[i], "rrr\0", 4)) && (operation(a, b, 'O', 'r'));
		(!ft_strncmp(op[i], "ra\0", 3)) && (operation(a, b, 'r', 'a'));
		(!ft_strncmp(op[i], "rb\0", 3)) && (operation(a, b, 'r', 'b'));
		(!ft_strncmp(op[i], "rr\0", 3)) && (operation(a, b, 'R', 'r'));
		free(op[i]);
		i++;
	}
	free(op);
	return (1);
}
