/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:18:44 by mnaimi            #+#    #+#             */
/*   Updated: 2021/12/07 23:37:08 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

int ft_printf(const char *str_in, ...)
{
	t_fields	data;
	t_flags		flags;
	size_t		i;
	size_t		outpt_len;
	va_list		ap;

	va_start(ap, str_in);
	i = 0;
	outpt_len = 0;
	while (str_in[i])
	{
		if (str_in[i] == '%' && (str_in[i + 1] == '%' || !ft_isvalid(str_in[i + 1])))
			ft_putchar(str_in[++i], &outpt_len);
		else if (str_in[i] == '%' && ft_isvalid(str_in[i + 1]))
		{
			ft_bzero(&data, sizeof(t_fields));
			ft_bzero(&flags, sizeof(t_flags));
			get_data(&data, &flags, (char *)&str_in[++i], &i);
			process_data(&data, &ap, &outpt_len);
		}
		else
			ft_putchar(str_in[i], &outpt_len);
		i++;
	}

	return (outpt_len);
}

/* -------------------------------------------------------------------------- */
// printf("%d\n", data -> flags -> minus);
// printf("%d\n", data -> flags -> plus);
// printf("%d\n", data -> flags -> space);
// printf("%d\n", data -> flags -> zero);
// printf("%d\n", data -> flags -> hash);

/*
ft_putchar('\n');
printf("minus:\t%d\n", data.flags -> minus);
printf("plus:\t%d\n", data.flags -> plus);
printf("space:\t%d\n", data.flags -> space);
printf("zero:\t%d\n", data.flags -> zero);
printf("hash:\t%d\n", data.flags -> hash);
printf("type:\t%c\n", data.type);
printf("width:\t%zu\n", data.width);
printf("prcsn:\t%zu\n", data.precision);
*/