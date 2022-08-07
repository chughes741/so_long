#!-----------------------------------------------------------------------------#
#!                                 GENERICS                                    #
#!-----------------------------------------------------------------------------#

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
DFLAG	=	-D DEBUG -Wall -Werror -Wextra #! Remove before submission
TFLAG	=	-pg -Wall -Werror -Wextra #! Remove before submission
RM		=	rm -rf


#!-----------------------------------------------------------------------------#
#!                                LIBRARIES                                    #
#!-----------------------------------------------------------------------------#

LDIR	=	libft/
LIBFT	=	libft.a
MLXDIR	=	mlx/
MLX		=	libmlx.a

# Generates libft.a
$(LDIR)/$(LIBFT):
	$(HIDE)$(MAKE) -C $(LDIR)

# Generates libmlx.a
$(MLXDIR)/$(MLX):
	$(HIDE)$(MAKE) -C $(MLXDIR)


#!-----------------------------------------------------------------------------#
#!                                TARGETS                                      #
#!-----------------------------------------------------------------------------#

# Dir and file names
NAME	=	so_long
DEBUG	=	so_long_debug #! Remove before submission
TEST	=	so_long_test #! Remove before submission
SRCDIR	=	src/
OBJDIR	=	bin/
SRCS	=	$(wildcard $(SRCDIR)*.c) # Change to file names before sub
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

all: $(LDIR)/$(LIBFT) $(MLXDIR)/$(MLX) $(NAME)

$(NAME): $(OBJS) $(LDIR)/$(LIBFT)
	$(HIDE)$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDIR)$(LIBFT) -lm

$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c
	$(HIDE)mkdir -p $(OBJDIR)
	$(HIDE)$(CC) $(CFLAGS) -c $< -o $@

# Removes objects
clean:
	$(HIDE)$(RM) $(OBJS)
	$(HIDE)$(MAKE) -C $(LDIR) $(MAKE) clean
	$(HIDE)$(MAKE) -C $(MLXDIR) $(MAKE) clean

# Removes objects and executables
fclean: clean
	$(HIDE)$(RM) $(NAME)
	$(HIDE)$(MAKE) -C $(LDIR) $(MAKE) $@
	$(HIDE)$(MAKE) -C $(MLXDIR) $(MAKE) $@
	$(HIDE)$(RM) $(TEST) #! Remove before submission
	$(HIDE)$(RM) $(DEBUG) #! Remove before submission
	$(HIDE)$(RM) *.dSYM #! Remove before submission
	$(HIDE)$(RM) *.out #! Remove before submission

# Removes objects and executables and remakes
re: fclean all


#!-----------------------------------------------------------------------------#
#!                                TESTING                                      #
#!-----------------------------------------------------------------------------#

$(DEBUG): fclean
	$(HIDE)$(CC) $(DFLAG) -o $@ $(SRCS) $(LDIR)$(LIBFT) -lm

$(TEST): fclean
	$(HIDE)$(CC) $(TFLAG) -o $@ $(SRCS) $(LDIR)$(LIBFT) -lm

debug: $(DEBUG)
	$(HIDE)./$^

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
