# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 16:03:12 by insoares          #+#    #+#              #
#    Updated: 2024/10/24 17:28:48 by insoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PIPEX_FUNC = pipex.c pipex_utils.c 
PIPEX_OBJS =  $(PIPEX_FUNC:.c=.o)
LIBFT = libft

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = pipex

RM = rm -rf

all: $(NAME)

$(NAME): $(PIPEX_OBJS)
	$(MAKE) all -C $(LIBFT)
	$(CC) $(CFLAGS) $(PIPEX_OBJS) -o $(NAME) ./$(LIBFT)/$(LIBFT).a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(PIPEX_OBJS)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT)
	
re: fclean all

.PHONY: all clean fclean re