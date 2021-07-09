/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:01:29 by youkim            #+#    #+#             */
/*   Updated: 2021/07/09 15:19:16 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static	int	pad_width(t_info *info, bool is_noprec)
{
	int i;
	int result;

	i = info->prec;
	result = 0;
	while (info->num_minus + i++ < info->width)
	{
		if (info->zeropad && is_noprec)
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
	bool	is_noprec;

	result = 0;
	start = ft_strlen(s);
	is_noprec = (info->prec == NOPREC);
	info->prec = ft_max(info->prec, ft_strlen(s));
	if (info->num_minus && (info->zeropad && is_noprec))
		result += ft_putchar('-');
	if (!info->lalign)
		result += pad_width(info, is_noprec);
	if (info->num_minus && !(info->zeropad && is_noprec))
		result += ft_putchar('-');
	while (start++ < info->prec)
		result += ft_putchar('0');
	result += ft_putstr(s);
	if (info->lalign)
		result += pad_width(info, is_noprec);
	return (result);
}

int	print_number(long long n, t_info *info)
{
	int		result;
	char	*s;

	result = 0;
	if (n < 0 && ft_strchr("di", info->type))
		info->num_minus = true;
	if (n == 0 && !info->prec)
		s = ft_strdup("");
	else
		s = ft_itoa_base(n, get_baseset(info->type));
	if (info->type == 'p')
		s = ft_strjoin("0x", s);
	result += pad(s, info);
	return (result);
}
