/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:44:38 by youkim            #+#    #+#             */
/*   Updated: 2021/07/03 14:21:50 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	pad(t_info *info)
{
	int	result;

	result = 0;
	while (info->width--)
	{
		if (info->zeropad)
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
		result += ft_putchar(c) + pad(info);
	else
		result += pad(info) + ft_putchar(c);
	return (result);
}
