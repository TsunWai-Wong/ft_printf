/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tswong <tswong@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:47:46 by tswong            #+#    #+#             */
/*   Updated: 2025/12/08 16:33:56 by tswong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int	ft_router(va_list argv, char c)
{
	if (c == 'c')
		return (ft_write_c(va_arg(argv, int)));
	else if (c == 's')
		return (ft_write_s(va_arg(argv, char *)));
	else if (c == 'p')
		return (ft_write_p(va_arg(argv, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_write_i(va_arg(argv, int)));
	else if (c == 'u')
		return (ft_write_u(va_arg(argv, unsigned int)));
	else if (c == 'X' || c == 'x')
		return (ft_write_x(va_arg(argv, unsigned int), c));
	else if (c == '%')
		return (ft_write_percent());
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
		{
			ft_write_c(*str);
			count += 1;
		}
		else
		{
			str++;
			count += ft_router(args, *str);
		}
		str++;
	}
	va_end(args);
	return (count);
}
