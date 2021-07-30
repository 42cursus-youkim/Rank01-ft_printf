/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_literal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:01:29 by youkim            #+#    #+#             */
/*   Updated: 2021/07/30 14:28:36 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pad(int len, t_info *info)
{
	int	result;

	result = 0;
	while (len++ < info->width)
	{
		if (info->zeropad && !info->lalign)
			ft_putchar('0');
		else
			ft_putchar(' ');
		result++;
	}
	return (result);
}

int	print_char(int c, t_info *info)
{
	int		result;

	result = 0;
	if (info->type == '%' && info->lalign)
		info->zeropad = false;
	if (info->lalign)
		result += ft_putchar(c) + pad(1, info);
	else
		result += pad(1, info) + ft_putchar(c);
	return (result);
}

int	print_string(char *s, t_info *info)
{
	int	result;

	result = 0;
	if (!s)
		s = "(null)";
	if (info->prec == NOPREC || (size_t)info->prec > ft_strlen(s))
		info->prec = ft_strlen(s);
	if (info->lalign)
		result += write(1, s, info->prec) + pad(info->prec, info);
	else
		result += pad(info->prec, info) + write(1, s, info->prec);
	return (result);
}
