/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:36:07 by youkim            #+#    #+#             */
/*   Updated: 2021/06/29 15:49:35 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_info(t_info *info)
{
	info->type = 0;
}

void	check_info(va_list ap, char *format, t_info *info, int i)
{

}

int		print_type(va_list ap, t_info *info)
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