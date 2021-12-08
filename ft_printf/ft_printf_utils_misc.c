/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_misc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:07:32 by mnaimi            #+#    #+#             */
/*   Updated: 2021/12/07 23:29:58 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* -------------------------------------------------------------------------- */

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* -------------------------------------------------------------------------- */

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*myptr;

	i = 0;
	myptr = (char *)s;
	while (i++ < n)
		*(myptr++) = 0;
}

/* -------------------------------------------------------------------------- */

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = (char *) malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return ((void *) ptr);
}

/* -------------------------------------------------------------------------- */

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*output_str;
	size_t	output_i;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	output_str = (char *) malloc((i + 1) * sizeof(char));
	if (!output_str)
		return (NULL);
	ft_bzero(output_str, (i + 1) * sizeof(char));
	if (!i)
		return (output_str);
	i = 0;
	output_i = 0;
	while (s1[i])
		output_str[output_i++] = s1[i++];
	i = 0;
	while (s2[i])
		output_str[output_i++] = s2[i++];
	return (output_str);
}

/* -------------------------------------------------------------------------- */

void	ft_putchar(char c, size_t *outpt_len)
{
	write(1, &c, 1);
	*outpt_len += 1;
}

/* -------------------------------------------------------------------------- */

void	ft_putnchar(char c, size_t n, size_t *outpt_len)
{
	if (!c)
	{
		write(1, "(null)", 6);
		*outpt_len += 6;
	}
	else
	{
		*outpt_len += n;
		while (n-- != 0)
		write(1, &c, 1);
	}
}

/* -------------------------------------------------------------------------- */

void	ft_putstr(char *s, size_t *outpt_len)
{
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*outpt_len += 6;
	}
	else
	{
		write(1, s, ft_strlen(s));
		*outpt_len += ft_strlen(s);
	}
}

/* -------------------------------------------------------------------------- */

void	ft_putstr_len(char *s, size_t len, size_t *outpt_len)
{
	if (s == NULL)
	{
		write(1, "(null)", 6);
		len = 6;
	}
	else
		write(1, s, len);
	*outpt_len += len;
}

/* -------------------------------------------------------------------------- */

void	ft_putnbr(int n, size_t *outpt_len)
{
	if (n >= 0 && n < 10)
		ft_putchar(n + 48, outpt_len);
	else if (n == -2147483648)
		ft_putstr("-2147483648", outpt_len);
	else if (n < 0 && n > -2147483648)
	{
		ft_putchar('-', outpt_len);
		ft_putnbr(n * (-1), outpt_len);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10, outpt_len);
		ft_putnbr(n % 10, outpt_len);
	}
}

/* -------------------------------------------------------------------------- */

int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

/* -------------------------------------------------------------------------- */

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	sum;
	char	sign;

	i = 0;
	sum = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	while (ft_isdigit(str[i]))
		sum = (sum * 10) + (str[i++] - '0');
	return (sum * sign);
}

/* -------------------------------------------------------------------------- */

void	ft_puthex_adrs(unsigned long n, size_t *outpt_len)
{
	if (n < 10)
		ft_putchar(n + 48, outpt_len);
	else if (n >= 10 && n <= 15)
	 	ft_putchar(n + 87, outpt_len);
	else if (n > 15)
	{
		ft_puthex_adrs(n / 16, outpt_len);
		ft_puthex_adrs(n % 16, outpt_len);
	}
}

/* -------------------------------------------------------------------------- */

void	get_hex_adrs_size(unsigned long n, size_t *hex_size)
{
	if (n <= 15)
		(*hex_size) += 1;
	else if (n > 15)
	{
		get_hex_adrs_size(n / 16, hex_size);
		get_hex_adrs_size(n % 16, hex_size);
	}
}

/* -------------------------------------------------------------------------- */

void	ft_puthex(unsigned int n, size_t *outpt_len, int the_case)
{
	if (n < 10)
		ft_putchar(n + 48, outpt_len);
	else if (n >= 10 && n <= 15)
	 	ft_putchar(n + the_case, outpt_len);
	else if (n > 15)
	{
		ft_puthex(n / 16, outpt_len, the_case);
		ft_puthex(n % 16, outpt_len, the_case);
	}
}

/* -------------------------------------------------------------------------- */

void	get_hex_size(unsigned int n, size_t *hex_size)
{
	if (n <= 15)
		(*hex_size) += 1;
	else if (n > 15)
	{
		get_hex_size(n / 16, hex_size);
		get_hex_size(n % 16, hex_size);
	}
}

/* -------------------------------------------------------------------------- */

void	ft_puthexa_prefix(unsigned int n, int isflag, char c, size_t *outpt_len)
{
	if (isflag && n)
	{
		if (c == 'x')
			ft_putstr_len("0x", 2, outpt_len);
		else if (c == 'X')
			ft_putstr_len("0X", 2, outpt_len);
	}
}

/* -------------------------------------------------------------------------- */