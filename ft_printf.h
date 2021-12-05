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
# define FT_PRINTF

/* ------------------------------ LIBRARIES --------------------------------- */
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>

/* -------------------------------- MACROS ---------------------------------- */
# define TRUE 1;
# define FALSE 0;

/* ------------------------------- TYPEDEF's -------------------------------- */
typedef struct  s_flags
{
    int minus;
    int plus;
    int space;
    int zero;
    int hash;
}   t_flags;

typedef struct  s_field
{
    //char    *parameter;
    t_flags    *flags;
    int     width;
    int     precision;
    //char    *length;
    char    type;
}   t_field;

/* ------------------------------ PROTOTYPES -------------------------------- */
int     ft_printf(const char *str_in, ...);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putchar(char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr(int n);
int     is_width(char c);
int     is_flag(char c);


/* ---------------------------------- END ----------------------------------- */

#endif
