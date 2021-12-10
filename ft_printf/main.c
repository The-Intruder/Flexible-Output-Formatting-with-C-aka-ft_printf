/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 23:47:04 by mnaimi            #+#    #+#             */
/*   Updated: 2021/12/09 23:47:45 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	a;

	a = printf("%-d", INT_MIN);
	putchar('\n');
	printf("%d\n", a);
	a = ft_printf("%-d", INT_MIN);
	putchar('\n');
	printf("%d\n", a);
	return (0);
}
