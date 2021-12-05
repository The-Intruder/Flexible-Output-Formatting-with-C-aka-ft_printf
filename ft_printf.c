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

static t_flags	*get_flags(const char *field_ptr)
{
	t_flags	*flags;
	size_t	i;
	char	flag;

	flags = (t_flags *) ft_calloc(1, sizeof(t_flags));
	if (!flags)
		return (NULL);
	i = 0;
	while (is_flag(field_ptr[i]))
	{
		flag = is_flag(field_ptr[i]);
		if (flag == '-')
			flags -> minus = 1;
		else if (flag == '+')
			flags -> plus = 1;
		else if (flag == ' ')
			flags -> space = 1;
		else if (flag == '0')
			flags -> zero = 1;
		else if (flag == '#')
			flags -> hash = 1;
	}
	return (flags);
}

/* -------------------------------------------------------------------------- */

static void	set_field_vars(t_field *field_data, t_flags *f, int *w, int p, char t)
{
	field_data -> flags = f;
    field_data -> width = w;
    field_data -> precision = p;
    field_data -> type = t;
}

/* -------------------------------------------------------------------------- */

static t_field	get_data(const char *field_ptr, size_t *printd_outpt_len)
{
	t_field	*field_data;

	if (*field_ptr == '%')
		set_field_vars(field_data, NULL, 0, 0, '%');
	else
	{

	}
	return (field_data);
}

/* -------------------------------------------------------------------------- */

int	ft_printf(const char *str_in, ...)
{
	t_field	*data;
	size_t	i;
	size_t	outpt_len;

	i = 0;
	outpt_len = 0;
	while (str_in[i])
	{
		if (str_in[i] == '%')
		{
			data = get_data(str_in[i + 1], &outpt_len);
		}
		else
		{
			ft_putchar(str_in[i++]);
			outpt_len++;
		}
	}
	return (outpt_len);
}

/* -------------------------------------------------------------------------- */