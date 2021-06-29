/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:12:45 by youkim            #+#    #+#             */
/*   Updated: 2021/06/29 13:11:39 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
// # include "./libft/libft.h"
# include <stdbool.h>

/*
** INFO STRUCT
*/
typedef struct	s_info
{
	char		type;
	int			width;
	int			prec;
	int			zeropad;
	int			is_zero;
	int			dosign;
	int			nbr_base;
	int			nbr_sign;
}				t_info;

/*
**
*/

#endif
