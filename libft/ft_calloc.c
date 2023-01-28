/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:30:24 by wewang            #+#    #+#             */
/*   Updated: 2022/10/10 17:11:36 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*res;

	res = (void *)malloc(sizeof(void) * nmemb * size);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}
