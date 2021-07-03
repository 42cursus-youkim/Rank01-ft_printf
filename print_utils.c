/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:47:07 by youkim            #+#    #+#             */
/*   Updated: 2021/07/03 13:52:56 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pad(t_info *info, int len)
{
	int	result;

	result = 0;
	while (len--)
	{
		if (info->zeropad)
			ft_putchar('0');
		else
			ft_putchar(' ');
		result++;
	}
	return (result);
}

int	print_width(t_info *info, char *s)
{
	int	result;
	int	len;

	result = 0;
	len = ft_strlen(s);
	if (info->lalign)
		result += ft_putstr(s) + pad(info, len);
	else
		result += pad(info, len) + ft_putstr(s);
	return (result);
}
