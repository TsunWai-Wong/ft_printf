/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tswong <tswong@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:11:16 by tswong            #+#    #+#             */
/*   Updated: 2025/12/08 16:32:34 by tswong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	hex_to_char(unsigned int value, char case_type)
{
	if (value >= 0 && value <= 9)
		return (value + '0');
	else if (case_type == 'X')
		return (value - 10 + 'A');
	else if (case_type == 'x')
		return (value - 10 + 'a');
	return (1);
}

static void	ft_write_x_recur(unsigned int value, char case_type)
{
	char	c;

	if (value <= 15)
	{
		c = hex_to_char(value, case_type);
		write(1, &c, 1);
	}
	else
	{
		ft_write_x_recur(value / 16, case_type);
		ft_write_x_recur(value % 16, case_type);
	}
}

int	ft_write_x(unsigned int value, char case_type)
{
	unsigned int	count;

	ft_write_x_recur(value, case_type);
	count = 0;
	if (value == 0)
		count = 1;
	else
	{
		while (value > 0)
		{
			value /= 16;
			count++;
		}
	}
	return (count * sizeof(char));
}
