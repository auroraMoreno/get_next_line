# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 11:36:38 by aumoreno          #+#    #+#              #
#    Updated: 2024/03/27 11:27:51 by aumoreno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextline.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra 

SRCS = get_next_line.c get_next_line_utils.c

SRCS_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
			@ar crs $(NAME) $(OBJS)

bonus: $(OBJS_BONUS) 
		@ar crs $(NAME) $(OBJS_BONUS)

all: $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
