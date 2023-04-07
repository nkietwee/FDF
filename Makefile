# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 13:49:56 by nkietwee          #+#    #+#              #
#    Updated: 2023/04/07 22:19:02 by nkietwee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT_PATH = libft/
GET_NEXT_LINE_PATH = get_next_line/

FDF_SRCS = ft_fdf.c\
			ft_fillnbr.c\
			ft_printerr.c\
			ft_checkerr.c\

LIBFT_SRCS = ft_atoi.c\
			ft_isdigit.c\
			ft_putstr_fd.c\
			ft_split.c\
			ft_strlen.c\


GET_NEXT_LINE_SRCS = get_next_line.c\
					get_next_line_utils.c\


SRCS = $(FDF_SRCS)\
	   $(addprefix $(LIBFT_PATH), $(LIBFT_SRCS))\
	   $(addprefix $(GET_NEXT_LINE_PATH), $(GET_NEXT_LINE_SRCS))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
