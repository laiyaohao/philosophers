# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/27 17:31:03 by ylai              #+#    #+#              #
#    Updated: 2024/10/31 18:57:19 by ylai             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo
CC := gcc
CFLAGS := -Wall -Werror -Wextra -g
SRCS_FILE_NAMES := main prt_argc_msg init_data store_params check_data \
									init_table
SRCS := ${addsuffix .c, ${SRCS_FILE_NAMES}}
OBJS := ${SRCS:.c=.o}


all: ${NAME}

clean: 
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o $@

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@