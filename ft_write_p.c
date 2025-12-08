/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tswong <tswong@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:22:09 by tswong            #+#    #+#             */
/*   Updated: 2025/12/08 16:33:37 by tswong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	hex_to_char(unsigned int value)
{
	if (value >= 0 && value <= 9)
		return (value + '0');
	else
		return (value - 10 + 'a');
}

static void	ft_write_p_recur(unsigned long value)
{
	char	c;

	if (value <= 15)
	{
		c = hex_to_char(value);
		write(1, &c, 1);
	}
	else
	{
		ft_write_p_recur(value / 16);
		ft_write_p_recur(value % 16);
	}
}

int	ft_write_p(void *ptr)
{
	unsigned long	value;
	unsigned int	count;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count = 2;
	value = (unsigned long) ptr;
	ft_write_p_recur(value);
	while (value > 0)
	{
		value /= 16;
		count++;
	}
	return (count * sizeof(char));
}
