/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_getdata.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:15:14 by mnaimi            #+#    #+#             */
/*   Updated: 2021/12/06 19:19:43 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* -------------------------------------------------------------------------- */

void set_placeholder_fields(t_fields *field_data, t_flags *f, \
	size_t *w, size_t p, char t)
{
	field_data -> flags = f;
	field_data -> width = *w;
	field_data -> precision = p;
	field_data -> type = t;
}

/* -------------------------------------------------------------------------- */

t_flags *get_flags(char **field_ptr)
{
	t_flags *flags;
	char flag;

	flags = (t_flags *)ft_calloc(1, sizeof(t_flags));
	if (!flags)
		return (NULL);
	while (is_flag(**field_ptr) && **field_ptr)
	{
		flag = is_flag(**field_ptr);
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
		*field_ptr++;
	}
	return (flags);
}

/* -------------------------------------------------------------------------- */

size_t get_width(char **field_ptr)
{
	size_t	the_width;

	the_width = 0;
	if (**field_ptr && is_true_digit(**field_ptr))
		the_width = (size_t)ft_atoi(**field_ptr);
	while (is_digit(**field_ptr))
		*field_ptr++;
	return (the_width);
}

/* -------------------------------------------------------------------------- */

size_t get_precision(char **field_ptr)
{
	size_t	the_precision;

	the_precision = 0;
	if (**field_ptr == '.' && is_true_digit(*(*field_ptr + 1)))
		the_precision = (size_t)ft_atoi(++*field_ptr);
	while (is_digit(**field_ptr))
		*field_ptr++;
	return (the_precision);
}

/* -------------------------------------------------------------------------- */

char    get_type(char **field_ptr)
{
	if (**field_ptr && is_type(**field_ptr))
		return (is_type(**field_ptr));
	return (0);
}

/* -------------------------------------------------------------------------- */

t_fields *get_data(char *field_ptr, size_t *printd_outpt_len)
{
	t_fields	*placeholder_data;

	placeholder_data = (t_fields *)ft_calloc(1, sizeof(t_fields));
	if (!placeholder_data)
		return (NULL);

	placeholder_fields(placeholder_data, get_flags(&field_ptr), \
		get_width(&field_ptr), get_precision(&field_ptr), get_type(&field_ptr));

	return (placeholder_data);
}
