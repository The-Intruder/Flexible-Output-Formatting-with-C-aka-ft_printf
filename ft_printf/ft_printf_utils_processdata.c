/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_processdata.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:18:00 by mnaimi            #+#    #+#             */
/*   Updated: 2021/12/07 19:29:37 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* -------------------------------------------------------------------------- */

void	process_data(t_fields *data, va_list *ap, size_t *outpt_len)
{
	if (data -> type == 'c')
		*outpt_len += process_char(data, va_arg(*ap, int));
	else if (data -> type == 's')
		*outpt_len += process_str(data, va_arg(*ap, char *));
	/*else if (data -> type == 'p')
		*outpt_len += process_vptr(data, va_arg(*ap, unsigned long));
	else if (data -> type == 'd' || data -> type == 'i')
		*outpt_len += process_sint(data, va_arg(*ap, signed int));
	else if (data -> type == 'u')
		*outpt_len += process_uint(data, va_arg(*ap, unsigned int));
	else if (data -> type == 'x' || data -> type == 'X')
		*outpt_len += process_hex(data, va_arg(*ap, unsigned int));*/
}

/* -------------------------------------------------------------------------- */

size_t	process_char(t_fields *data, char c)
{
	data -> flags -> plus = 0;
	data -> flags -> zero = 0;
	data -> flags -> space = 0;
	data -> flags -> hash = 0;
	data -> precision = 0;
	if (data -> flags -> minus)
	{
		ft_putchar(c);
		if (data -> width)
			ft_putnchar(' ', (data -> width) - 1);
	}
	else
	{
		if (data -> width)
			ft_putnchar(' ', (data -> width) - 1);
		ft_putchar(c);
	}
	return (data -> width);

}

/* -------------------------------------------------------------------------- */

size_t	process_str(t_fields *data, char *str)
{
	
}

/* -------------------------------------------------------------------------- */
