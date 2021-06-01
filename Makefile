# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egrazina <egrazina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/01 20:58:39 by egrazina          #+#    #+#              #
#    Updated: 2021/06/01 21:04:36 by egrazina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= $(wildcard ./srcs/*.c)

OBJS		= ${SRCS:.c=.o}

INCDIR		= includes

NAME		= libftprintf.a

CC			= gcc

ARRC		= ar rcs

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror 

.c.o: 
			${CC} -g ${CFLAGS} -c $^ -o ${<:.c=.o} -I${INCDIR}

$(NAME):	$(OBJS)
				${ARRC} $(NAME) $(OBJS)

all:		${NAME}

bonus:		${NAME}

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus