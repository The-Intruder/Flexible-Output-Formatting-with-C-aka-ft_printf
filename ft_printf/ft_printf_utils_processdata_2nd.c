/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_processdata_2nd.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:11:48 by mnaimi            #+#    #+#             */
/*   Updated: 2021/12/09 23:31:39 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* -------------------------------------------------------------------------- */

void	check_zero(t_fields *data, char *char_to_fill)
{
	*char_to_fill = ' ';
	if (!(data->is_precision) && !(data->flags->minus) \
		&& data->flags->zero)
		*char_to_fill = '0';
}

/* -------------------------------------------------------------------------- */

void	check_precision_n_width(t_fields *data, size_t the_size, int prefix)
{
	if ((data->is_precision) && (data->precision) >= the_size)
		data->precision -= the_size;
	else
		data->precision = 0;
	if (prefix)
		the_size += 1;
	if (data->width >= (the_size + (data->precision)))
		data->width -= (the_size + (data->precision));
	else
		data->width = 0;
}

/* -------------------------------------------------------------------------- */

void	process_hex(t_fields *data, unsigned int n, size_t *outpt_len)
{
	size_t	hex_size;
	char	char_to_fill;
	int		the_case;

	hex_size = 0;
	get_hex_size(n, &hex_size);
	check_zero(data, &char_to_fill);
	the_case = 87;
	if (data->type == 'X')
		the_case = 55;
	check_precision_n_width(data, hex_size, 0);
	if (data->flags->minus)
	{
		ft_putnchar('0', data->precision, outpt_len);
		ft_puthexa_prefix(n, data->flags->hash, data->type, outpt_len);
		ft_puthex(n, outpt_len, the_case);
		ft_putnchar(char_to_fill, data->width, outpt_len);
	}
	else
	{
		ft_putnchar(char_to_fill, data->width, outpt_len);
		ft_putnchar('0', data->precision, outpt_len);
		ft_puthexa_prefix(n, data->flags->hash, data->type, outpt_len);
		ft_puthex(n, outpt_len, the_case);
	}
}

/* -------------------------------------------------------------------------- */

void	process_int(t_fields *data, int n, size_t *outpt_len)
{
	size_t	nbr_size;
	char	char_to_fill;

	nbr_size = 0;
	get_nbr_size(n, &nbr_size);
	check_zero(data, &char_to_fill);
	check_precision_n_width(data, nbr_size, ft_ispresign(data, n));
	if (data->flags->minus)
	{
		ft_putnbr_presign(n, data->flags, outpt_len);
		ft_putnchar('0', data->precision, outpt_len);
		ft_putnbr(n, outpt_len);
		ft_putnchar(char_to_fill, data->width, outpt_len);
		return ;
	}
	if (char_to_fill == ' ')
	{
		ft_putnchar(char_to_fill, data->width, outpt_len);
		data->width = 0;
	}
	ft_putnbr_presign(n, data->flags, outpt_len);
	ft_putnchar(char_to_fill, data->width, outpt_len);
	ft_putnchar('0', data->precision, outpt_len);
	ft_putnbr(n, outpt_len);
}

/* -------------------------------------------------------------------------- */

void	process_uint(t_fields *data, unsigned int n, size_t *outpt_len)
{
	size_t	nbr_size;
	char	char_to_fill;

	nbr_size = 0;
	get_unbr_size(n, &nbr_size);
	check_zero(data, &char_to_fill);
	check_precision_n_width(data, nbr_size, 0);
	if (data->flags->minus)
	{
		ft_putnchar('0', data->precision, outpt_len);
		ft_putunbr(n, outpt_len);
		ft_putnchar(char_to_fill, data->width, outpt_len);
	}
	else
	{
		if (char_to_fill == ' ')
		{
			ft_putnchar(char_to_fill, data->width, outpt_len);
			data->width = 0;
		}
		ft_putnchar(char_to_fill, data->width, outpt_len);
		ft_putnchar('0', data->precision, outpt_len);
		ft_putunbr(n, outpt_len);
	}
}

/* -------------------------------------------------------------------------- */
