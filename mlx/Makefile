# Hides calls
VERBOSE	=	FALSE
ifeq ($(VERBOSE),TRUE)
	HIDE =
else
	HIDE = @
endif

# Variables
NAME	=	libmlx.a
SRC		=	mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m \
			mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+	=	mlx_png.c mlx_mouse.m
OBJ1	=	$(SRC:.c=.o)
OBJ		=	$(OBJ1:.m=.o)
CFLAGS	=	-Wno-deprecated
CFLAGS+	=	-O2

RM		=	rm -rf

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: $(NAME)

$(NAME): $(OBJ)
	$(HIDE)ar -r $(NAME) $(OBJ)
	$(HIDE)ranlib $(NAME)

clean:
	$(HIDE)$(RM) $(OBJ) *~
	$(HIDE)$(RM) mlx_app

fclean: clean
	$(HIDE)$(RM) $(NAME)

re: clean all
