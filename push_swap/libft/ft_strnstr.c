/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:12:31 by wewang            #+#    #+#             */
/*   Updated: 2022/10/13 13:54:48 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *big, char const *little, size_t len)
{
	size_t	b_c;
	size_t	l_c;
	size_t	l_s;

	b_c = 0;
	l_s = ft_strlen(little);
	if (l_s == 0)
		return ((char *)&*big);
	if (!big && len == 0)
		return (NULL);
	while (big[b_c] && b_c < len)
	{
		l_c = 0;
		while (big[b_c + l_c] && (b_c + l_c) < len && l_c < l_s)
		{
			if (big[b_c + l_c] != little[l_c])
				break ;
			l_c++;
		}
		if (l_c == l_s)
			return ((char *)&big[b_c]);
		b_c++;
	}
	return (NULL);
}
