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

CC := gcc
CC_FLAGS := -Wall -Wextra -Werror

RCS := ft_printf_getdata.c ft_printf_isdata.c ft_printf_misc.c ft_printf.c

OBJS := $(SRCS:%.c=%.o)

NAME := libprintf.a


all: $(NAME)

$(NAME): $(OBJS) ft_printf.h
	@echo "Creating $(NAME) archive file ...\n"
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	@echo "Creating Object file from $< file ...\n"
	@$(CC) $(CC_FLAGS) -c $< -o $@

compile: re main.c
	@echo "Compiling the main.c ...\n"
	@$(CC) $(CC_FLAGS) -L. -lprintf main.c

execute: compile
	@./a.out | cat -e

clean:
	@echo "Cleaning up Object files ...\n"
	@rm -f *.o

fclean: clean
	@echo "Cleaning up the $(NAME) archive file ...\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re compile execute
