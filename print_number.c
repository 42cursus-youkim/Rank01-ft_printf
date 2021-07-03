/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:01:29 by youkim            #+#    #+#             */
/*   Updated: 2021/07/03 16:56:22 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_baseset(char type)
{
	if (ft_strchr("udi", type))
		return ("0123456789");
	else if (ft_strchr("xp", type))
		return ("0123456789abcdef");
	else if (ft_strchr("X", type))
		return ("0123456789ABCDEF");
}

int	print_number(long long n, t_info *info)
{
	int		result;
	char	*numstr;
	char	*baseset;

	if (n < 0 && ft_strchr("di", info->type))
		info->num_minus = true;
	baseset = get_baseset(info->type);
	numstr = ft_itoa_base(n, baseset);
	if (info->num_minus)
		result += ft_putchar('-');
	result += print_string(numstr, info);
	return (result);
}
/*
** //TODO: remove num_base from info struct; needless
** 	if (n < 0 && ft_strchr("di", info->type))
*/
