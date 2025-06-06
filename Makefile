CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
NAME		= pipex
LIBFT		= ./libft/libft.a
SRCS		= main.c \
				args_checking.c \
				init.c \
				clean.c \
				parsing.c \

# GNL_SRCS	= $(addprefix ./gnl/, \
# 				get_next_line_utils.c \
# 				get_next_line.c)

OBJS		= $(SRCS:.c=.o)
# GNL_OBJS	= $(GNL_SRCS:.c=.o)

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(LIBFT) $(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
			make bonus -C ./libft

clean:
			make clean -C ./libft
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C ./libft
			$(RM) $(NAME)

re:			fclean all