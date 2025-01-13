# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/27 17:31:03 by ylai              #+#    #+#              #
#    Updated: 2025/01/13 21:07:53 by ylai             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo
CC := cc
CFLAGS := -Wall -Werror -Wextra -g -o3 -pthread #-fsanitize=thread
SRC_FOLDER := src/

INIT_FOLDER := init/
INIT_FILE_NAMES := check_data init_data store_params init_table
INIT_FILES := ${addprefix ${INIT_FOLDER}, ${addsuffix .c, ${INIT_FILE_NAMES}}}

CLEANUP_FOLDER := cleanup/
CLEANUP_FILE_NAMES := free_table
CLEANUP_FILES := \
			${addprefix ${CLEANUP_FOLDER}, ${addsuffix .c, ${CLEANUP_FILE_NAMES}}}

UTILS_FOLDER := utils/
UTILS_FILE_NAMES := ft_atol prt_argc_msg get_time check print
UTILS_FILES := \
			${addprefix ${UTILS_FOLDER}, ${addsuffix .c, ${UTILS_FILE_NAMES}}}

MAIN_FOLDER := main/
MAIN_FILE_NAMES := main start actions
MAIN_FILES := ${addprefix ${MAIN_FOLDER}, ${addsuffix .c, ${MAIN_FILE_NAMES}}}

SRC := ${addprefix ${SRC_FOLDER}, ${INIT_FILES}} \
			${addprefix ${SRC_FOLDER}, ${CLEANUP_FILES}} \
			${addprefix ${SRC_FOLDER}, ${UTILS_FILES}} \
			${addprefix ${SRC_FOLDER}, ${MAIN_FILES}}
OBJS := ${SRC:.c=.o}


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