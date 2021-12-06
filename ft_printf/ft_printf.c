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

int ft_printf(const char *str_in)
{
	t_fields *data;
	size_t i;
	size_t outpt_len;

	i = 0;
	outpt_len = 0;
	while (str_in[i])
	{
		if (str_in[i] == '%' && str_in[i + 1] == '%')
			ft_putchar(str_in[++i]);
		else if (str_in[i] == '%' && str_in[i + 1] != '%')
		{
			data = get_data(&str_in[i + 1], &outpt_len);
		}
		else
			ft_putchar(str_in[i]);
		i++;
		outpt_len++;
	}
	return (outpt_len);
}

/* -------------------------------------------------------------------------- */
// printf("%d\n", data -> flags -> minus);
// printf("%d\n", data -> flags -> plus);
// printf("%d\n", data -> flags -> space);
// printf("%d\n", data -> flags -> zero);
// printf("%d\n", data -> flags -> hash);