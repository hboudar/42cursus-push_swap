SRC		=	get_next_line.c get_next_line_utils.c ft_printf.c ft_is_flag.c ft_print_c.c ft_print_s.c \
			ft_print_p.c ft_print_x.c ft_print_u.c ft_print_di.c ft_print_sp.c ft_print_xx.c ft_precision_di.c \
			ft_split.c ft_substr.c ft_memcpy.c ft_strncmp.c ft_strdup.c ft_strlen.c

OBJS	=	$(SRC:.c=.o)
LIBC	=	ar -rcs
CFLAGS	=	-Wall -Wextra -Werror
CC		=	cc
RM		=	rm -f
NAME	=	libft.a

all: ${NAME}

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all bonus re
