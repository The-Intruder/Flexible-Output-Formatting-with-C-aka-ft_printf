
#include "ft_printf.h"

void	process_hex(t_fields *data, unsigned int n, size_t *outpt_len)
{
	size_t	hex_size;
	char	char_to_fill;
	int		the_case;

	hex_size = 0;
	get_hex_size(n, &hex_size);
	char_to_fill = ' ';
    /* Check '0' flag */
	if (!(data -> is_precision) && (data -> flags -> zero))
		char_to_fill = '0';
    /* Check if 'x' or 'X' */
	the_case = 87;
	if (data -> type == 'X')
		the_case = 55;
    /* Check Precision */
	if (data -> is_precision && data -> precision > hex_size)
		data -> precision -= hex_size;
	else
		data -> precision = 0;
    /* Check Width */
	if (data -> width >= hex_size + (data -> precision))
		data -> width -= hex_size + (data -> precision);
	else
		data -> width = 0;
    /* Check 'minus' flag */
	if (data -> flags -> minus)
	{
		ft_putnchar('0', data -> precision, outpt_len);
		ft_puthexa_prefix(n, data -> flags -> hash, data -> type, outpt_len);
		ft_puthex(n, outpt_len, the_case);
		ft_putnchar(char_to_fill, data -> width, outpt_len);
	}
	else
	{
		ft_putnchar(char_to_fill, data -> width, outpt_len);
		ft_putnchar('0', data -> precision, outpt_len);
		ft_puthexa_prefix(n, data -> flags -> hash, data -> type, outpt_len);
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
	char_to_fill = ' ';
    /* Check '0' flag */
	if (!(data -> is_precision) && !(data -> flags -> minus) && data -> flags -> zero)
		char_to_fill = '0';
    /* Check Precision */
	if ((data -> is_precision) && (data -> precision) >= nbr_size)
		data -> precision -= nbr_size;
	else
		data -> precision = 0;
    /* Include number sign in nbr_size */
	if (data -> flags -> plus || data -> flags -> space || n < 0)
		nbr_size += 1;
    /* Check Width */
	if (data -> width >= nbr_size + (data -> precision))
		data -> width -= nbr_size + (data -> precision);
	else
		data -> width = 0;
    /* Check 'minus' flag */
	if (data -> flags -> minus)
	{
		ft_putnbr_presign(n, data -> flags, outpt_len);
		ft_putnchar('0', data -> precision, outpt_len);
		ft_putnbr(n, outpt_len);
		ft_putnchar(char_to_fill, data -> width, outpt_len);
	}
	else
	{
        /* If '0' flag is false, print spaces, then the nbr sign */
		if (char_to_fill == ' ')
		{
			ft_putnchar(char_to_fill, data -> width, outpt_len);
			data -> width = 0;
		}
		ft_putnbr_presign(n, data -> flags, outpt_len);
		ft_putnchar(char_to_fill, data -> width, outpt_len);
		ft_putnchar('0', data -> precision, outpt_len);
		ft_putnbr(n, outpt_len);
	}
}

/* -------------------------------------------------------------------------- */

void	process_uint(t_fields *data, unsigned int n, size_t *outpt_len)
{
	size_t	nbr_size;
	char	char_to_fill;
	nbr_size = 0;
	get_unbr_size(n, &nbr_size);
	char_to_fill = ' ';
	if ((data -> is_precision) && (data -> precision) >= nbr_size)
		data -> precision -= nbr_size;
	else
		data -> precision = 0;
	if (!(data -> is_precision) && !(data -> flags -> minus) && data -> flags -> zero)
		char_to_fill = '0';
	if (data -> width >= nbr_size + data -> precision)
		data -> width -= nbr_size + data -> precision;
	else
		data -> width = 0;
	
	if (data -> flags -> minus)
	{
		ft_putnchar('0', data -> precision, outpt_len);
		ft_putunbr(n, outpt_len);
		ft_putnchar(char_to_fill, data -> width, outpt_len);
	}
	else
	{
		if (char_to_fill == ' ')
		{
			ft_putnchar(char_to_fill, data -> width, outpt_len);
			data -> width = 0;
		}
		ft_putnchar(char_to_fill, data -> width, outpt_len);
		ft_putnchar('0', data -> precision, outpt_len);
		ft_putunbr(n, outpt_len);
	}
}
