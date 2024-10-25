# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 14:25:41 by insoares          #+#    #+#              #
#    Updated: 2024/09/23 17:47:27 by insoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc -g
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror
NAME			= libft.a
PRINTF_DIR = extra/ft_printf
GET_NET_LINE_DIR = extra/Get_Next_Line
LIB_FUNC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c\
		   ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c\
	  	   ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
	  	   ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		   $(PRINTF_DIR)/ft_printf.c $(PRINTF_DIR)/ft_printf_utils.c $(PRINTF_DIR)/ft_printf_utils2.c\
		   $(GET_NET_LINE_DIR)/get_next_line.c $(GET_NET_LINE_DIR)/get_next_line_utils.c

LIB_OBJS 		= $(LIB_FUNC:.c=.o)

all: 			$(NAME)

$(NAME): 		$(LIB_OBJS)
				ar rc $(NAME) $(LIB_OBJS)

clean:
				$(RM) $(LIB_OBJS)

fclean: 		clean
				$(RM) $(NAME)

re: 			clean all

PHONY: all clean fclean re