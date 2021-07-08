/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:01:29 by youkim            #+#    #+#             */
/*   Updated: 2021/07/08 12:17:01 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static	char	*ft_strjoin_dir(const char *s1, const char *s2, bool no_rev)
{
	if (!no_rev)
		return (ft_strjoin(s1, s2));
	return (ft_strjoin(s2, s1));
}

static	char	*pad_width(char *s, t_info *info)
{
	while (info->num_minus + info->prec++ < info->width)
	{
		if (info->zeropad)
			s = ft_strjoin_dir("0", s, info->lalign);
		else
			s = ft_strjoin_dir(" ", s, info->lalign);
	}
	if (info->num_minus && info->zeropad)
		s = ft_strjoin("-", s);
	return (s);
}

static	char	*pad_prec(char *s, t_info *info)
{
	int		start;

	start = ft_strlen(s);
	info->prec = ft_max(info->prec, ft_strlen(s));
	while (start++ < info->prec)
		s = ft_strjoin("0", s);
	if (info->num_minus && !info->zeropad)
		s = ft_strjoin("-", s);
	return (s);
}

int	print_number(long long n, t_info *info)
{
	int		result;
	char	*s;

	result = 0;
	if (n < 0 && ft_strchr("di", info->type))
		info->num_minus = true;
	s = ft_itoa_base(n, get_baseset(info->type));
	s = pad_width(pad_prec(s, info), info);
	result += ft_putstr(s);
	return (result);
}
/*
** //TODO: remove num_base from info struct; needless
** 	if (n < 0 && ft_strchr("di", info->type))
*/
