/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:05:09 by wewang            #+#    #+#             */
/*   Updated: 2022/10/13 16:16:18 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*cstr;

	cstr = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (cstr[i] == (unsigned char)c)
			return ((unsigned char *)&cstr[i]);
		i++;
	}
	return (NULL);
}
