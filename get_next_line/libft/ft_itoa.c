/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 12:58:44 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/11 17:54:44 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

static char		*itoa_filler(char *tab, int value, int flag)
{
	int			tmp;
	int			size;
	char		*str;

	size = 0;
	tmp = ft_abs(value);
	while (tmp /= 10)
		size++;
	size = size + flag + 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = tab[ft_abs(value % 10)];
		size--;
		value = value / 10;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char		*str;
	char		*tab;
	int			flag;

	flag = 0;
	tab = "0123456789abcdef";
	if (n < 0)
		flag = 1;
	str = itoa_filler(tab, n, flag);
	return (str);
}
