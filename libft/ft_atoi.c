/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:40:14 by youkim            #+#    #+#             */
/*   Updated: 2021/07/03 11:50:12 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	if (!str[i])
		return (0);
	while (ft_strchr("\t\n\v\f\r ", str[i]))
		i++;
	if (ft_strchr("-+", str[i]))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (sign * num);
}
