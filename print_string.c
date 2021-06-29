/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:01:29 by youkim            #+#    #+#             */
/*   Updated: 2021/06/29 16:51:20 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *s, t_info *info)
{
	int result;
	// char *buffer;

	if (info->prec == UNDEFINED || info->prec > ft_strlen(s))
		info->prec = ft_strlen(s);

	// TODO: string parsing
	result += ft_putstr(s); // FIXME: width should be handled
	// free(buffer);
	return (result);
}