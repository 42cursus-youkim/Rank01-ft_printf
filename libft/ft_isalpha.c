/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:59:15 by youkim            #+#    #+#             */
/*   Updated: 2021/07/03 11:50:23 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_islower(int c)
{
	return ('a' <= c && c <= 'z');
}

static int	st_isupper(int c)
{
	return ('A' <= c && c <= 'Z');
}

int	ft_isalpha(int c)
{
	return (st_islower(c) || st_isupper(c));
}
