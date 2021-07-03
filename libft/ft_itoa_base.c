/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 10:42:30 by youkim            #+#    #+#             */
/*   Updated: 2021/07/03 15:39:52 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_sign(long long n)
{
	if (n < 0)
		return (-1);
	return (1);
}

static int	st_abs(long long n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

static size_t	st_digitlen(long long n, int base)
{
	size_t	len;

	len = 0;
	if (!n || st_sign(n) == -1)
		len++;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(long long n, int base)
{
	int		len;
	int		sign;
	char	*str;

	sign = st_sign(n);
	len = st_digitlen(n, base);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len] = 0;
	while (--len >= 0)
	{
		str[len] = st_abs(n % base) + '0';
		n = st_abs(n / base);
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
