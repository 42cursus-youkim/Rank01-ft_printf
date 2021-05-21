/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 16:45:32 by youkim            #+#    #+#             */
/*   Updated: 2021/05/08 21:24:50 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*dstptr;
	const unsigned char	*srcptr;

	i = 0;
	srcptr = (unsigned char *)src;
	dstptr = (unsigned char *)dst;
	while (i < n)
	{
		dstptr[i] = srcptr[i];
		if (srcptr[i] == (unsigned char)c)
			return ((void *)&dstptr[i + 1]);
		i++;
	}
	return (0);
}
