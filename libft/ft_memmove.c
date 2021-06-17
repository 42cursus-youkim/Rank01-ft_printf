/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 18:18:00 by youkim            #+#    #+#             */
/*   Updated: 2021/05/08 19:24:20 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dstptr;
	const unsigned char	*srcptr;

	if (dst == src || !len)
		return (dst);
	i = 0;
	dstptr = (unsigned char *)dst;
	srcptr = (unsigned char *)src;
	if (dst <= src)
		while (++i <= len)
			dstptr[i - 1] = srcptr[i - 1];
	else if (dst > src)
		while (++i <= len)
			dstptr[len - i] = srcptr[len - i];
	return (dst);
}
