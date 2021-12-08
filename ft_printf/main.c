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
	a = printf("\"%1s\"\n", "");
	printf("%d\n", a);
	a = ft_printf("\"%1s\"\n", "");
	printf("%d\n\n", a);
	
	a = printf("\"%-1s\"\n", "");
	printf("%d\n", a);
	a = ft_printf("\"%-1s\"\n", "");
	printf("%d\n\n", a);
	
	a = printf("\" %-2s\"\n", "");
	printf("%d\n", a);
	a = ft_printf("\" %-2s\"\n", "");
	printf("%d\n\n", a);
	
	a = printf("\"%-3s \"\n", "");
	printf("%d\n", a);
	a = ft_printf("\"%-3s \"\n", "");
	printf("%d\n\n", a);
	
	a = printf("\" %-0s \"\n", "");
	printf("%d\n", a);
	a = ft_printf("\" %-0s \"\n", "");
	printf("%d\n\n", a);
	
	a = printf("\" %-s \"\n", "-");
	printf("%d\n", a);
	a = ft_printf("\" %-s \"\n", "-");
	printf("%d\n\n", a);
	
	a = printf("\" %-1s %-2s \"\n", "", "-");
	printf("%d\n", a);
	a = ft_printf("\" %-1s %-2s \"\n", "", "-");
	printf("%d\n\n", a);
	
	a = printf("\" %-3s %-4s \"\n", " - ", "");
	printf("%d\n", a);
	a = ft_printf("\" %-3s %-4s \"\n", " - ", "");
	printf("%d\n\n", a);
	
	a = printf("\" <%-2s> <%-3s> <%-4s> <%-5s> \"\n", " - ", "", "4", "");
	printf("%d\n", a);
	a = ft_printf("\" <%-2s> <%-3s> <%-4s> <%-5s> \"\n", " - ", "", "4", "");
	printf("%d\n\n", a);
	
	a = printf("\" %-3s %-3s %-4s %-5s %-3s \"\n", " - ", "", "4", "", "2 ");
	printf("%d\n", a);
	a = ft_printf("\" %-3s %-3s %-4s %-5s %-3s \"\n", " - ", "", "4", "", "2 ");
	printf("%d\n\n", a);
	
	return (0);
}


	// char s2[] = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
	// a = printf("\"%s\"\n", "");
	// printf("%d\n", a);
	// a = ft_printf("\"%s\"\n", "");
	// printf("%d\n\n", a);
	// a = printf("\" %s\"\n", "");
	// printf("%d\n", a);
	// a = ft_printf("\" %s\"\n", "");
	// printf("%d\n\n", a);
	// a = printf("\"%s \"\n", "");
	// printf("%d\n", a);
	// a = ft_printf("\"%s \"\n", "");
	// printf("%d\n\n", a);
	// a = printf("\" %s \"\n", "");
	// printf("%d\n", a);
	// a = ft_printf("\" %s \"\n", "");
	// printf("%d\n\n", a);
	// a = printf("\" %s \"\n", "-");
	// printf("%d\n", a);
	// a = ft_printf("\" %s \"\n", "-");
	// printf("%d\n\n", a);
	// a = printf("\" %s %s \"\n", "", "-");
	// printf("%d\n", a);
	// a = ft_printf("\" %s %s \"\n", "", "-");
	// printf("%d\n\n", a);
	// a = printf("\" %s %s \"\n", " - ", "");
	// printf("%d\n", a);
	// a = ft_printf("\" %s %s \"\n", " - ", "");
	// printf("%d\n\n", a);
	// a = printf("\" %s %s %s %s %s\"\n", " - ", "", "4", "", s2);
	// printf("%d\n", a);
	// a = ft_printf("\" %s %s %s %s %s\"\n", " - ", "", "4", "", s2);
	// printf("%d\n\n", a);
	// a = printf("\" %s %s %s %s %s \"\n", " - ", "", "4", "", "2 ");
	// printf("%d\n", a);
	// a = ft_printf("\" %s %s %s %s %s \"\n", " - ", "", "4", "", "2 ");
	// printf("%d\n\n", a);
	// a = printf("\" NULL %s NULL \"\n", NULL);
	// printf("%d\n", a);
	// a = ft_printf("\" NULL %s NULL \"\n", NULL);
	// printf("%d\n\n", a);

	// a = printf("\"%-1c\"\n", '0');
	// printf("%d\n", a);
	// a = ft_printf("\"%-1c\"\n", '0');
	// printf("%d\n", a);
	// putchar('\n');
	// a = printf("\" %-2c \"\n", '0');
	// printf("%d\n", a);
	// a = ft_printf("\" %-2c \"\n", '0');
	// printf("%d\n", a);
	// putchar('\n');
	// a = printf("\" %-3c\"\n", '0' - 256);
	// printf("%d\n", a);
	// a = ft_printf("\" %-3c\"\n", '0' - 256);
	// printf("%d\n", a);
	// putchar('\n');
	// a = printf("\"%-4c \"\n", '0' + 256);
	// printf("%d\n", a);
	// a = ft_printf("\"%-4c \"\n", '0' + 256);
	// printf("%d\n", a);
	// putchar('\n');
	// a = printf("\" %-1c %-2c %-3c \"\n", '0', 0, '1');
	// printf("%d\n", a);
	// a = ft_printf("\" %-1c %-2c %-3c \"\n", '0', 0, '1');
	// printf("%d\n", a);
	// putchar('\n');
	// a = printf("\" %-1c %-2c %-3c \"\n", ' ', ' ', ' ');
	// printf("%d\n", a);
	// a = ft_printf("\" %-1c %-2c %-3c \"\n", ' ', ' ', ' ');
	// printf("%d\n", a);
	// putchar('\n');
	// a = printf("\" %-1c %-2c %-3c \"\n", '1', '2', '3');
	// printf("%d\n", a);
	// a = ft_printf("\" %-1c %-2c %-3c \"\n", '1', '2', '3');
	// printf("%d\n", a);
	// putchar('\n');
	// a = printf("\" %-1c %-2c %-3c \"\n", '2', '1', 0);
	// printf("%d\n", a);
	// a = ft_printf("\" %-1c %-2c %-3c \"\n", '2', '1', 0);
	// printf("%d\n", a);
	// putchar('\n');
	// a = printf("\" %-1c %-2c %-3c \"\n", 0, '1', '2');
	// printf("%d\n", a);
	// a = ft_printf("\" %-1c %-2c %-3c \"\n", 0, '1', '2');
	// printf("%d\n", a);
	// putchar('\n');