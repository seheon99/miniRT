# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/27 00:16:18 by seyu              #+#    #+#              #
#    Updated: 2020/10/29 01:33:46 by seyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_SRC	=	srcs/
SRCS	=	$(wildcard $(DIR_SRC)/libft/*.c) \
			$(wildcard $(DIR_SRC)/ft_printf/*.c) \
			$(wildcard $(DIR_SRC)/ft_printf/*/*.c)
OBJS	=	$(SRCS:.c=.o)

NAME	=	libft.a

CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror -g -Iincludes

RM		=	rm -f

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@ar rc $(NAME) $(OBJS)

all:		$(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all
