##
## Makefile for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
## 
## Made by grelli_t
## Login   <grelli_t@epitech.net>
## 
## Started on  Mon Apr 21 10:06:56 2014 grelli_t
## Last update Sat May 31 14:21:33 2014 
##

CC	= gcc

RM	= rm -f

NAME	= rt

LIB	= src/lib/

SRC	= src/

SRCS	= $(SRC)alt_int.c		\
	  $(SRC)basic_functions.c	\
	  $(SRC)cones.c			\
	  $(SRC)cylinders.c		\
	  $(SRC)events.c		\
	  $(SRC)intersection.c		\
	  $(SRC)lumos2.c		\
	  $(SRC)lumos.c			\
	  $(SRC)main.c			\
	  $(SRC)pixel_put_to_image.c	\
	  $(SRC)plans.c			\
	  $(SRC)rotation2.c		\
	  $(SRC)rotation.c		\
	  $(SRC)scene_stuff.c		\
	  $(SRC)shadows.c		\
	  $(SRC)spheres.c		\
	  $(SRC)spot.c			\
	  $(SRC)stuff.c			\
	  $(SRC)translation.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	+= -I./include

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
