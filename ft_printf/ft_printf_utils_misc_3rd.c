/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_misc_3rd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:39:42 by mnaimi            #+#    #+#             */
/*   Updated: 2021/12/09 21:39:55 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	get_nbr_size(long n, size_t *nbr_size)
{
	if (n < 0)
		get_nbr_size(n * -1, nbr_size);
	else if (n <= 9)
		(*nbr_size) += 1;
	else if (n > 9)
	{
		get_nbr_size(n / 10, nbr_size);
		get_nbr_size(n % 10, nbr_size);
	}
}

/* -------------------------------------------------------------------------- */