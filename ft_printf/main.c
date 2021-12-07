/* ************************************************************************** */
/* ************************************************************************** */
/* **                                                                      ** */
/* **              ███    ███  █████  ██ ███    ██     ██████              ** */
/* **              ████  ████ ██   ██ ██ ████   ██    ██                   ** */
/* **              ██ ████ ██ ███████ ██ ██ ██  ██    ██                   ** */
/* **              ██  ██  ██ ██   ██ ██ ██  ██ ██    ██                   ** */
/* **              ██      ██ ██   ██ ██ ██   ████ ██  ██████              ** */
/* **                                                                      ** */
/* ************************************************************************** */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int a;
	//ft_printf("srjtjrtjewtj %+-0# 20.15d kuasigalkghiug");
	a = ft_printf("abcd %c", '0');
	putchar('\n');
	ft_putnbr(a);
	putchar('\n');
	a = printf("abcd %c", '0');
	putchar('\n');
	ft_putnbr(a);
	putchar('\n');
	/*ft_printf(" %c ", '0');
	putchar('\n');
	printf(" %c ", '0');
	putchar('\n');
	ft_printf(" %c", '0' - 256);
	putchar('\n');
	printf(" %c", '0' - 256);
	putchar('\n');
	ft_printf("%c ", '0' + 256);
	putchar('\n');
	printf("%c ", '0' + 256);
	putchar('\n');
	ft_printf(" %c %c %c ", '0', 0, '1');
	putchar('\n');
	printf(" %c %c %c ", '0', 0, '1');
	putchar('\n');
	ft_printf(" %c %c %c ", ' ', ' ', ' ');
	putchar('\n');
	printf(" %c %c %c ", ' ', ' ', ' ');
	putchar('\n');
	ft_printf(" %c %c %c ", '1', '2', '3');
	putchar('\n');
	printf(" %c %c %c ", '1', '2', '3');
	putchar('\n');
	ft_printf(" %c %c %c ", '2', '1', 0);
	putchar('\n');
	printf(" %c %c %c ", '2', '1', 0);
	putchar('\n');
	ft_printf(" %c %c %c ", 0, '1', '2');
	putchar('\n');
	printf(" %c %c %c ", 0, '1', '2');
	putchar('\n');	
	
	printf("\'%-20c\'\n", 't');
	printf("\'%20c\'\n", 't');
	*/
	return (0);
}
