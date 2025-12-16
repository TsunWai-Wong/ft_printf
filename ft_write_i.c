/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tswong <tswong@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:11:16 by tswong            #+#    #+#             */
/*   Updated: 2025/12/08 16:33:46 by tswong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_write_i_recur(unsigned int value)
{
	char	c;

	if (value <= 9)
	{
		c = value + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_write_i_recur(value / 10);
		ft_write_i_recur(value % 10);
	}
}

int	ft_write_i(int value)
{
	int				count;
	unsigned int	num;

	count = 0;
	if (value < 0)
	{
		num = -1 * value;
		count += ft_write_c('-');
	}
	else
		num = value;
	ft_write_i_recur(num);
	if (num == 0)
		count = 1;
	else
	{
		while (num > 0)
		{
			num /= 10;
			count++;
		}
	}
	return (count);
}
