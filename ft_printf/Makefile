# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by ███████ ██        #+#    #+#              #
#    Updated: 2021/12/09 23:53:17 by mnaimi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NC := \033[31;0m
RED := \033[0;31;1m
YEL := \033[0;33;1m
GRA := \033[0;37;1m
CYN := \033[0;36;1m
GRN := \033[0;32;1m
MGN := \033[0;35;1m
BLU := \033[0;34;1m

CC := gcc
CC_FLAGS := -Wall -Wextra -Werror

SRCS := ft_printf_utils_getdata.c ft_printf_utils_isdata.c \
	ft_printf_utils_misc_1st.c ft_printf_utils_misc_2nd.c \
	ft_printf_utils_misc_3rd.c ft_printf_utils_misc_4th.c \
	ft_printf_utils_processdata_1st.c \
	ft_printf_utils_processdata_2nd.c ft_printf.c

OBJS := $(SRCS:%.c=%.o)

NAME := libftprintf.a


all: $(NAME)

bonus : re

$(NAME): $(OBJS) ft_printf.h
	@echo "\n$(BLU)Creating $(GRA)$(NAME) $(BLU)archive file ...$(NC)\n"
	@ar rcs $(NAME) $(OBJS)
	@echo "\n$(GRN)Library created successfully ...\n$(NC)"

%.o: %.c
	@echo "$(MGN)Creating Object file from $(GRA)$< $(MGN)file ...\n$(NC)"
	@$(CC) $(CC_FLAGS) -o $@ -c $<

compile: re main.c
	@echo "\n$(YEL)Compiling the $(GRA)main.c $(YEL)...\n\n$(NC)"
	@$(CC) $(CC_FLAGS) main.c -L. -lftprintf

execute: compile a.out
	@echo "$(CYN) => Output:\n‾‾‾‾‾‾‾‾‾‾‾‾‾‾$(NC)"
	@./a.out
	@echo "$(CYN)______________$(NC)\n"
	@echo "$(RED)Removing $(GRA)$(NAME)$(RED), $(GRA)*.o\
	$(RED) files, and the $(GRA)./a.out$(RED) file ...$(NC)\n"
	@rm -f a.out $(NAME) *.o

clean:
	@echo "\n$(RED)Cleaning up Object files ...\n$(NC)"
	@rm -f *.o

fclean: clean
	@echo "$(RED)Cleaning up the $(GRA)$(NAME)$(RED) archive file ...\n\n$(NC)"
	@rm -f $(NAME)

exclean:
	@echo "$(RED)Cleaning up the $(GRA)./a.out$(RED) executable file ...\n\n$(NC)"
	@rm -f a.out


re: fclean all

.PHONY: all clean fclean re compile execute exclean
