#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: kgomera <kgomera@student.wethinkcode.co.za>+#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2020/07/10 16:31:20 by kgomera           #+#    #+#             *#
#*   Updated: 2020/07/10 20:38:48 by kgomera          ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = ft_ls

LIBFT = libft/libft.a

CC = gcc

#CFLAGS = -Wall -Wextra -Werror

SRCS = ft_ls.c ft_sort.c process.c display.c get.c

OBJS = ft_ls.o ft_sort.o process.o display.o get.o


all: $(NAME)

$(NAME):
		make -C libft all
			$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME) -g -std=gnu99

clean:
		make -C libft clean
			rm -f $(OBJS)

fclean: clean
		make -C libft fclean
			rm -f $(NAME)

re : fclean all
