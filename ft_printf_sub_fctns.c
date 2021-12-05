

#include "ft_printf.h"

/* -------------------------------------------------------------------------- */

void set_placeholder_fields(t_fields *field_data, t_flags *f, \
	size_t *w, size_t p, char t)
{
	field_data->flags = f;
	field_data->width = w;
	field_data->precision = p;
	field_data->type = t;
}

/* -------------------------------------------------------------------------- */

t_flags *get_flags(const char *field_ptr)
{
	t_flags *flags;
	size_t i;
	char flag;

	flags = (t_flags *)ft_calloc(1, sizeof(t_flags));
	if (!flags)
		return (NULL);
	i = 0;
	while (is_flag(field_ptr[i]) && field_ptr[i])
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
		i++;
	}
	return (flags);
}

/* -------------------------------------------------------------------------- */

size_t get_width(const char *field_ptr)
{
	size_t	i;
	size_t	the_width;

	i = 0;
	the_width = 0;
	while (is_flag(field_ptr[i]) && field_ptr[i])
		i++;
	if (is_width(field_ptr[i]) && field_ptr[i])
		the_width = (size_t)ft_atoi(field_ptr[i]);
	return (the_width);
}

/* -------------------------------------------------------------------------- */

size_t get_precision(const char *field_ptr)
{
	size_t	i;
	size_t	the_precision;

	i = 0;
	the_precision = 0;
	while (field_ptr[i] && is_flag(field_ptr[i]))
		i++;
    while (field_ptr[i] && is_width(field_ptr[i]))
		i++;
	if (is_precision(&field_ptr[i]) && field_ptr[i])
		the_precision = (size_t)ft_atoi(field_ptr[i + 1]);
	return (the_precision);
}

/* -------------------------------------------------------------------------- */

char    get_type(const char *field_ptr)
{
    size_t	i;
	char	the_type;

	i = 0;
	the_type = 0;
	while (field_ptr[i] && is_flag(field_ptr[i]))
		i++;
    while (field_ptr[i] && is_width(field_ptr[i]))
		i++;
	if (field_ptr[i] == '.')
        i++;
    /* Although the condition below says is_width(), i'm actually just using it
     to check if there is a number there (1 - 9)*/
    while (field_ptr[i] && is_width(field_ptr[i])) 
		the_type = (size_t)ft_atoi(field_ptr[i + 1]);
	return (the_type);
}

/* -------------------------------------------------------------------------- */

t_fields *get_data(const char *field_ptr, size_t *printd_outpt_len)
{
	t_fields *placeholder_data;

	placeholder_data = (t_fields *)ft_calloc(1, sizeof(t_fields));
	if (!placeholder_data)
		return (NULL);
	placeholder_fields(placeholder_data, get_flags(field_ptr), \
		get_width(field_ptr), get_precision(field_ptr), '%');

	return (placeholder_data);
}