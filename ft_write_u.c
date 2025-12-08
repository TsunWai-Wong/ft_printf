/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tswong <tswong@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:11:16 by tswong            #+#    #+#             */
/*   Updated: 2025/12/08 16:33:14 by tswong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_write_u_recur(unsigned int value)
{
	char	c;

	if (value <= 9)
	{
		c = value + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_write_u_recur(value / 10);
		ft_write_u_recur(value % 10);
	}
}

int	ft_write_u(unsigned int value)
{
	unsigned int	count;

	ft_write_u_recur(value);
	count = 0;
	if (value == 0)
		count = 1;
	else
	{
		while (value > 0)
		{
			value /= 10;
			count++;
		}
	}
	return (count * sizeof(char));
}
