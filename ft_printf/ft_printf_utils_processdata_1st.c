/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_processdata.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:18:00 by mnaimi            #+#    #+#             */
/*   Updated: 2021/12/07 23:37:19 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* -------------------------------------------------------------------------- */

void	process_data(t_fields *data, va_list *ap, size_t *outpt_len)
{
	if (data -> type == 'c')
		process_char(data, va_arg(*ap, int), outpt_len);
	else if (data -> type == 's')
		process_str(data, va_arg(*ap, char *), outpt_len);
	else if (data -> type == 'p')
		process_vptr(data, va_arg(*ap, unsigned long), outpt_len);
	else if (data -> type == 'x' || data -> type == 'X')
		process_hex(data, va_arg(*ap, unsigned int), outpt_len);
	else if (data -> type == 'd' || data -> type == 'i')
		process_int(data, va_arg(*ap, signed int), outpt_len);
	else if (data -> type == 'u')
		process_uint(data, va_arg(*ap, unsigned int), outpt_len);
}

/* -------------------------------------------------------------------------- */

void	process_char(t_fields *data, char c, size_t *outpt_len)
{
	if (data -> width >= 1)
		data -> width -= 1;
	if (data -> flags -> minus)
	{
		ft_putchar(c, outpt_len);
		ft_putnchar(' ', data -> width, outpt_len);
	}
	else
	{
		ft_putnchar(' ', data -> width, outpt_len);
		ft_putchar(c, outpt_len);
	}
}

/* -------------------------------------------------------------------------- */

void	process_str(t_fields *data, char *str, size_t *outpt_len)
{
	size_t	str_len;

	str_len = ft_strlen(str);
	if (data -> is_precision && data -> precision < str_len)
		str_len = data -> precision;
	if (data -> width >= str_len)
		data -> width -= str_len;
	else
		data -> width = 0;
	if (data -> flags -> minus)
	{
		ft_putstr_len(str, str_len, outpt_len);
		ft_putnchar(' ', data -> width, outpt_len);
	}
	else
	{
		ft_putnchar(' ', data -> width, outpt_len);
		ft_putstr_len(str, str_len, outpt_len);
	}
}

/* -------------------------------------------------------------------------- */

void	process_vptr(t_fields *data, unsigned long vptr, size_t *outpt_len)
{
	size_t	adrs_size;

	adrs_size = 2;
	get_hex_adrs_size(vptr, &adrs_size);
	if (data -> width >= adrs_size)
		data -> width -= adrs_size;
	else
		data -> width = 0;
	if (data -> flags -> minus)
	{
		ft_putstr_len("0x", 2, outpt_len);
		ft_puthex_adrs(vptr, outpt_len);
		ft_putnchar(' ', data -> width, outpt_len);
	}
	else
	{
		ft_putnchar(' ', data -> width, outpt_len);
		ft_putstr_len("0x", 2, outpt_len);
		ft_puthex_adrs(vptr, outpt_len);
	}
}

/* -------------------------------------------------------------------------- */