##
## Makefile for wolf3d in /home/coutar_a/Documents/I_graph/wolf3d
## 
## Made by coutar_a
## Login   <coutar_a@epitech.net>
## 
## Started on  Tue Jan  7 16:06:29 2014 coutar_a
## Last update Fri Apr 11 10:58:25 2014 coutar_a
##

SRC	= main.c \
	  basic_functions.c \
	  pixel_put_to_image.c \
	  events.c \
	  cylinders.c \
	  spheres.c \
	  plans.c \
	  cones.c \
	  lumos.c \
	  lumos2.c \
	  intersection.c \
	  alt_int.c \
	  translation.c \
	  rotation2.c \
	  spot.c \
	  scene_stuff.c \
	  shadows.c \
	  stuff.c

##MLX	= -L/usr/lib64 -lmlx -L/usr/lib64/X11 -lXext -lX11 -lm

MLX	= -L/usr/lib64 -lmlx -L/usr/X11/lib -lXext -lX11 -lm

CFLAGS	= -I/usr/X11/include -g3

CC	= cc

RM	= rm -f

NAME	= rtv1

OBJ	= $(SRC:.c=.o)

all:	  $(NAME)

$(NAME):  $(OBJ)
	  $(CC) $(OBJ) -o $(NAME) $(MLX)

clean:
	  $(RM) $(OBJ)

fclean:   clean
	  $(RM) $(NAME)

re:	  fclean all
