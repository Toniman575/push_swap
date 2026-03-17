NAME =		push_swap
LIBFT_DIR =	./libft
LIBFT =		$(LIBFT_DIR)/libft.a

CC =		cc
CFLAGS =	-Wall -Wextra -Werror -MMD -MP -I$(LIBFT_DIR)
LDFLAGS =	-L$(LIBFT_DIR) -lft
SRCS =		push_swap.c
OBJS =		$(SRCS:.c=.o)
DEPS =		$(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR)

FORCE:

clean:
	rm -f $(OBJS) $(DEPS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

debug: fclean
	$(MAKE) -C $(LIBFT_DIR) debug
	$(MAKE) all CFLAGS="$(CFLAGS) -g"

.PHONY: all clean fclean re debug FORCE

-include $(DEPS)