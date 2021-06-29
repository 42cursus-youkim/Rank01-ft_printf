/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:10:29 by youkim            #+#    #+#             */
/*   Updated: 2021/06/29 15:49:13 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"


int		parse_format(va_list ap, char *format)
{
	int		i;
	int		result;
	t_info	*info;

	i = 0;
	result = 0;
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (-1);
	while (format[i])
	{
		if (format[i] != '%')
			result += ft_putchar(format[i++]);
		else
		{
			init_info(info);
			while (format[++i] && !(ft_strchr(TYPES, format[i])))
				check_info(ap, format, info, i);
			info->type = format[i++];
			result += print_type(ap, info);
		}
	}
	free(info);
	return (result);
}

int		ft_printf(const char *format, ...)
{
	int		result;
	va_list	ap;

	va_start(ap, format);
	result = parse_format(ap, (char *)format);
	va_end(ap);
	return (result);
}
