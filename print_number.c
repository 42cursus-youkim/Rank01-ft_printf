/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:01:29 by youkim            #+#    #+#             */
/*   Updated: 2021/07/08 15:58:48 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// (info->zeropad)
// First line of code: {return test("%08.5i", 34);}
// 	expected output : "   00034"
// 	your output     : "00000034"

// (info->zeropad && (!info->prec && info->width))
// First line of code: {return test("%05i", 43);}
// expected output : "00043"
// your output     : "   43"

// printf("[%010.5i]\n", -216); -> [    -00216]
static	char	*ft_strjoin_dir(const char *s1, const char *s2, bool no_rev)
{
	if (!no_rev)
		return (ft_strjoin(s1, s2));
	return (ft_strjoin(s2, s1));
}

static	char	*pad(char *s, t_info *info)
{
	int		start;
	bool	is_noprec;

	start = ft_strlen(s);
	is_noprec = (info->prec == NOPREC);
	info->prec = ft_max(info->prec, ft_strlen(s));
	while (start++ < info->prec)
		s = ft_strjoin("0", s);
	if (info->num_minus && !(info->zeropad && is_noprec))
		s = ft_strjoin("-", s);
	while (info->num_minus + info->prec++ < info->width)
	{
		if (info->zeropad && is_noprec)
			s = ft_strjoin_dir("0", s, info->lalign);
		else
			s = ft_strjoin_dir(" ", s, info->lalign);
	}
	if (info->num_minus && (info->zeropad && is_noprec))
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
	s = pad(s, info);
	// s = pad_width(pad_prec(s, info), info);
	result += ft_putstr(s);
	return (result);
}
/*
** //TODO: remove num_base from info struct; needless
** 	if (n < 0 && ft_strchr("di", info->type))
*/
