/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:01:29 by youkim            #+#    #+#             */
/*   Updated: 2021/06/29 16:26:38 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		numlen(unsigned long long n, t_info *info)
{
	size_t i;
	// TODO: chek prec
	i = 0;
	while (n)
	{
		i++;
		n /= 10; // FIXME: it should implement info->num_base
	}

	return (i);
}

#include <stdio.h>

int putdigit(unsigned long long n, t_info *info)
{
	char *base;

	if (ft_strchr("px",info->type))
		base = "0123456789abcdef";
	else if (info->type == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789";
	ft_putchar(base[n % info->num_base]);
}

int	print_number(unsigned long long n, t_info *info)
{
	int		result;
	// char	*buffer;

	if (ft_strchr("pxX", info->type))
		info->num_base = 16;

	// TODO: string parsing
	result = numlen(n, info);
	// printf("<RES: %d>", result);
	while (n) // FIXME: it shows reverse
	{
		putdigit(n, info);
		n /= info->num_base;
	}
	// ft_putnbr_fd(n, 1); // TODO: need to handle number length
	// ft_putstr(buffer);
	return (result);
}