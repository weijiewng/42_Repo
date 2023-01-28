/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:31:29 by wewang            #+#    #+#             */
/*   Updated: 2023/01/04 14:56:26 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_word(char const *s, char c)
{
	char	*word;
	int		i;
	int		length;

	length = 0;
	while (s[length] && s[length] != c)
		length++;
	word = (char *)malloc(sizeof(char) * (length + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	ft_get_split_length(char const *s, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			size++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * ((ft_get_split_length(s, c) + 1)));
	if (res == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			res[j] = ft_get_word(&s[i], c);
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	res[j] = NULL;
	return (res);
}
