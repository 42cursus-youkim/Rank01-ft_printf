/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:10:29 by youkim            #+#    #+#             */
/*   Updated: 2021/06/29 14:50:25 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		print_type(va_list ap, t_info *info)
{
	int		result;
	char	type;

	result = 0;
	type = info->type;
	if (type == 'c')
		result = print_char(va_arg(ap, int), info);
	else if (type == '%')
		result = print_char('%', info);
	return (result);
}

void	check_info(va_list ap, char *format, t_info *info, int i)
{

}

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
		while (format[i] && format[i] != '%')
			result += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			init_info(info);
			while (format[++i] && !(ft_strchr(TYPES, format[i])))
				printf("%d ", i);
				// check_info(ap, format, info, i);
			info->type = format[i++];
			result += print_type(ap, info);
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
