/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 19:23:14 by youkim            #+#    #+#             */
/*   Updated: 2021/05/10 10:41:37 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;
	char	*str;

	str = 0;
	if (s1 && set)
	{
		first = 0;
		last = ft_strlen(s1);
		while (s1[first] && ft_strchr(set, s1[first]))
			first++;
		while (s1[last - 1] && ft_strchr(set, s1[last - 1]) && first < last)
			last--;
		str = malloc((last - first + 1) * sizeof(char));
		if (str)
			ft_strlcpy(str, &s1[first], last - first + 1);
	}
	return (str);
}
