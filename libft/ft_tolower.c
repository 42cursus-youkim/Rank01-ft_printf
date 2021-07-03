/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 11:17:02 by youkim            #+#    #+#             */
/*   Updated: 2021/07/03 11:45:52 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_isupper(int c)
{
	return ('A' <= c && c <= 'Z');
}

int	ft_tolower(int c)
{
	if (st_isupper(c))
		return ((c - 'A') + 'a');
	return (c);
}
