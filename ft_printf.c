/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:10:29 by youkim            #+#    #+#             */
/*   Updated: 2021/06/17 17:05:58 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	parse_format(va_list ap, char *format)
{
	int		i;
	int		result;
	t_info	*info;

	i = 0;
	result = 0;
	if (!(info = malloc(sizeof(t_info))))
		return (-1);
	while (format[i])
	{
		while (format[i] && format[i] != '%')
			result += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			//init_info(info);
			printf("%% found");
		}
	}
	free(info);
	ap += 1;

	return (result);
}

int	ft_printf(const char *format,...)
{
	int		result;
	va_list	ap;

	va_start(ap, format);
	result = parse_format(ap, (char *)format);
	va_end(ap);
	return (result);
}
