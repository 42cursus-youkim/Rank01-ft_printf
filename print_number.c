/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:01:29 by youkim            #+#    #+#             */
/*   Updated: 2021/07/09 15:03:01 by youkim           ###   ########.fr       */
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

static	int	pad(char *s, t_info *info)
{
	int		start;
	int		result;
	bool	is_noprec;

	result = 0;
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
		result += ft_putchar('-');
	result += ft_putstr(s);
	return (result);
}

int	print_number(long long n, t_info *info)
{
	int		result;
	char	*s;

	result = 0;
	if (n < 0 && ft_strchr("di", info->type))
		info->num_minus = true;
	if (n == 0 && !info->prec)
		s = ft_strdup("");
	else
		s = ft_itoa_base(n, get_baseset(info->type));
	if (info->type == 'p')
		s = ft_strjoin("0x", s);
	result += pad(s, info);
	return (result);
}
