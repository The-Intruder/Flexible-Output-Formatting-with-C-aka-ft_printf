################################################################################
################################################################################
##                                                                            ##
##        ███    ███  █████  ██   ██ ███████ ███████ ██ ██      ███████       ##
##        ████  ████ ██   ██ ██  ██  ██      ██      ██ ██      ██            ##
##        ██ ████ ██ ███████ █████   █████   █████   ██ ██      █████         ##
##        ██  ██  ██ ██   ██ ██  ██  ██      ██      ██ ██      ██            ##
##        ██      ██ ██   ██ ██   ██ ███████ ██      ██ ███████ ███████       ##
##                                                                            ##
################################################################################
################################################################################

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
	ft_printf_utils_misc.c ft_printf_utils_processdata.c \
	ft_printf.c

OBJS := $(SRCS:%.c=%.o)

NAME := libftprintf.a


all: $(NAME)

bonus : fclean all

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

clean:
	@echo "\n$(RED)Cleaning up Object files ...\n$(NC)"
	@rm -f *.o

fclean: clean
	@echo "$(RED)Cleaning up the $(GRA)$(NAME)$(RED) archive file ...\n\n$(NC)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re compile execute
