/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 11:17:02 by youkim            #+#    #+#             */
/*   Updated: 2021/05/10 11:16:35 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_isupper(int c)
{
	return ('A' <= c && c <= 'Z');
}

int			ft_tolower(int c)
{
	if (st_isupper(c))
		return ((c - 'A') + 'a');
	return (c);
}
