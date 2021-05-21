/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_purge2str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 20:40:36 by youkim            #+#    #+#             */
/*   Updated: 2021/05/10 20:55:51 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_purge2str_bonus(char **str2d)
{
	size_t i;

	i = 0;
	while (str2d[i])
		free(str2d[i++]);
	free(str2d);
	return (0);
}
