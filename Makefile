##
## EPITECH PROJECT, 2023
## anim_csfml
## File description:
## Makefile
##

NAME = my_rpg

CC = gcc

SRCS = $(shell find $(SOURCEDIR) -name '*.c')

OBJS =  $(SRCS:.c=.o)

CFLAGS = -g -Wall -Wextra

CSFML = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(CSFML)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

PHONY: all clean fclean re
