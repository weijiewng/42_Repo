/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:09:36 by wewang            #+#    #+#             */
/*   Updated: 2022/12/30 13:27:44 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_list **list_a)
{
	t_list	*tmp;
	t_list	*new;

	if (list_a == NULL || *list_a == NULL || (*list_a)->next == NULL)
		return ;
	tmp = ft_listlast(*list_a);
	new = ft_listnew(tmp->number, tmp->index);
	ft_listadd_front(list_a, new);
	ft_listremove_back(*list_a);
	ft_printf("rra\n");
}

void	rrb(t_list **list_b)
{
	t_list	*tmp;
	t_list	*new;

	if (list_b == NULL || *list_b == NULL || (*list_b)->next == NULL)
		return ;
	tmp = ft_listlast(*list_b);
	new = ft_listnew(tmp->number, tmp->index);
	ft_listadd_front(list_b, new);
	ft_listremove_back(*list_b);
	ft_printf("rrb\n");
}

void	rrr(t_list **list_a, t_list **list_b)
{
	rra(list_a);
	rrb(list_b);
	ft_printf("rrr\n");
}
