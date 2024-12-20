# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmory <tmory@student.42antananarivo.mg>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 14:38:25 by tmory             #+#    #+#              #
#    Updated: 2024/12/16 06:53:14 by tmory            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAG = -Wall -Wextra -Werror
RM = rm
SRC = ft_atoi.c ft_atol.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c ft_printf.c ft_printf_utilities.c ft_putchar_printf.c ft_putnbr_base.c ft_putnbr_ui.c ft_putnbr.c \
		lst/ft_lstnew_bonus.c ./lst/ft_lstadd_front_bonus.c ./lst/ft_lstsize_bonus.c \
		./lst/ft_lstlast_bonus.c ./lst/ft_lstadd_back_bonus.c ./lst/ft_lstdelone_bonus.c ./lst/ft_lstclear_bonus.c ./lst/ft_lstiter_bonus.c \
		./gnl/get_next_line.c ./gnl/get_next_line_utils.c \

OBJ = $(SRC:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
	@echo "\033[90m[\033[32;1;5mSuccess\033[0m\033[90m]\033[32m Successfully compiled Libft.\033[0m"

%.o: %.c
	$(CC) $(CFLAG) -o $@ -c $<

clean:
	$(RM) -f $(OBJ) $(OBJB)

fclean: clean
	$(RM) -f $(NAME)

re: fclean $(NAME)
.PHONY:  all clean fclean re
