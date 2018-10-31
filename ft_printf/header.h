/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 18:30:21 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/30 22:19:11 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include "libft/libft.h"

typedef struct	s_arg
{
	int		hashtag;
	int		right_pending;
	int		star_precision;
	int		star_width;
	int		minus;
	int		plus;
	int		zero_pending;
	int		space;
	int		width;
	int		precision;
	int		nonascii;
	char	*format;
	char	type;
}				t_arg;

char	*g_word;

int		ft_printf(const char *restrict format, ...);
char	*ft_itoa_base_unsigned(uintmax_t value, int base);
char	*ft_itoa_intmax(long long value);
char	*ft_itoa_unsigned(uintmax_t value);

#endif
