/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:12:22 by mnaimi            #+#    #+#             */
/*   Updated: 2021/12/07 23:37:15 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

/* ------------------------------ LIBRARIES --------------------------------- */
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>

/* -------------------------------- MACROS ---------------------------------- */
# define TRUE 1;
# define FALSE 0;

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
	t_flags	*flags;
	size_t	width;
	int		precision;
	char	type;
} t_fields;

/* ------------------------------ PROTOTYPES -------------------------------- */
int		ft_printf(const char *str_in, ...);
int		ft_isflag(char c);
int		ft_istrue_digit(char c);
int		ft_isdigit(char c);
int		ft_istype(char c);

size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putchar(char c, size_t *outpt_len);
void	ft_putnchar(char c, size_t n, size_t *outpt_len);
void	ft_putstr(char *s, size_t *outpt_len);
void	ft_putstr_len(char *s, size_t len, size_t *outpt_len);
void	ft_putnbr(int n);
int		ft_isspace(char c);
int		ft_atoi(const char *str);

/* ----------------------- */
/* ft_printf sub-functions */
/* ----------------------- */
void	get_flags(char **field_ptr, t_flags *flags);
size_t	get_width(char **field_ptr);
void	get_data(t_fields *data, t_flags *flags, char *field_ptr, \
	size_t *index);
void	process_data(t_fields *data, va_list *ap, size_t *outpt_len);
void	process_char(t_fields *data, char c, size_t *outpt_len);
void	process_str(t_fields *data, char *str, size_t *outpt_len);
/* ---------------------------------- END ----------------------------------- */

#endif
