
# Special variables
.DEFAULT_GOAL: all
.DELETE_ON_ERROR: $(TEST) $(DEBUG)
.PHONY: all bonus clean fclean re debug leak time test

# Hide calls
export VERBOSE	=	FALSE
ifeq ($(VERBOSE),TRUE)
	HIDE =
else
	HIDE = @
endif

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
DFLAG	=	-D DEBUG -Wall -Werror -Wextra
TFLAG	=	-pg -Wall -Werror -Wextra
RM		=	rm -rf

# Dir and file names
NAME	=	so_long
DEBUG	=	so_long_debug
TEST	=	so_long_test
LIBFT	=	libft.a
LDIR	=	libft/
MLX		=	libmlx.a
MLXDIR	=	mlx/
SRCDIR	=	src/
OBJDIR	=	bin/
SRCS	=	$(wildcard $(SRCDIR)*.c) # Change to file names before sub
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

# Targets
all: $(LDIR)/$(LIBFT) $(MLXDIR)/$(MLX) $(NAME)

$(NAME): $(OBJS) $(LDIR)/$(LIBFT)
	$(HIDE)$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDIR)$(LIBFT) -lm

$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c
	$(HIDE)mkdir -p $(OBJDIR)
	$(HIDE)$(CC) $(CFLAGS) -c $< -o $@

# Generates libft.a
$(LDIR)/$(LIBFT):
	$(HIDE)$(MAKE) -C $(LDIR)

# Generates libmlx.a
$(MLXDIR)/$(MLX):
	$(HIDE)$(MAKE) -C $(MLXDIR) $(MAKE) -s

# Compiles bonus program: checker
bonus: all

# Removes objects
clean:
	$(HIDE)$(RM) $(OBJS)
	$(HIDE)$(MAKE) -C $(LDIR) $(MAKE) -s clean
	$(HIDE)$(MAKE) -C $(MLXDIR) $(MAKE) -s clean

# Removes objects and executables
fclean: clean
	$(HIDE)$(RM) $(NAME)
	$(HIDE)$(MAKE) -C $(LDIR) $(MAKE) -s $@
	$(HIDE)$(MAKE) -C $(MLXDIR) $(MAKE) -s $@
	$(HIDE)$(RM) $(TEST)
	$(HIDE)$(RM) $(DEBUG)
	$(HIDE)$(RM) *.dSYM
	$(HIDE)$(RM) *.out

# Removes objects and executables and remakes
re: fclean all


# Starts a debugging run
$(DEBUG): fclean
	$(HIDE)$(CC) $(DFLAG) -o $@ $(SRCS) $(LDIR)$(LIBFT) -lm

debug: $(DEBUG)
	$(HIDE)./$^

# Generates test files for valgrind and gprof
$(TEST): fclean
	$(HIDE)$(CC) $(TFLAG) -o $@ $(SRCS) $(LDIR)$(LIBFT) -lm

test: $(TEST)
	$(HIDE)clear
	$(HIDE)./$^

leak: $(TEST)
	$(HIDE)clear
	$(HIDE)valgrind				\
		--leak-check=full		\
		--track-origins=yes		\
		--show-leak-kinds=all	\
		--read-var-info=yes		\
		--read-inline-info=yes	\
		./$^

time: $(TEST)
	$(HIDE)clear
	$(HIDE)./$(TEST)
	$(HIDE)gprof -b -p $(TEST) gmon.out
	$(MAKE) fclean
