/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:12:45 by youkim            #+#    #+#             */
/*   Updated: 2021/06/29 16:44:36 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <stdbool.h>

# define TYPES "csdiupxX%"
# define UNDEFINED -1

/*
** INFO STRUCT
*/

/*
** STRUCT INFO
*/
typedef	struct	s_info
{
	char		type;
	int			width;
	int			prec;
	int			num_base;
	bool		zeropad;
	// int			is_zero;
	// int			dosign;
	// int			nbr_sign;
}				t_info;

/*
** PRINTF
*/
int				ft_printf(const char *format, ...);

/*
** PRINT TYPES
*/
int				print_char(int c, t_info *info);
int				print_string(char *s, t_info *info);
int				print_number(unsigned long long n, t_info *info);

/*
** UTILS
*/
void			init_info(t_info *info);
int				print_type(va_list ap, t_info *info);
void			check_info(va_list ap, char *format, t_info *info, int i);

#endif
