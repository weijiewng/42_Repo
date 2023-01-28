/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:08:24 by wewang            #+#    #+#             */
/*   Updated: 2022/10/13 13:35:41 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_length(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	long	l;

	i = ft_get_length(n);
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return (NULL);
	res[i--] = '\0';
	l = n;
	if (l < 0)
		res[0] = '-';
	if (l < 0)
		l = l * -1;
	if (l != 0)
	{
		while (l)
		{
			res[i--] = (l % 10) + '0';
			l = l / 10;
		}
	}
	else
		res[0] = '0';
	return (res);
}
