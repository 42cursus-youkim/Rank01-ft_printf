/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:01:29 by youkim            #+#    #+#             */
/*   Updated: 2021/07/03 15:36:19 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_number(long long n, t_info *info)
{
	int		result;
	char	*numstr;

	if (ft_strchr("pxX", info->type))
		info->num_base = 16;
	numstr = ft_itoa_base(n, info->num_base);
	result += print_string(numstr, info);
	return (result);
}
/*
** 	if (n < 0 && ft_strchr("di", info->type))
*/
