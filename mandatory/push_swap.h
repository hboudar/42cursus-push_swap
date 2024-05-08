/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:21:33 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/04 09:11:47 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
	int				dest;
	int				pos;
	int				cost;
	struct s_stack	*target;
}	t_stack;

int		add_node(t_stack **lst, long nbr);
long	ft_atoi_p(char *s);
t_stack	*ft_lstlast(t_stack *lst, int op);
int		ft_nbrlen(char *s);
int		free_all(t_stack **lst, int op);
int		ft_dup(t_stack *lst, int len, int i);

int		sort_three(t_stack **a, t_stack **b);
int		op(t_stack **a, t_stack **b, char op, char stack);

int		ft_set_dest(t_stack *a, int size);
int		ft_set_target(t_stack **a, t_stack **b, int size);
t_stack	*find_min(t_stack *stack);
int		ft_set_pos(t_stack *stack);
t_stack	*ft_find_cheapest(t_stack *b, int size_a, int size);
int		ft_size(t_stack *a);
int		is_sorted(t_stack *a);
void	ft_push_cheapest(t_stack **a, t_stack **b, t_stack *cheapest);

#endif
