# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/10 23:07:12 by seheon            #+#    #+#              #
#    Updated: 2020/10/28 02:32:57 by seyu             ###   ########.fr        #
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

SRCS	=	$(wildcard $(DIR_SRC)/*.c) \
			$(wildcard $(DIR_SRC)/*/*.c) \
			$(wildcard $(DIR_SRC)/*/*/*.c) \
			$(wildcard $(DIR_SRC)/*/*/*/*.c) \
			$(wildcard $(DIR_SRC)/*/*/*/*/*.c)
OBJS	=	$(SRCS:.c=.o)

NAME	=	miniRT
NAME_MLX=	libmlx.dylib
NAME_FT	=	libft.a

CC		=	clang
CFLAGS	=	-I$(DIR_INC)# -Wall -Wextra -Werror
CLIBFMW	=	-L$(DIR_FT) -lft -framework OpenGL -framework AppKit

CP		=	cp
RM		=	rm -f
MV		=	mv
ECHO	=	echo

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
			@$(ECHO) "Compiled $(YELLOW)" $< " $(GREEN)Successfully$(NOCOLOR)"

$(NAME):	$(NAME_MLX) $(DIR_FT)/$(NAME_FT) $(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) $(CLIBFMW) -lmlx -o $(NAME)
			@$(ECHO) "Maked $(LIGHTBLUE)$(NAME)$(NOCOLOR) $(GREEN)Successfully$(NOCOLOR)"
			@$(ECHO) "You can render your $(LIGHTGREEN).rt files$(NOCOLOR) with $(LIGHTBLUE)$(NAME)$(NOCOLOR)"
			@$(ECHO) " $(BLUE)>$(NOCOLOR) ./$(NAME) wolf.rt cat.rt ..."

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

bonus:		$(NAME)

clean:
			@make -C $(DIR_MLX) clean
			@$(ECHO) "Cast out $(RED)MLX$(NOCOLOR)"
			@make -C $(DIR_FT) clean
			@$(ECHO) "Cast out $(RED)FT$(NOCOLOR)"
			@$(RM) $(OBJS)
			@$(ECHO) "Cast out $(RED)$(NAME)$(NOCOLOR)"

fclean:
			@make -C $(DIR_MLX) clean
			@$(RM) ./$(NAME_MLX)
			@$(ECHO) "Cast out $(RED)MLX$(NOCOLOR)"
			@make -C $(DIR_FT) fclean
			@$(ECHO) "Cast out $(RED)FT$(NOCOLOR)"
			@$(RM) $(OBJS)
			@$(ECHO) "Cast out $(RED)$(NAME)$(NOCOLOR)"
			@$(RM) $(NAME)
			@$(ECHO) "Remove $(RED)$(NAME)$(NOCOLOR)"
			@$(RM) **/*\ *.o **/*\ *.swift* **/*\ *.dylib **/*\ *.a

re:			fclean $(NAME)
