/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 11:17:02 by youkim            #+#    #+#             */
/*   Updated: 2021/07/03 11:45:44 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_islower(int c)
{
	return ('a' <= c && c <= 'z');
}

int	ft_toupper(int c)
{
	if (st_islower(c))
		return ((c - 'a') + 'A');
	return (c);
}
