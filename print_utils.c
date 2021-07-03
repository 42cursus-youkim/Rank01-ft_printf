/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:08:22 by youkim            #+#    #+#             */
/*   Updated: 2021/07/03 17:18:51 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pad(int len, int max, t_info *info)
{
	int	result;

	result = 0;
	while (len++ < max)
	{
		if (info->zeropad)
			ft_putchar('0');
		else
			ft_putchar(' ');
		result++;
	}
	return (result);
}