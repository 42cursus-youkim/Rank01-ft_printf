/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:44:38 by youkim            #+#    #+#             */
/*   Updated: 2021/07/03 15:08:50 by youkim           ###   ########.fr       */
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
		result += ft_putchar(c) + pad(info, 1);
	else
		result += pad(info, 1) + ft_putchar(c);
	return (result);
}
