/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:12:45 by youkim            #+#    #+#             */
/*   Updated: 2021/07/08 10:19:09 by youkim           ###   ########.fr       */
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
# define NOPREC -1
# define INITPREC 0

/*
** INFO STRUCT
*/

/*
** STRUCT INFO
*/
typedef struct s_info
{
	char	type;
	int		width;
	int		prec;
	bool	lalign;
	bool	zeropad;
	bool	num_minus;
}			t_info;
/*
** 	int			is_zero;
** 	int			dosign;
** 	int			nbr_sign;
*/

/*
** PRINTF
*/
int		ft_printf(const char *format, ...);

/*
** PRINT TYPES
*/
int		print_char(int c, t_info *info);
int		print_string(char *s, t_info *info);
int		print_number(long long n, t_info *info);

/*
** UTILS
*/
void	init_info(t_info *info);
int		print_type(va_list ap, t_info *info);
void	check_info(va_list ap, char *format, t_info *info, int i);
char	*get_baseset(char type);

#endif
