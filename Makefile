# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/10 23:07:12 by seheon            #+#    #+#              #
#    Updated: 2020/10/27 00:14:40 by seyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------------------------
# Echo Colors
# ----------------------------------
NOCOLOR		= \033[0m
RED			= \033[0;31m
GREEN		= \033[0;32m
ORANGE		= \033[0;33m
BLUE		= \033[0;34m
PURPLE		= \033[0;35m
CYAN		= \033[0;36m
LIGHTGRAY	= \033[0;37m
DARKGRAY	= \033[1;30m
LIGHTRED	= \033[1;31m
LIGHTGREEN	= \033[1;32m
YELLOW		= \033[1;33m
LIGHTBLUE	= \033[1;34m
LIGHTPURPLE	= \033[1;35m
LIGHTCYAN	= \033[1;36m
WHITE		= \033[1;37m

# ----------------------------------
# Makefile
# ----------------------------------

DIR_INC	=	./includes/
DIR_SRC	=	./srcs/
DIR_MLX	=	./libs/minilibx/
DIR_FT	=	./libs/libft/

SRC		=
SRCS	=	$(addprefix $(DIR_SRC), $(SRC))
OBJS	=	$(SRCS:.c=.o)

NAME	=	miniRT
NAME_MLX=	libmlx.dylib
NAME_FT	=	libft.a

CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror -I$(DIR_INC) -L$(DIR_FT) -lft
CFRMWRK	=	-framework OpenGL -framework AppKit

CP		=	cp
RM		=	rm -f
MV		=	mv
ECHO	=	echo

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
			@$(ECHO) "Compiled $(YELLOW)" $< " $(GREEN)Successfully$(NOCOLOR)"

$(NAME):	$(NAME_MLX) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(CFRMWRK) -lmlx -o $(NAME)

$(NAME_MLX):
			@$(ECHO) "Summoning $(YELLOW)$(NAME_MLX)$(NOCOLOR) ..."
			@make -C $(DIR_MLX) all
			@$(CP) $(DIR_MLX)/$(NAME_MLX) ./
			@$(ECHO) "Summoned $(YELLOW)$(NAME_MLX)$(YELLOW) $(GREEN)Successfully$(NOCOLOR)"

$(DIR_FT)/$(NAME_FT):
			@$(ECHO) "Summoning $(YELLOW)$(NAME_FT)$(NOCOLOR) ..."
			@make -C $(DIR_FT) all
			@$(ECHO) "Summoned $(YELLOW)$(NAME_FT)$(YELLOW) $(GREEN)Successfully$(NOCOLOR)"


all:		$(NAME)

clean:
			@make -C $(DIR_MLX) clean
			@$(RM) ./$(NAME_MLX)
			@$(ECHO) "Cast out $(RED)$(NAME_MLX)$(NOCOLOR)"
			@$(RM) $(OBJS)
			@$(ECHO) "Cast out $(RED)the Object files$(NOCOLOR)"

fclean:		clean
			@$(RM) $(NAME)
			@$(ECHO) "Cast out $(RED)$(NAME)$(NOCOLOR)"

re:			fclean $(NAME)
