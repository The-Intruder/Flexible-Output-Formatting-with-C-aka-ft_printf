/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:18:44 by mnaimi            #+#    #+#             */
/*   Updated: 2021/12/04 23:04:12 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* -------------------------------------------------------------------------- */

int ft_printf(const char *str_in, ...)
{
	t_fields *data;
	size_t i;
	size_t outpt_len;

	i = 0;
	outpt_len = 0;
	while (str_in[i])
	{
		if (str_in[i] == '%' && str_in[i + 1] == '%')
		{
			ft_putchar(str_in[i]);
			i += 2;
			outpt_len++;
		}
		else if (str_in[i] == '%' && str_in[i + 1] != '%')
			data = get_data(str_in[i + 1], &outpt_len);
		else
		{
			ft_putchar(str_in[i++]);
			outpt_len++;
		}
	}
	return (outpt_len);
}

/* -------------------------------------------------------------------------- */