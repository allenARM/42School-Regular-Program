/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:29:31 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/31 13:59:42 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	makezero(t_arg *data)
{
	data->hashtag = 0;
	data->right_pending = 0;
	data->star_precision = 0;
	data->star_width = 0;
	data->minus = 0;
	data->plus = 0;
	data->zero_pending = 0;
	data->space = 0;
	data->width = 0;
	data->precision = 0;
	data->format = ft_strnew(1);
	data->type = 0;
}

char	*conversion_s_S(va_list arg, t_arg *data)
{
	char	*str;
	char	*tmp;
	t_arg	*tmp_for_data;

	tmp_for_data = data;
	tmp = va_arg(arg, char *);
	if (tmp == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(tmp);
	return (str);
}

char	*conversion_c_C(va_list arg, t_arg *data)
{
	wchar_t w_tmp;
	char	*letter;
	int		tmp;

	if (!ft_strcmp(data->format, "l"))
		data->type = 'C';
	if (data->type == 'C')
	{
		w_tmp = va_arg(arg, wint_t);
		tmp = (char)w_tmp;
	}
	else
		tmp = va_arg(arg, int);
	letter = ft_bchar(1, (char)tmp);
	return (letter);
}

char	*conversion_d_i(va_list arg, t_arg *data)
{
	char		*answer;
	intmax_t	tmp;

	answer = ft_strnew(1);
	tmp = va_arg(arg, intmax_t);
	if (!ft_strcmp(data->format, "ll"))
		tmp = (long long)tmp;
	else if (!ft_strcmp(data->format, "l"))
		tmp = (long int)tmp;
	else if (!ft_strcmp(data->format, "hh"))
		tmp = (char)tmp;
	else if (!ft_strcmp(data->format, "h"))
		tmp = (short int)tmp;
	else if (!ft_strcmp(data->format, "j"))
		tmp = (intmax_t)tmp;
	else if (!ft_strcmp(data->format, "z"))
		tmp = (size_t)tmp;
	else
		tmp = (int)tmp;
	answer = ft_update(answer, ft_itoa_intmax(tmp));
	if (answer[0] == '-')
	{
		data->minus = 1;
		answer = ft_update(answer, ft_strsub(answer, 1, ft_strlen(answer) - 1));
	}
	return (answer);
}

char	*conversion_p(va_list arg)
{
	char		*answer;
	intmax_t	tmp;

	answer = ft_strnew(1);
	tmp = va_arg(arg, unsigned long);
	answer = ft_update(answer, ft_itoa_base(tmp, 16));
	answer = ft_update(answer, ft_strjoin("0x", answer));
	return (answer);
}

char	*conversion_u_D_U(va_list arg, t_arg *data)
{
	char		*answer;
	intmax_t	tmp;

	answer = ft_strnew(1);
	tmp = va_arg(arg, uintmax_t);
	if (!ft_strcmp(data->format, "ll"))
		tmp = (unsigned long long)tmp;
	else if (!ft_strcmp(data->format, "l"))
		tmp = (unsigned long)tmp;
	else if (!ft_strcmp(data->format, "hh"))
		tmp = (unsigned char)tmp;
	else if (!ft_strcmp(data->format, "h"))
		tmp = (unsigned short)tmp;
	else if (!ft_strcmp(data->format, "j"))
		tmp = (uintmax_t)tmp;
	else if (!ft_strcmp(data->format, "z"))
		tmp = (size_t)tmp;
	else
		tmp = (unsigned int)tmp;
	answer = ft_update(answer, ft_itoa_unsigned(tmp));
	return (answer);
}

char	*conversion_o_O(va_list arg, t_arg *data)
{
	char		*answer;
	intmax_t	tmp;

	answer = ft_strnew(1);
	tmp = va_arg(arg, uintmax_t);
	if (!ft_strcmp(data->format, "ll"))
		tmp = (unsigned long long int)tmp;
	else if (!ft_strcmp(data->format, "l"))
		tmp = (unsigned long int)tmp;
	else if (!ft_strcmp(data->format, "hh"))
		tmp = (unsigned char)tmp;
	else if (!ft_strcmp(data->format, "h"))
		tmp = (unsigned short int)tmp;
	else if (!ft_strcmp(data->format, "j"))
		tmp = (uintmax_t)tmp;
	else if (!ft_strcmp(data->format, "z"))
		tmp = (size_t)tmp;
	else
		tmp = (unsigned int)tmp;
	answer = ft_update(answer, ft_itoa_base_unsigned(tmp, 8));
	if (data->hashtag == 1 && tmp != 0)
		answer = ft_update(answer, ft_strjoin("0", answer));
	return (answer);
}

char	*conversion_x_X(va_list arg, t_arg *data)
{
	char		*answer;
	intmax_t	tmp;

	answer = ft_strnew(1);
	tmp = va_arg(arg, uintmax_t);
	if (!ft_strcmp(data->format, "ll"))
		tmp = (unsigned long long int)tmp;
	else if (!ft_strcmp(data->format, "l"))
		tmp = (unsigned long int)tmp;
	else if (!ft_strcmp(data->format, "hh"))
		tmp = (unsigned char)tmp;
	else if (!ft_strcmp(data->format, "h"))
		tmp = (unsigned short int)tmp;
	else if (!ft_strcmp(data->format, "j"))
		tmp = (uintmax_t)tmp;
	else if (!ft_strcmp(data->format, "z"))
		tmp = (size_t)tmp;
	else
		tmp = (unsigned int)tmp;
	answer = ft_update(answer, ft_itoa_base_unsigned(tmp, 16));
	if (data->hashtag == 1 && tmp != 0 && data->zero_pending == 0)
		answer = ft_update(answer, ft_strjoin("0x", answer));
	if (data->type == 'X')
		answer = ft_update(answer, ft_strtoupper(answer));
	return (answer);
}

char	*adding_precision_string(t_arg *data, char *str)
{
	char	*tmp;

	if (data->type != 'S' && data->type != 's')
	{
		tmp = ft_strdup(str);
		return (tmp);
	}
	if (data->precision == 0)
	{
		tmp = ft_strnew(1);
		return (tmp);
	}
	if (data->precision >= (int)ft_strlen(str))
	{
		tmp = ft_strdup(str);
		return (tmp);
	}
	str = ft_strsub(str, 0, data->precision);
	return (str);
}

char	*adding_precision_number(t_arg *data, char *str)
{
	char	*tmp;
	int		i;

	if (data->type != 'd' && data->type != 'i' && \
			data->type != 'U' && data->type != 'u' && \
			data->type != 'D' && data->type != 'X' && \
			data->type != 'o' && data->type != 'x' && \
			data->type != 'O')
	{
		tmp = ft_strdup(str);
		return (tmp);
	}
	if (!((data->type == 'o' || data->type == 'O') && data->hashtag == 1))
		if (data->precision == 0 && !ft_strcmp(str, "0"))
		{
			tmp = ft_strnew(1);
			return (tmp);
		}
	if (data->precision <= (int)ft_strlen(str))
	{
		tmp = ft_strdup(str);
		return (tmp);
	}
	tmp = (char *)malloc(sizeof(char) * data->precision + 1);
	i = 0;
	while (i < (data->precision - (int)ft_strlen(str)))
		tmp[i++] = '0';
	while (*str)
	{
		tmp[i++] = *str;
		str++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*adding_minus(t_arg *data, char *str)
{
	char	*tmp;

	if (data->type != 'd' && data->type != 'i' && \
			data->type != 'D')
	{
		tmp = ft_strdup(str);
		return (tmp);
	}
	tmp = ft_strnew(1);
	tmp = ft_update(tmp, ft_strjoin("-", str));
	return (tmp);
}

char	*adding_plus(t_arg *data, char *str)
{
	char	*tmp;

	if (data->type != 'd' && data->type != 'i' && \
			data->type != 'D')
	{
		tmp = ft_strdup(str);
		return (tmp);
	}
	tmp = ft_strnew(1);
	if (data->minus == 0)
		tmp = ft_update(tmp, ft_strjoin("+", str));
	return (tmp);
}

char	*adding_space(t_arg *data, char *str)
{
	char	*tmp;

	if (data->type != 'd' && data->type != 'i' && \
			data->type != 'D')
	{
		tmp = ft_strdup(str);
		return (tmp);
	}
	tmp = ft_strnew(1);
	if (data->minus == 0)
		tmp = ft_update(tmp, ft_strjoin(" ", str));
	return (tmp);
}

char	*adding_width(t_arg *data, char *str)
{
	char	fill;
	char	*extra;

	if (data->width <= (int)ft_strlen(str))
		return (str);
	fill = ' ';
	if (data->zero_pending == 1 && data->precision == 0 && data->type != 's' &&
	data->type != 'c' && data->type != 'C' && data->type != 'S'
	&& data->type != 'p')
		fill = '0';
	if ((data->type != 'x' || data->type != 'X') &&
	data->zero_pending == 1 && data->hashtag == 1)
	{
		extra = ft_bchar(data->width - (int)ft_strlen(str) - 2, fill);
		extra = ft_update(extra, ft_strjoin("0x", extra));
	}
	else
		extra = ft_bchar(data->width - (int)ft_strlen(str), fill);
	if (data->zero_pending == 1 && (str[0] == '+' || str[0] == '-'))
		str = ft_update(str, ft_strsub(str, 1, ft_strlen(str) - 1));
	if (data->right_pending == 1)
		str = ft_update(str, ft_strjoin(str, extra));
	if (data->right_pending == 0)
		str = ft_update(str, ft_strjoin(extra, str));
	if (data->zero_pending == 1 && data->minus == 1)
		str = ft_update(str, ft_strjoin("-", str));
	else if (data->zero_pending == 1 && data->plus == 1)
		str = ft_update(str, ft_strjoin("+", str));
	free(extra);
	return (str);
}

char	*type_define(va_list arg, t_arg *data)
{
	char	*tmp;

	tmp = ft_strnew(1);
	if (data->type == 's' || data->type == 'S')
		tmp = ft_update(tmp, conversion_s_S(arg, data));
	else if (data->type == 'c' || data->type == 'C')
		tmp = ft_update(tmp, conversion_c_C(arg, data));
	else if (data->type == 'i' || data->type == 'd')
		tmp = ft_update(tmp, conversion_d_i(arg, data));
	else if (data->type == 'p')
		tmp = ft_update(tmp, conversion_p(arg));
	else if (data->type == 'D' || data->type == 'u' || data->type == 'U')
		tmp = ft_update(tmp, conversion_u_D_U(arg, data));
	else if (data->type == 'o' || data->type == 'O')
		tmp = ft_update(tmp, conversion_o_O(arg, data));
	else if (data->type == 'x' || data->type == 'X')
		tmp = ft_update(tmp, conversion_x_X(arg, data));
	else if (data->type == '%')
		tmp = ft_update(tmp, ft_bchar(1, '%'));
	if (data->star_precision != 0)
	{
		tmp = ft_update(tmp, adding_precision_string(data, tmp));
		tmp = ft_update(tmp, adding_precision_number(data, tmp));
	}
	if (data->minus == 1)
		tmp = ft_update(tmp, adding_minus(data, tmp));
	else if (data->plus == 1)
		tmp = ft_update(tmp, adding_plus(data, tmp));
	else if (data->space == 1)
		tmp = ft_update(tmp, adding_space(data, tmp));
	if (data->width != 0)
		tmp = adding_width(data, tmp);
	return (tmp);
}

void	parse_data_child(const char *s, int *i, t_arg *data)
{
	while (s[*i] == '#' && s[*i + 1] != '\0')
	{
		data->hashtag = 1;
		(*i)++;
	}
	while (s[*i] == '-' && s[*i + 1] != '\0')
	{
		data->right_pending = 1;
		(*i)++;
	}
	while (s[*i] == '+' && s[*i + 1] != '\0')
	{
		data->plus = 1;
		(*i)++;
	}
	while (s[*i] == '0' && s[*i + 1] != '\0')
	{
		data->zero_pending = 1;
		(*i)++;
	}
	while (s[*i] == ' ' && s[*i + 1] != '\0')
	{
		data->space = 1;
		(*i)++;
	}
}

void	parse_data(const char *s, int *i, t_arg *data)
{
	int j;

	j = 0;
	while (j < 5)
	{
		parse_data_child(s, &*i, data);
		j++;
	}
}

void	parse_width(va_list arg, const char *s, int *i, t_arg *data)
{
	int	tmp;
	int skip;

	if (s[*i] == '*')
	{
		tmp = va_arg(arg, int);
		data->star_width = 1;
		data->width = tmp;
		(*i)++;
	}
	else if (s[(*i)] == '0')
		(*i)++;
	else
	{
		tmp = ft_atoi(&s[*i]);
		skip = ft_sizeofint(tmp, 10);
		data->star_width = -1;
		data->width = tmp;
		*i += skip;
	}
}

void	parse_accuracy(va_list arg, const char *s, int *i, t_arg *data)
{
	int tmp;
	int skip;

	if (s[*i] == '.' && s[*i + 1] != '\0')
	{
		(*i)++;
		if (s[*i] == '*')
		{
			tmp = va_arg(arg, int);
			data->star_precision = 1;
			data->precision = tmp;
			(*i)++;
		}
		else if (s[(*i)] == '0')
		{
			(*i)++;
			data->star_precision = -1;
		}
		else
		{
			tmp = ft_atoi(&s[*i]);
			skip = ft_sizeofint(tmp, 10);
			data->star_precision = -1;
			data->precision = tmp;
			*i += skip;
		}
	}
}

void	parse_format(const char *s, int *i, t_arg *data)
{
	char	*tmp;
	char	*tmp1;
	int		j;

	tmp = ft_strnew(1);
	tmp1 = ft_strnew(1);
	j = 0;
	while (j < 2)
	{
		if (s[j] == 'h' || s[j] == 'l' || s[j] == 'j' || s[j] == 'z')
		{
			tmp1 = ft_update(tmp1, ft_makestr(s[j]));
			tmp = ft_update(tmp, ft_strjoin(tmp, tmp1));
			(*i)++;
		}
		j++;
	}
	data->format = ft_update(data->format, ft_strjoin(data->format, tmp));
	ft_strdel(&tmp);
	ft_strdel(&tmp1);
}

void	parse_type(const char *s, int *i, t_arg *data)
{
	if (s[*i] == 's')
		data->type = 's';
	if (s[*i] == 'S')
		data->type = 'S';
	if (s[*i] == 'p')
		data->type = 'p';
	if (s[*i] == 'd')
		data->type = 'd';
	if (s[*i] == 'D')
		data->type = 'D';
	if (s[*i] == 'i')
		data->type = 'i';
	if (s[*i] == 'o')
		data->type = 'o';
	if (s[*i] == 'O')
		data->type = 'O';
	if (s[*i] == 'u')
		data->type = 'u';
	if (s[*i] == 'U')
		data->type = 'U';
	if (s[*i] == 'x')
		data->type = 'x';
	if (s[*i] == 'X')
		data->type = 'X';
	if (s[*i] == 'c')
		data->type = 'c';
	if (s[*i] == 'C')
		data->type = 'C';
	if (s[*i] == '%')
		data->type = '%';
	(*i)++;
}

void	if_unusial(va_list arg, const char *s, int *i, t_arg *data)
{
	makezero(data);
	parse_data(s, &*i, data);
	parse_width(arg, s, &*i, data);
	parse_accuracy(arg, s, &*i, data);
	parse_format(&s[*i], &*i, data);
	parse_type(s, &*i, data);
	if (data->right_pending == 1)
		data->zero_pending = 0;
}

void	data_use(va_list arg, t_arg *data)
{
	char	*res;

	res = type_define(arg, data);
	g_word = ft_update(g_word, ft_strjoin(g_word, res));
	free(res);
}

void	after_percentage_checker(va_list arg, const char *s, int *i)
{
	t_arg	*data;

	data = (t_arg*)malloc(sizeof(t_arg));
	if_unusial(arg, s, &*i, data);
	data_use(arg, data);
	// printf("\n--debugging--\nhashtag:\t%i\nright_pending:\t%i\nstar_precision:\t%i\nstar_width:\t%i\nplus:\t\t%i\nzero_pending:\t%i\nspace:\t\t%i\nwidth:\t\t%i\nprecision:\t%i\nformat:\t\t%s\ntype:\t\t%c\n--debugging--\n", data->hashtag, data->right_pending, data->star_precision, data->star_width, data->plus, data->zero_pending, data->space, data->width, data->precision, data->format, data->type);
	free(data->format);
	free(data);
}

void	because_str(const char *s, int i)
{
	char	*str;

	str = ft_makestr(s[i]);
	g_word = ft_update(g_word, ft_strjoin(g_word, str));
	free(str);
}

void	start_printf(va_list arg, const char *s)
{
	int		i;

	i = 0;
	g_word = ft_strnew(1);
	while (s[i] != '\0')
	{
		while (s[i] != '%' && s[i] != '\0')
		{
			because_str(s, i);
			i++;
		}
		if (s[i] == '%' && s[i] != '\0')
		{
			if (s[i + 1] != '\0')
				i++;
			after_percentage_checker(arg, s, &i);
		}
	}
}

int		ft_printf(const char *restrict format, ...)
{
	int		number_of_char;
	va_list	arg;

	va_start(arg, format);
	start_printf(arg, format);
	number_of_char = ft_strlen(g_word);
	// ft_putstr("\n-----\nThis is output: ");
	write(1, g_word, number_of_char);
	va_end(arg);
	ft_strdel(&g_word);
	// printf("number_of_char: %d\n", number_of_char - 1);
	return (number_of_char);
}
