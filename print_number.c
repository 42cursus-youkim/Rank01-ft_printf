/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:01:29 by youkim            #+#    #+#             */
/*   Updated: 2021/07/08 10:19:58 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	pad_width(int len, t_info *info)
{
	int	result;

	result = 0;
	if(info->num_minus)
		len++;
	if (info->num_minus && info->zeropad && info->prec == NOPREC)
		result += (ft_putchar('-'));
	while (len++ < info->width)
		if (info->zeropad && !info->lalign)
			result += ft_putchar('0');
		else
			result += ft_putchar(' ');
	return (result);
}

static int	pad_prec(char *numstr, t_info *info)
{
	int result;
	int start;

	result = 0;
	start = ft_strlen(numstr);
	if (info->num_minus && !info->zeropad)
		result += (ft_putchar('-'));
	while (start++ < info->prec)
		result += ft_putchar('0');
	result += ft_putstr(numstr);
	return (result);
}

int	print_number(long long n, t_info *info)
{
	int		result;
	char	*numstr;

	result = 0;
	numstr = ft_itoa_base(n, get_baseset(info->type));
	if (info->prec < ft_strlen(numstr))
		info->prec = ft_strlen(numstr);
	if (n < 0 && ft_strchr("di", info->type))
		info->num_minus = true;
	pad_prec(numstr, info);
	// if (info->lalign)
	// 	result += pad_prec(numstr, info) \
	// 	+ pad_width(ft_strlen(numstr), info);
	// else
	// 	result += pad_width(ft_strlen(numstr), info) \
	// 	+ pad_prec(numstr, info);
	return (result);
}
/*
** //TODO: remove num_base from info struct; needless
** 	if (n < 0 && ft_strchr("di", info->type))
*/
