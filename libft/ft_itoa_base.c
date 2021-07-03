/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 10:42:30 by youkim            #+#    #+#             */
/*   Updated: 2021/07/03 16:52:21 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	if (!n)
		len++;
	if (n < 0)
		n = -n;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(long long n, char *baseset)
{
	int		len;
	char	*str;
	int		baselen;

	baselen = ft_strlen(baseset);
	len = st_digitlen(n, baselen);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len] = 0;
	while (--len >= 0)
	{
		str[len] = baseset[st_abs(n % baselen)];
		n = st_abs(n / baselen);
	}
	return (str);
}
