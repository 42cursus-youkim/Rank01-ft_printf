/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:01:29 by youkim            #+#    #+#             */
/*   Updated: 2021/07/03 14:59:00 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	pad(t_info *info, int len)
{
	int	result;

	result = 0;
	while (len++ < info->width)
	{
		if (info->zeropad)
			ft_putchar('0');
		else
			ft_putchar(' ');
		result++;
	}
	return (result);
}

int	print_string(char *s, t_info *info)
{
	int	result;

	if (!s)
		s = "(null)";
	if (info->prec == NOPREC || info->prec > ft_strlen(s))
		info->prec = ft_strlen(s);
	if (info->lalign)
		result += write(1, s, info->prec) + pad(info, info->prec);
	else
		result += pad(info, info->prec) + write(1, s, info->prec);
	return (result);
}