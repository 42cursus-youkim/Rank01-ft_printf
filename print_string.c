/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:01:29 by youkim            #+#    #+#             */
/*   Updated: 2021/07/03 15:08:46 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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