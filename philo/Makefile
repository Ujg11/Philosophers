# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 11:28:37 by ojimenez          #+#    #+#              #
#    Updated: 2023/12/27 15:00:44 by ojimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

HEADER = philosophers.h

OBJECTS = main.o check_arguments.o init.o errors.o utils.o thread.o state_change.o

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER) Makefile
		$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)
		@printf "\n$(COLOR)$(KAOMOJI_SUCCESS) Successfully compiled! $(COLOR_RESET)"

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJECTS)
	@echo "Clean done, objects removed"

fclean: clean
	rm -f $(NAME)
	@echo "FClean done, all removed"

re: fclean all

.PHONY: re all clean fclean

