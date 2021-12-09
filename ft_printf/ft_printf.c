/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:18:44 by mnaimi            #+#    #+#             */
/*   Updated: 2021/12/10 00:12:31 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* -------------------------------------------------------------------------- */

int	ft_printf(const char *s_in, ...)
{
	t_fields	data;
	t_flags		flags;
	size_t		i;
	size_t		outpt_len;
	va_list		ap;

	va_start(ap, s_in);
	i = 0;
	outpt_len = 0;
	while (s_in[i])
	{
		if (s_in[i] == '%' && s_in[i + 1] == '%')
			ft_putchar(s_in[++i], &outpt_len);
		else if (s_in[i] == '%' && ft_will_be_valid((char *)&s_in[i + 1]))
		{
			get_data(&data, &flags, (char *)&s_in[++i], &i);
			process_data(&data, &ap, &outpt_len);
		}
		else if (s_in[i] == '%' && !ft_will_be_valid((char *)&s_in[i + 1]))
			return (-1);
		else
			ft_putchar(s_in[i], &outpt_len);
		i++;
	}
	return (outpt_len);
}

/* -------------------------------------------------------------------------- */
