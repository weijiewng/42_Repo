/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:37:53 by wewang            #+#    #+#             */
/*   Updated: 2022/10/20 09:34:49 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char const *s)
{
	int		i;
	char	*res;

	i = 0;
	while (s[i])
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

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

int	ft_find_nl(char *str)
{
	ssize_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
