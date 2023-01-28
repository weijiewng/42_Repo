/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:09:38 by wewang            #+#    #+#             */
/*   Updated: 2022/10/10 17:05:07 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void const *str1, void const *str2, size_t n)
{
	size_t			i;
	unsigned char	*cstr1;
	unsigned char	*cstr2;

	cstr1 = (unsigned char *)str1;
	cstr2 = (unsigned char *)str2;
	i = 0;
	while (i < n && cstr1[i] == cstr2[i])
		i++;
	if (i == n)
		i--;
	return (cstr1[i] - cstr2[i]);
}
