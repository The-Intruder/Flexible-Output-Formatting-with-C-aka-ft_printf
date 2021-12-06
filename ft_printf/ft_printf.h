/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:12:22 by mnaimi            #+#    #+#             */
/*   Updated: 2021/12/04 20:18:15 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
#define FT_PRINTF

/* ------------------------------ LIBRARIES --------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/* -------------------------------- MACROS ---------------------------------- */
#define TRUE 1;
#define FALSE 0;

/* ------------------------------- TYPEDEF's -------------------------------- */
typedef struct s_flags
{
	int minus;
	int plus;
	int space;
	int zero;
	int hash;
} t_flags;

typedef struct s_fields
{
	// char      *parameter;
	t_flags *flags;
	size_t width;
	size_t precision;
	// char		*length;
	char type;
} t_fields;

/* ------------------------------ PROTOTYPES -------------------------------- */
int		ft_printf(const char *str_in);
int		is_flag(char c);
int		is_true_digit(char c);
int		is_digit(char c);
int		is_type(char c);

size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putchar(char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr(int n);
int		ft_isspace(char c);
int		ft_atoi(const char *str);

/* ----------------------- */
/* ft_printf sub-functions */
/* ----------------------- */
void		set_placeholder_fields(t_fields *field_data, t_flags *f, \
	size_t *w, size_t p, char t);

t_flags		*get_flags(char **field_ptr);
size_t		get_width(char **field_ptr);
t_fields	*get_data(char *field_ptr, size_t *printd_outpt_len);

/* ---------------------------------- END ----------------------------------- */

#endif
