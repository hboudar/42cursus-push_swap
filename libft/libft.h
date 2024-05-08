/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:58:03 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/04 09:02:36 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}			t_list;

typedef struct s_menu
{
	va_list	list;
	int		i;
	int		count;
	int		hash;
	int		space;
	int		plus;
	int		minus;
	int		zero;
	int		width;
	int		precision;
	int		precision_1;
	int		lenght;
}			t_menu;

char	*get_next_line(int fd);
int		ft_lstchar(t_list *list, int i);
t_list	*ft_find_last_node(t_list *list);
void	ft_copy_str(t_list *list, char *str, int i, int k);
int		ft_len_to_newline(t_list *list, int len, int i);
void	ft_free_all(t_list **list, t_list **clean_node, char **buf);

int		ft_printf(const char *str, ...);
int		ft_flags(char *s, t_menu *flags);
void	ft_print_c(char s, t_menu *menu, int *count, char c);
void	ft_print_di(long int n, t_menu *menu, int *count, char c);
void	ft_print_s(char *s, t_menu *menu, int *count, char c);
void	ft_print_u(unsigned int nbr, t_menu *menu, int *count, char c);
void	ft_print_x(unsigned int nbr, t_menu *menu, int *count, char c);
void	ft_print_xx(unsigned int n, t_menu *menu, int *count, char c);
void	ft_print_p(unsigned long long nbr, t_menu *menu, int *count, char c);
int		ft_write_c(int c);
void	ft_write_s(char *s, int *count, t_menu *menu);
void	ft_special_di(t_menu *menu, int *count);
void	ft_precision_di(long int n, t_menu *menu, int *count);
void	ft_special_x(t_menu *menu, int *count);

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

#endif
