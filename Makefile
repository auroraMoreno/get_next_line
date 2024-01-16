# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 11:36:38 by aumoreno          #+#    #+#              #
#    Updated: 2024/01/16 16:30:54 by aumoreno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextline.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra 

# ADD BONUS RULE !!!!!!!

SRCS = get_next_line.c get_next_line_utils.c \
		get_next_line_bonus.c get_next_line_bonus_utils.c

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
