/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:36:07 by youkim            #+#    #+#             */
/*   Updated: 2021/07/09 16:42:54 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_info(t_info *info)
{
	info->type = 0;
	info->width = 0;
	info->prec = NOPREC;
	info->zeropad = false;
	info->lalign = false;
	info->num_minus = false;
}

static	void	check_star(va_list ap, t_info *info)
{
	if (info->prec == NOPREC)
	{
		info->width = va_arg(ap, int);
		if (info->width < 0)
		{
			info->lalign = true;
			info->width *= -1;
		}
	}
	else
		info->prec = va_arg(ap, int);
}

void	check_info(va_list ap, char *format, t_info *info, int i)
{
	if (format[i] == '0' && info->width == 0 \
		&& info->prec == NOPREC && !info->lalign)
		info->zeropad = true;
	else if (format[i] == '-')
		info->lalign = true;
	else if (format[i] == '.')
		info->prec = INITPREC;
	else if (format[i] == '*')
		check_star(ap, info);
	else if (ft_isdigit(format[i]))
	{
		if (info->prec == NOPREC)
			info->width = info->width * 10 + (format[i] - '0');
		else
			info->prec = info->prec * 10 + (format[i] - '0');
	}
}

int	print_type(va_list ap, t_info *info)
{
	int		result;
	char	type;

	result = 0;
	type = info->type;
	if (type == 'c')
		result = print_char(va_arg(ap, int), info);
	else if (type == 's')
		result = print_string(va_arg(ap, char *), info);
	else if (ft_strchr("di", type))
		result = print_number(va_arg(ap, int), info);
	else if (type == 'p')
		result = print_number(va_arg(ap, unsigned long long), info);
	else if (ft_strchr("uxX", type))
		result = print_number(va_arg(ap, unsigned int), info);
	else if (type == '%')
		result = print_char('%', info);
	return (result);
}

char	*get_baseset(char type)
{
	if (ft_strchr("udi", type))
		return ("0123456789");
	else if (ft_strchr("xp", type))
		return ("0123456789abcdef");
	else if (ft_strchr("X", type))
		return ("0123456789ABCDEF");
	return (NULL);
}
