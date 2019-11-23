NAME = ft_ls

CC = gcc
CFLAGS = -w -c

SRC = main.c functions.c display.c
OBJ = $(SRC:.c=.o)

SRCDIR = sources
OBJDIR = objects
LIBDIR = libs/libft

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))
LIBS = $(LIBDIR)/libft.a
HEADER = -I includes -I $(LIBDIR)/includes


GREEN = \x1b[32;1m
RED = \x1b[31;1m
RESET = \x1b[0m

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -I includes -I $(LIBDIR)/includes $< -o $@

$(NAME): $(OBJS)
	@make -s -C $(LIBDIR)
	@$(CC) $(OBJS) $(LIBS) -o $@
	@echo "$(GREEN)[$(NAME) executable created]$(RESET)"

clean:
	@/bin/rm -rf $(OBJDIR)
	@make -C $(LIBDIR) clean
	@echo "$(RED)[$(OBJDIR) was removed]$(RESET)"
	@echo "$(RED)[object files were removed]$(RESET)"

fclean: clean
	@/bin/rm -f $(NAME)
	@rm -f $(LIBDIR)/libft.a
	@echo "$(RED)[$(NAME) executable was removed]$(RESET)"
	@echo "$(RED)[$(LIBDIR)/libft.a was removed]$(RESET)"

re: fclean all
