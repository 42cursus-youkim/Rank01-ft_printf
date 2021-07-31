/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:01:29 by youkim            #+#    #+#             */
/*   Updated: 2021/07/31 19:16:05 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static	int	pad_width(t_info *info, int temprec)
{
	int	i;
	int	result;

	i = info->prec;
	result = 0;

	while (info->num_minus + i++ < info->width)
	{
		if (info->zeropad && !info->lalign && temprec < 0)
			result += ft_putchar('0');
		else
			result += ft_putchar(' ');
	}
	return (result);
}

static	int	pad(char *s, t_info *info)
{
	int		start;
	int		result;
	int		temprec;
	result = 0;
	start = ft_strlen(s);
	temprec = info->prec;
	info->prec = ft_max(info->prec, ft_strlen(s));
	if (info->num_minus && (info->zeropad && temprec < 0))
		result += ft_putchar('-');
	if (!info->lalign)
		result += pad_width(info, temprec);
	if (info->num_minus && !(info->zeropad && temprec < 0))
		result += ft_putchar('-');
	while (start++ < info->prec)
		result += ft_putchar('0');
	result += ft_putstr(s);
	if (info->lalign)
		result += pad_width(info, temprec);
	return (result);
}

int	print_number(long long n, t_info *info)
{
	int		result;
	char	*s;
	char	*nums;

	result = 0;
	if (n < 0 && ft_strchr("di", info->type))
		info->num_minus = true;
	if (n == 0 && !info->prec)
		nums = ft_strdup("");
	else
		nums = ft_itoa_base(n, get_baseset(info->type));
	if (info->type == 'p')
		s = ft_strjoin("0x", nums);
	else
		s = ft_strdup(nums);
	result += pad(s, info);
	if (s)
		free(s);
	if (nums)
		free(nums);
	return (result);
}
