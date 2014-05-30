##
## Makefile for Makefile in /home/lancel_e/Documents/DIVERS/script/base Makefile
## 
## Made by lancel_e
## Login   <lancel_e@epitech.net>
## 
## Started on  Tue Jan  7 14:24:41 2014 lancel_e
## Last update Thu May 29 15:29:45 2014 grelli_t
##

CC	= clang

RM	= rm -f

CFLAGS	+= -I headers/

CFLAGS	+= -g3

NAME	= ./rt

SRCS	= srcs/check.c			\
	  srcs/check_error_read_file.c	\
	  srcs/epur.c			\
	  srcs/fill.c			\
	  srcs/my_str.c			\
	  srcs/read_file.c		\
	  srcs/show_tab.c		\
	  srcs/str_to_wordtab.c		\
	  srcs/my_strcmp.c		\
	  srcs/fill_objects.c		\
	  srcs/fill_window.c		\
	  srcs/free_tab.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
