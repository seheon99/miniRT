# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/27 00:16:18 by seyu              #+#    #+#              #
#    Updated: 2020/10/27 00:20:42 by seyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=
SRCS	=	$(addprefix $(DIR_SRC), $(SRC))
OBJS	=	$(SRCS:.c=.o)

NAME	=	libft.a

CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror -g

RM		=	rm -f

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all