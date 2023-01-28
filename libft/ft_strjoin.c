/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:58:19 by wewang            #+#    #+#             */
/*   Updated: 2022/10/10 17:12:39 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	s1_l;
	size_t	s2_l;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (s1_l + s2_l + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < s1_l)
	{
		res[i] = s1[i];
		i++;
	}
	while (i < s1_l + s2_l)
	{
		res[i] = s2[i - s1_l];
		i++;
	}
	res[i] = '\0';
	return (res);
}
