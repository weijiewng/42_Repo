/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:24:14 by wewang            #+#    #+#             */
/*   Updated: 2022/12/30 13:27:49 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list *list_a)
{
	if (list_a == NULL || list_a->next == NULL)
		return ;
	ft_swap(&(list_a->number), &(list_a->next->number));
	ft_swap(&(list_a->index), &(list_a->next->index));
	ft_printf("sa\n");
}

void	sb(t_list *list_b)
{
	if (list_b == NULL || list_b->next == NULL)
		return ;
	ft_swap(&(list_b->number), &(list_b->next->number));
	ft_swap(&(list_b->index), &(list_b->next->index));
	ft_printf("sb\n");
}

void	ss(t_list *list_a, t_list *list_b)
{
	sb(list_a);
	sb(list_b);
	ft_printf("ss\n");
}
