# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/18 17:12:33 by kyuki             #+#    #+#              #
#    Updated: 2020/12/11 00:18:27 by kyuki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	ft_mini_ls

NAME_BONUS	=	ft_mini_ls

CC	= gcc

CFLAGS	= -Wall	-Wextra	-Werror

RM		=	rm -f

INCDIR	=	./includes

SRCDIR	=	./srcs

SRCDIR_BONUS = ./bonus
# LIBFT = srcs/libft/

SRCS_LIST	= 	ft_mini_ls.c \
				ft_mini_ls_utils.c \
				ft_strdup.c \
				ft_putstr.c \
				ft_strcmp.c \
				main.c \

BONUS_LIST	=	ft_mini_ls_bonus.c \
		ft_mini_ls_colors_bonus.c \
		ft_mini_ls_flag_bonus.c \
		ft_mini_ls_type_bonus.c \
		ft_mini_ls_utils_bonus.c \
		ft_mini_ls_sort_r_bonus.c \
		ft_mini_ls_sort_upper_s_bonus.c \
		ft_mini_ls_sort_t_bonus.c \
		ft_mini_ls_sort_utils_bonus.c \
		ft_strdup.c \
		ft_putstr.c \
		ft_strcmp.c \
		ft_strncpy.c \
		ft_strlen.c \
		main_bonus.c \

SRCS = $(addprefix $(SRCDIR)/, $(SRCS_LIST))
SRCS_BONUS = $(addprefix $(SRCDIR_BONUS)/, $(BONUS_LIST))

OBJS	=	$(SRCS:%.c=%.o)
OBJS_BONUS	=	$(SRCS_BONUS:%.c=%.o)


.c.o:
			$(CC) $(CFLAGS)	-I $(INCDIR) -c $< -o $@



$(NAME):	$(OBJS)
				echo Compiling $(NAME)
				$(CC) $(CFLAGS)  $(OBJS) -o $(NAME)
				echo ====DONE====


all:		$(NAME)

clean:
				$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
				$(RM) $(NAME) $(NAME_BONUS)

bonus:		$(OBJS_BONUS)
				echo Compiling $(NAME_BONUS)
				$(CC) $(CFLAGS)  $(OBJS_BONUS) -o $(NAME_BONUS)
				echo ====DONE====

re:			fclean all

.PHONY: clean fclean all re