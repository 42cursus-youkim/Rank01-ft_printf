/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 10:42:30 by youkim            #+#    #+#             */
/*   Updated: 2021/05/10 11:39:10 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		st_sign(long n)
{
	if (n < 0)
		return (-1);
	return (1);
}

static int		st_abs(long n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

static size_t	st_digitlen(long n)
{
	size_t	len;

	len = 0;
	if (!n || st_sign(n) == -1)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*str;

	sign = st_sign(n);
	len = st_digitlen(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len] = 0;
	while (--len >= 0)
	{
		str[len] = st_abs(n % 10) + '0';
		n = st_abs(n / 10);
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
