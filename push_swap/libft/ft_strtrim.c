/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:03:56 by wewang            #+#    #+#             */
/*   Updated: 2022/10/10 10:50:58 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char const *set, char const c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	s1_size;
	size_t	start;

	if (!s1)
		return (NULL);
	s1_size = ft_strlen(s1);
	start = 0;
	while (start < s1_size && ft_is_set(set, s1[start]) == 1)
		start++;
	s1_size--;
	while (s1_size > start && ft_is_set(set, s1[s1_size]) == 1)
		s1_size--;
	res = (char *)malloc(sizeof(char) * (++s1_size - start + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (start + i < s1_size && s1[start + i])
	{
		res[i] = s1[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
