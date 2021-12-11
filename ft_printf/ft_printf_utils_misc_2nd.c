/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_misc_2nd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:35:08 by mnaimi            #+#    #+#             */
/*   Updated: 2021/12/11 13:21:40 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		write(1, "(null)", len);
	else
		write(1, s, len);
	*outpt_len += len;
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

int	ft_ispresign(t_fields *data, int n)
{
	if (n < 0 || (n >= 0 && (data->flags->plus || data->flags->space)))
		return (1);
	return (0);
}

/* -------------------------------------------------------------------------- */