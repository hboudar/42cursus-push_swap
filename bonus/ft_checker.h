/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:31:47 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/04 08:43:46 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_H
# define FT_CHECKER_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}	t_stack;

int		is_args_valid(t_stack **a, char *s);
int		ft_dup(t_stack *lst, int len, int i);
char	**get_operations(int *size);
int		ft_do_ops(char **op, t_stack **a, t_stack **b);
t_stack	*ft_lstlast(t_stack *lst, int op);
int		operation(t_stack **a, t_stack **b, char op, char stack);
int		free_all(t_stack **lst, int op);

#endif
