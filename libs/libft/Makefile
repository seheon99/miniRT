# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/27 00:16:18 by seyu              #+#    #+#              #
#    Updated: 2020/10/27 21:24:01 by seyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	$(wildcard srcs/libft/*.c) \
			$(wildcard srcs/ft_printf/*.c) \
			$(wildcard srcs/ft_printf/*/*.c)
SRCS	=	$(addprefix $(DIR_SRC), $(SRC))
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