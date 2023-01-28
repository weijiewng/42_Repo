/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:28:44 by wewang            #+#    #+#             */
/*   Updated: 2022/10/10 17:05:23 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, void const *str2, size_t count)
{
	size_t			i;
	unsigned char	*cstr1;
	unsigned char	*cstr2;

	if (str1 == NULL && str2 == NULL)
		return (str1);
	cstr1 = (unsigned char *)str1;
	cstr2 = (unsigned char *)str2;
	if (cstr2 < cstr1)
	{
		while (count--)
			cstr1[count] = cstr2[count];
	}
	else
	{
		i = 0;
		while (i < count)
		{
			cstr1[i] = cstr2[i];
			i++;
		}
	}
	return (cstr1);
}
