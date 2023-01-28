/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:35:16 by wewang            #+#    #+#             */
/*   Updated: 2022/12/30 13:27:41 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_list **list_a, t_list **list_b)
{
	t_list	*new;

	if (list_b == NULL || *list_b == NULL)
		return ;
	new = ft_listnew((*list_b)->number, (*list_b)->index);
	if (new == NULL)
		return ;
	ft_listadd_front(list_a, new);
	ft_listremove_front(list_b);
	ft_printf("pa\n");
}

void	pb(t_list **list_a, t_list **list_b)
{
	t_list	*new;

	if (list_a == NULL || *list_a == NULL)
		return ;
	new = ft_listnew((*list_a)->number, (*list_a)->index);
	if (new == NULL)
		return ;
	ft_listadd_front(list_b, new);
	ft_listremove_front(list_a);
	ft_printf("pb\n");
}
