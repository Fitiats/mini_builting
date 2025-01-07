# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trahanta <trahanta@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 12:47:37 by tmory             #+#    #+#              #
#    Updated: 2025/01/07 15:19:31 by trahanta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAG = -Wall -Wextra -Werror -g
RDLFLAG = -lreadline
MAKE = make
MAKECLEAN = make clean
MAKEFCLEAN = make fclean
RM = rm

#             SOURCES FOLDER
#-------------------FOLDER: ms_check_token---------------------------
CHECK_TOKEN = ms_check_token/ms_check_pipe.c \
	ms_check_token/ms_check_quotes.c \
	ms_check_token/ms_check_redirection.c \
	ms_check_token/ms_isbackslash.c \
	ms_check_token/ms_issemicolon.c \
#-------------------FOLDER:ms_lexing----------------------------------
LEXING = ms_lexing/ms_split.c\
#-------------------FOLDER:ms_builtings----------------------------------
BUILTING = ms_builtings/ms_echo.c\
			ms_builtings/ms_export.c\
			ms_builtings/ms_function_built.c\
			ms_builtings/ms_exit.c\
			ms_builtings/ms_unset.c\
			ms_builtings/ms_export_utilities.c\
			ms_builtings/ms_env.c\
#-------------------FOLDER: utilities---------------------------
UTILITIES = utilities/ms_list_management.c \
	utilities/ms_env_management/ms_envcpy.c \
	test_user/test_trahanta/ft_ms_split.c \

#-------------------FOLDER: split_token---------------------------
SPLIT_TOKEN = test_user/split_token/ms_split_token.c \
	test_user/split_token/ms_test_quotes.c \
	test_user/split_token/ms_split_utils.c \
	test_user/split_token/ms_split_byword.c \
	test_user/split_token/ms_split_byword_utils.c \
	test_user/split_token/ms_cleanquotes/ms_clean_quotes.c \
	test_user/split_token/ms_expand.c \

#----------------FOLDER:ms_piping--------------------------
MS_PIPE = ms_piping/utilities/ms_parsing.c \
		ms_piping/utilities/ms_pipe_utilities.c \
		ms_piping/utilities/ms_count_pipe.c \
		ms_piping/ms_env_to_char.c \

#----------------FOLDER:ms_piping--------------------------
MS_EXEC = ms_execution/ms_execution.c \
	ms_execution/ms_execution_b.c \
	ms_execution/ms_exec_ifpipe.c \

#----------------FOLDER:test_trahanta--------------------------
TEST_TRAHANTA = test_user/test_trahanta.c\

#END :        SOURCES FOLDER

SRC = test_user/test_tmory.c \
	$(CHECK_TOKEN) \
	$(UTILITIES) \
	$(SPLIT_TOKEN) \
	$(LEXING)\
	$(BUILTING)\
	$(TEST_TRAHANTA)\
	$(MS_PIPE)\
	$(MS_EXEC)\

OBJ = $(SRC:.c=.o)
NAME_LIB = libft.a
NAME = minishell

all: $(NAME)

$(NAME): $(OBJ)
	@cd libft && $(MAKE)
	@cp libft/libft.a $(NAME_LIB)
	@ar -rcs $(NAME_LIB) $(OBJ)
	$(CC) $(CFLAG) libft.a -o $(NAME) $(RDLFLAG)
	@echo "\033[90m[\033[32;1;5mSuccess\033[0m\033[90m]\033[32m ꧁༺ 𝓶𝓲𝓷𝓲𝓼𝓱𝓮𝓵𝓵 ༻꧂\033[0m"

%.o: %.c
	$(CC) $(CFLAG) -o $@ -c $< 

clean:
	$(RM) -f $(OBJ)
	@cd libft && $(MAKECLEAN)
	@echo "\033[90m[\033[91;5;1mDeleting\033[0m\033[90m]\033[31m ꧁༺ 𝓶𝓲𝓷𝓲𝓼𝓱𝓮𝓵𝓵 ༻꧂  files.o deleted !\033[0m"

fclean: clean
	$(RM) -f $(NAME)
	$(RM) -f $(NAME_LIB)
	@cd libft && $(MAKEFCLEAN)
	@echo "\033[90m[\033[91;5;1mDeleting\033[0m\033[90m]\033[31m ꧁༺ 𝓶𝓲𝓷𝓲𝓼𝓱𝓮𝓵𝓵 ༻꧂  clean !\033[0m"

re: fclean $(NAME)
.PHONY:  all clean fclean re
