/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_literal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:01:29 by youkim            #+#    #+#             */
/*   Updated: 2021/07/03 17:19:24 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c, t_info *info)
{
	int		result;

	result = 0;
	if (info->type == '%' && info->lalign)
		info->zeropad = false;
	if (info->lalign)
		result += ft_putchar(c) + pad(1, info->width, info);
	else
		result += pad(1, info->width, info) + ft_putchar(c);
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
		result += write(1, s, info->prec) + pad(info->prec, info->width, info);
	else
		result += pad(info->prec, info->width, info) + write(1, s, info->prec);
	return (result);
}