/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:25:43 by wewang            #+#    #+#             */
/*   Updated: 2022/10/17 16:35:13 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
		{
			if (lst->content != NULL)
				(*f)(lst->content);
			lst = lst->next;
		}
		if (lst->content != NULL)
			(*f)(lst->content);
	}
}
