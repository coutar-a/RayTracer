##
## Makefile for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
## 
## Made by grelli_t
## Login   <grelli_t@epitech.net>
## 
## Started on  Mon Apr 21 10:06:56 2014 grelli_t
## Last update Sat May 31 15:05:01 2014 
##

CC	= gcc

RM	= rm -f

NAME	= rt

LIB	= src/lib/

SRC	= src/

CONF	= src/conf/

SRCS	= $(LIB)basic_functions.c		\
	  $(SRC)events.c			\
	  $(SRC)lumos2.c			\
	  $(SRC)lumos.c				\
	  $(SRC)main.c				\
	  $(SRC)pixel_put_to_image.c		\
	  $(SRC)rotation2.c			\
	  $(SRC)rotation.c			\
	  $(SRC)scene_stuff.c			\
	  $(SRC)shadows.c			\
	  $(SRC)spot.c				\
	  $(SRC)stuff.c				\
	  $(SRC)translation.c			\
	  $(CONF)check.c			\
	  $(CONF)check_error_read_file.c	\
	  $(LIB)epur.c				\
	  $(CONF)fill.c				\
	  $(LIB)my_str.c			\
	  $(CONF)read_file.c			\
	  $(LIB)show_tab.c			\
	  $(LIB)str_to_wordtab.c		\
	  $(LIB)my_strcmp.c			\
	  $(CONF)fill_objects.c			\
	  $(CONF)fill_window.c			\
	  $(LIB)free_tab.c			\
	  $(CONF)fill_ray.c			\
	  $(CONF)fill_sphere.c

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
