##
## Makefile for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
## 
## Made by grelli_t
## Login   <grelli_t@epitech.net>
## 
## Started on  Mon Apr 21 10:06:56 2014 grelli_t
## Last update Wed Jun  4 16:15:26 2014 grelli_t
##

CC	= gcc ##Vire le g3 avant de rendre connard.

RM	= rm -f

NAME	= rt

LIB	= src/lib/

SRC	= src/

CONF	= src/conf/

SRCS	= $(CONF)fill_spot.c			\
	  $(CONF)fill_spots.c			\
	  $(CONF)check.c			\
	  $(CONF)read_file.c			\
	  $(CONF)check_error_read_file.c	\
	  $(CONF)fill_objects.c			\
	  $(CONF)fill_color.c			\
	  $(CONF)fill_pos.c			\
	  $(CONF)fill_rot.c			\
	  $(CONF)fill_height.c			\
	  $(CONF)fill_texture.c			\
	  $(CONF)fill_transparency.c		\
	  $(CONF)fill_negative.c		\
	  $(CONF)fill_angle.c			\
	  $(CONF)fill_window.c			\
	  $(CONF)fill_ray.c			\
	  $(CONF)fill_checkerboard.c		\
	  $(CONF)fill_color_checkerboard.c	\
	  $(CONF)fill_size_checkerboard.c	\
	  $(CONF)fill_all_object.c		\
	  $(SRC)events.c			\
	  $(SRC)lumos2.c			\
	  $(SRC)lumos.c				\
	  $(SRC)main.c				\
	  $(LIB)pixel_put_to_image.c		\
	  $(SRC)rotation2.c			\
	  $(SRC)rotation.c			\
	  $(SRC)shadows.c			\
	  $(SRC)stuff.c				\
	  $(SRC)translation.c			\
	  $(LIB)epur.c				\
	  $(LIB)my_str.c			\
	  $(LIB)show_tab.c			\
	  $(LIB)str_to_wordtab.c		\
	  $(LIB)my_strcmp.c			\
	  $(LIB)free_tab.c 			\
	  $(SRC)intersection_computing.c \
	  $(SRC)normal_computing.c       \
	  $(SRC)intersection_functions.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS	+= -I./include
CFLAGS  += -I/usr/X11/include ## à commenter si vous n'êtes pas coutar_a !
CFLAGS  += -g3

LMX_P	= -L/usr/lib64 -lmlx_$(HOSTTYPE) -L/usr/lib64/X11 -lXext -lX11 -lm

MLX_A	= -L/usr/lib64 -lmlx -L/usr/X11/lib -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LMX_P) $(CFLAGS)

ambroise: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(MLX_A) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
