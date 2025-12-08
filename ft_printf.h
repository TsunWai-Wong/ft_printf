/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tswong <tswong@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:09:01 by tswong            #+#    #+#             */
/*   Updated: 2025/12/08 16:12:33 by tswong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_write_c(char c);
int	ft_write_i(int value);
int	ft_write_p(void *ptr);
int	ft_write_percent(void);
int	ft_write_s(char *s);
int	ft_write_u(unsigned int value);
int	ft_write_x(unsigned int value, char case_type);

#endif