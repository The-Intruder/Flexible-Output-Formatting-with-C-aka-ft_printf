/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:12:22 by mnaimi            #+#    #+#             */
/*   Updated: 2021/12/07 16:20:17 by mnaimi           ###   ########.fr       */
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
	t_flags *flags;
	size_t width;
	size_t precision;
	char type;
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
void	ft_putchar(char c);
void	ft_putnchar(char c, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr(int n);
int		ft_isspace(char c);
int		ft_atoi(const char *str);

/* ----------------------- */
/* ft_printf sub-functions */
/* ----------------------- */
t_flags		*get_flags(char **field_ptr);
size_t		get_width(char **field_ptr);
t_fields	*get_data(char *field_ptr, size_t *outpt_len, size_t *index);

void		process_data(t_fields *data, va_list *ap, size_t *outpt_len);
size_t		process_char(t_fields *data, char c);
/* ---------------------------------- END ----------------------------------- */

#endif
