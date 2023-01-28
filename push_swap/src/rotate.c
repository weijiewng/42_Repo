/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:05:06 by wewang            #+#    #+#             */
/*   Updated: 2022/12/30 13:27:45 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_list **list_a)
{
	t_list	*new;

	if (list_a == NULL || *list_a == NULL || (*list_a)->next == NULL)
		return ;
	new = ft_listnew((*list_a)->number, (*list_a)->index);
	ft_listadd_back(list_a, new);
	ft_listremove_front(list_a);
	ft_printf("ra\n");
}

void	rb(t_list **list_b)
{
	t_list	*new;

	if (list_b == NULL || *list_b == NULL || (*list_b)->next == NULL)
		return ;
	new = ft_listnew((*list_b)->number, (*list_b)->index);
	ft_listadd_back(list_b, new);
	ft_listremove_front(list_b);
	ft_printf("rb\n");
}

void	rr(t_list **list_a, t_list **list_b)
{
	ra(list_a);
	rb(list_b);
	ft_printf("rr\n");
}
