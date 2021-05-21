/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:13:19 by youkim            #+#    #+#             */
/*   Updated: 2021/05/09 13:37:40 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	n1;
	unsigned char	n2;

	i = 0;
	while (n-- > 0)
	{
		n1 = (unsigned char)s1[i];
		n2 = (unsigned char)s2[i];
		if (n1 != n2)
			return (n1 - n2);
		if (!n1 || !n2)
			return (0);
		i++;
	}
	return (0);
}
