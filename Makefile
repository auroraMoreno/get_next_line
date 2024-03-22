# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 11:36:38 by aumoreno          #+#    #+#              #
#    Updated: 2024/03/18 17:49:33 by aumoreno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextline.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra 

# ADD BONUS RULE !!!!!!!

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
			@ar crs $(NAME) $(OBJS)

all : $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
