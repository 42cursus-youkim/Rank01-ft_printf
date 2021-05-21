/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:49:38 by youkim            #+#    #+#             */
/*   Updated: 2021/05/10 15:54:45 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	st_writenbr(int n, int fd)
{
	if (n >= 10)
		st_writenbr(n / 10, fd);
	write(fd, &"0123456789"[n % 10], 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n >= 0)
		st_writenbr(n, fd);
	else if (n != -2147483648)
	{
		write(fd, "-", 1);
		st_writenbr(-n, fd);
	}
	else
		write(fd, "-2147483648", 11);
}
