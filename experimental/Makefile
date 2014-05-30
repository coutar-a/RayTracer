##
## Makefile for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
## 
## Made by grelli_t
## Login   <grelli_t@epitech.net>
## 
## Started on  Mon Apr 21 10:06:56 2014 grelli_t
## Last update Mon Apr 21 10:26:42 2014 grelli_t
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -I.

NAME	= rt

SRCS	= alt_int.c \
	  basic_functions.c  \
	  cones.c \
	  cylinders.c \
	  events.c \
	  intersection.c \
	  lumos2.c \
	  lumos.c \
	  main.c \
	  pixel_put_to_image.c \
	  plans.c \
	  rotation2.c \
	  rotation.c \
	  scene_stuff.c \
	  shadows.c \
	  spheres.c \
	  spot.c \
	  stuff.c \
	  translation.c

OBJS	= $(SRCS:.c=.o)

LMX_P	= -L/usr/lib64 -lmlx_$(HOSTTYPE) -L/usr/lib64/X11 -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LMX_P) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
