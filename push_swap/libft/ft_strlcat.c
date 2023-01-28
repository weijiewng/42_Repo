/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:30:32 by wewang            #+#    #+#             */
/*   Updated: 2022/10/10 10:08:27 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	dest_counter;
	size_t	src_counter;
	size_t	dest_length;
	size_t	src_length;

	if (!dest && size == 0)
		return (0);
	dest_counter = 0;
	src_counter = 0;
	while (dest[dest_counter])
		dest_counter++;
	dest_length = dest_counter;
	src_length = ft_strlen(src);
	if (size == 0 || size <= dest_length)
		return (src_length + size);
	while (src[src_counter] != '\0' && src_counter < (size - dest_length - 1))
	{
		dest[dest_counter] = src[src_counter];
		dest_counter++;
		src_counter++;
	}
	dest[dest_counter] = '\0';
	return (dest_length + src_length);
}
