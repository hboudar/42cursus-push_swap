NAME		=	push_swap
C_FILES		=	mandatory/push_swap.c mandatory/push_swap_utils1.c mandatory/push_swap_utils2.c \
				mandatory/operations.c mandatory/sort_stack_utils1.c mandatory/sort_stack_utils2.c
O_FILES		=	$(C_FILES:.c=.o)
H_FILE		=	mandatory/push_swap.h

NAME_BONUS	=	checker
CB_FILES	=	bonus/ft_checker.c bonus/ft_get_args.c bonus/ft_get_args2.c \
				bonus/ft_get_ops.c bonus/operations.c
OB_FILES	=	$(CB_FILES:.c=.o)
HB_FILE		=	bonus/ft_checker.h

CFLAGS		=	-Wall -Wextra -Werror
CC			=	cc

all: pre $(NAME)

bonus: pre $(NAME_BONUS)

$(NAME): $(O_FILES) libft/libft.a
	$(CC) $(CFLAGS) -o $@ $^ libft/libft.a

$(NAME_BONUS): $(OB_FILES) libft/libft.a
	$(CC) $(CFLAGS) -o $@ $^ libft/libft.a

mandatory/%.o: mandatory/%.c $(H_FILE)
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c $(HB_FILE)
	$(CC) $(CFLAGS) -c $< -o $@

pre:
	@cd libft && make

clean:
	rm -f $(O_FILES) $(OB_FILES)
	@cd libft && make clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	@cd libft && make fclean

re: fclean all
