/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:44:38 by youkim            #+#    #+#             */
/*   Updated: 2021/07/03 12:54:43 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c, t_info *info)
{
	int	result;

	result = 0;
	if (info->type == '%' && info->lalign)
		info->zeropad = true;
	if (info->lalign)
		result += ft_putchar(c) + print_width(info);
	else
		result += print_width(info) + ft_putchar(c);
	return (result);
}

static int	print_width(t_info *info)
{
	int	result;

	result = 0;
	while (info->width)
	{
		if (info->zeropad)
			ft_putchar('0');
		else
			ft_putchar(' ');
		info->width--;
		result++;
	}
	return (result);
}
